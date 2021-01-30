#
# SQLITE_INCLUDE_DIRS
# SQLITE_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_SQLITE QUIET sqlite3)
endif()

find_path(SQLITE_INC
    NAMES sqlite3.h
    HINTS
        ${_SQLITE_INCLUDE_DIRS}
    PATHS
        /usr/include/ /usr/local/include/)

find_library(SQLITE_LIB
    NAMES ${_SQLITE_LIBRARIES} sqlite3
    HINTS
        ${_SQLITE_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SQLite DEFAULT_MSG SQLITE_LIB SQLITE_INC)
mark_as_advanced(SQLITE_INC SQLITE_LIB)

if(SQLITE_FOUND)
    set(SQLITE_INCLUDE_DIRS ${SQLITE_INC})
    set(SQLITE_LIBRARIES ${SQLITE_LIB})
endif()