{
    "targets": [{
        # "target_name": "NodeTest",
        "target_name": "NanTest",
        "sources": [
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