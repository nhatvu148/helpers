{
    "targets": [{
        # "target_name": "NodeTest",
        "target_name": "NanTest",
        # "target_name": "helpers",
        "sources": [
            # "src/main.cpp",
            # "src/Samples/functionexample.cpp",
            # "src/Samples/actualclass.cpp",
            # "src/Samples/classexample.cpp",
            # "src/Samples/mytest.cpp"
            # "src/NodeTest.cpp"
            "src/NanTest.cpp",
            # "src/MyObject.cpp",
            # "src/FactoryWrap.cpp",
            "src/PassWrap.cpp",
        ],
        "include_dirs": [
        "<!(node -e \"require('nan')\")"
        ]
    }]
}