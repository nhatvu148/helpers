{
    "targets": [{
        "target_name": "hello",
        # "target_name": "helpers",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            # "src/main.cpp",
            # "src/Samples/functionexample.cpp",
            # "src/Samples/actualclass.cpp",
            # "src/Samples/classexample.cpp",
            # "src/Samples/mytest.cpp"
            "src/hello.cc"
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")"
        ],
        'libraries': [],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}