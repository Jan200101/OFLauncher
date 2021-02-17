# OFLauncher
OFLaunch is a Launcher for the Team Fortress sourcemod [Open Fortress](https://openfortress.fun/) designed to be simple at its core.

## Installation

### Windows
* Download either the cli or qt executable from the [releases](https://github.com/Jan200101/OFLauncher/releases)
* Install a subversion commandline client like:
    * TortoiseSVN
    * Win32SVN
    * (If the svn cli client you are using is not supported open an issue)
* Run OFLauncher

### Linux

Currently no binary releases for Linux exists
Consult [Building](#Building) on how to build OFLauncher

## Building

All building guides are rather simplistic and assume
you already know how your toolchain and build tools work.

### CMake options

Option      | Type | Default | Description
----------- | ---- | ------- | -----------
COMPILE_CLI | BOOL | ON      | If set compiles the CLI frontend
COMPILE_QT  | BOOL | ON      | If set compiles the Qt frontend

### For Linux

#### Dependencies:

* cmake
* a C compiler

For Qt
* Qt5
* a C++ compiler

```bash
cd /path/to/OFLauncher

# all frontends are enabled by default
# add COMPILE_CLI=OFF to disable CLI
# and COMPILE_QT=OFF to disable QT
cmake -B build

cmake --build build
```

### For Windows on Linux (using MXE)

``` bash
CROSS=i686-w64-mingw32.static

cd /path/to/mxe

MXE_TARGETS=${CROSS} make cc cmake
MXE_TARGETS=${CROSS} make qt5 # for the Qt5 frontend

cd /path/to/OFLauncher

${CROSS}-cmake -B build
${CROSS}-cmake --build build
```

## License
This project is licensed under [GPLv3](LICENSE) to be compatible with the Qt license ([LGPL](https://www.gnu.org/licenses/lgpl-3.0.en.html)) and the SVN license ([Apache2](https://www.apache.org/licenses/LICENSE-2.0.html))
