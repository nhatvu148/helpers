{
    "targets": [{
        "target_name": "addon",
        "sources": [
            "src/main.cpp",
            # "src/MyObject.cpp",
            # "src/FactoryWrap.cpp",
            "src/PassWrap.cpp",
        ],
        "include_dirs": [
        "<!(node -e \"require('nan')\")"
        ]
    }]
}