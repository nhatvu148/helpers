const fs = require("fs");
const os = require("os");
const SoftwareLicenseKey = require("software-license-key");
const util = require("util");
const childProcess = require("child_process");
const exec = util.promisify(childProcess.exec);

const args = process.argv.slice(2);

const publicKeyFile = fs.readFileSync(
  `${process.cwd()}/config/public_key.pub`,
  "utf-8"
);

const getMAC = async () => {
  const result = await exec("cd scripts && lmutil.exe lmhostid -ether");

  const stdout = result.stdout;
  const macArr = stdout.match(/"([^"]+)"/)[1];

  return macArr.split(" ")[0];
};

const checkLicense = async (dataPath) => {
  try {
    const hostname = os.hostname().toLowerCase();
    const MAC = (await getMAC()).toLowerCase();
    const validator = new SoftwareLicenseKey(publicKeyFile);
    const licenseKey = fs.readFileSync(
      `${dataPath}/license/license.key`,
      "utf8"
    );

    const decryptedLicenseKeydata = validator.validateLicense(licenseKey);
    const date = new Date();
    const toDate = new Date(decryptedLicenseKeydata.expire);

    if (MAC !== decryptedLicenseKeydata.MAC) {
      throw new Error("-3");
    }

    if (hostname !== decryptedLicenseKeydata.hostname) {
      throw new Error("-4");
    }

    if (toDate.getTime() - date.getTime() <= 0) {
      throw new Error("0");
    }

    return 1;
  } catch (err) {
    if (err.message === "0") {
      return 0;
    } else if (err.code === "ENOENT") {
      return -1;
    } else if (err.message === "-3") {
      return -3;
    } else if (err.message === "-4") {
      return -4;
    }
    return -2;
  }
};

(async () => {
  console.log(await checkLicense(args[0]));
})();
