{
    'targets': [
        {
            'target_name': 'unlocker',
            'include_dirs': [
                "<!@(node -p \"require('node-addon-api').include\")",
                "./juce/modules/"
            ],
            'dependencies': [
                "<!(node -p \"require('node-addon-api').gyp\")"
            ],
            "defines": [
                "JUCE_DISPLAY_SPLASH_SCREEN=1",
                "JUCE_USE_DARK_SPLASH_SCREEN=1",
                "JUCE_PROJUCER_VERSION=0x60008",
                "JUCE_MODULE_AVAILABLE_juce_core=1",
                "JUCE_MODULE_AVAILABLE_juce_cryptography=1",
                "JUCE_MODULE_AVAILABLE_juce_data_structures=1",
                "JUCE_MODULE_AVAILABLE_juce_events=1",
                "JUCE_MODULE_AVAILABLE_juce_product_unlocking=1",
                "JUCE_GLOBAL_MODULE_SETTINGS_INCLUDED=1",
                "JUCE_STRICT_REFCOUNTEDPOINTER=1",
                "JUCE_STANDALONE_APPLICATION=0",
                "JUCER_LINUX_MAKE_6D53C8B4=1",
                "JUCE_APP_VERSION=1.0.0",
                "JUCE_APP_VERSION_HEX=0x10000",
                "JucePlugin_Build_VST=0",
                "JucePlugin_Build_VST3=0",
                "JucePlugin_Build_AU=0",
                "JucePlugin_Build_AUv3=0",
                "JucePlugin_Build_RTAS=0",
                "JucePlugin_Build_AAX=0",
                "JucePlugin_Build_Standalone=0",
                "JucePlugin_Build_Unity=0",
                "NDEBUG",
            ],
            'cflags!': ['-fno-exceptions'],
            'cflags_cc!': [
                '-fno-exceptions',
                "-fno-rtti",
                "-pthread",
            ],
            'xcode_settings': {
                'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
                'CLANG_CXX_LIBRARY': 'libc++',
                'MACOSX_DEPLOYMENT_TARGET': '10.7',
                'GCC_ENABLE_CPP_RTTI': 'YES'
            },
            'msvs_settings': {
                'VCCLCompilerTool': {'ExceptionHandling': 1},
            },
            'conditions': [
                ['OS=="mac"', {
                    "sources": [
                        'src/main.mm',
                        'juce/JuceLibraryCode/include_juce_core.mm',
                        'juce/JuceLibraryCode/include_juce_cryptography.mm',
                        'juce/JuceLibraryCode/include_juce_data_structures.mm',
                        'juce/JuceLibraryCode/include_juce_events.mm',
                        'juce/JuceLibraryCode/include_juce_product_unlocking.mm',
                    ],
                }],
                ['OS!="mac"', {
                    "sources": [
                        'src/main.cc',
                        'juce/JuceLibraryCode/include_juce_core.cpp',
                        'juce/JuceLibraryCode/include_juce_cryptography.cpp',
                        'juce/JuceLibraryCode/include_juce_data_structures.cpp',
                        'juce/JuceLibraryCode/include_juce_events.cpp',
                        'juce/JuceLibraryCode/include_juce_product_unlocking.cpp',
                    ],
                }],
                ['OS=="linux"', {
                    "include_dirs": [
                        "<!(pkg-config --cflags alsa libcurl)"
                    ],
                    'libraries': [
                        "<!(pkg-config --libs alsa libcurl)"
                    ],
                }],
                ['OS=="win"', {
                    'configurations': {
                        'Debug': {
                            'msvs_settings': {
                                'VCCLCompilerTool': {
                                    'RuntimeTypeInfo': 'true',
                                },
                            }
                        },  # Debug
                        'Release': {
                            'msvs_settings': {
                                'VCCLCompilerTool': {
                                    'RuntimeTypeInfo': 'true',
                                },
                            },
                        },  # Release
                    },  # configurations
                }],  # OS=="win"
            ]
        }
    ]
}
