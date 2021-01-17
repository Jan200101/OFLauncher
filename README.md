# OFLauncher
OFLaunch is a Launcher for the Team Fortress sourcemod [Open Fortress](https://openfortress.fun/) designed to be simple at its core.

## Installation
OFLauncher is currently in no state to be installed but when the time comes there will be stable windows releases

## Building
OFLauncher has 2 frontends: cli and qt
cli depends on nothing but standard C
qt depends on at least Qt5

to build simply invoke cmake and build the output

## Structure
all source files directly present in src/ are core files written in C that will act independent of frontend
folders in src/ represent a frontend (e.g. cli, qt)

## License
This project is licensed under [GPLv3](LICENSE) to be compatible with the Qt license ([LGPL](https://www.gnu.org/licenses/lgpl-3.0.en.html)) and the SVN license ([Apache2](https://www.apache.org/licenses/LICENSE-2.0.html))
