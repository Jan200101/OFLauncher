#
# EXPAT_INCLUDE_DIRS
# EXPAT_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_EXPAT QUIET expat)
endif()

find_path(EXPAT_INC
    NAMES expat.h
    HINTS
        ${_EXPAT_INCLUDE_DIRS}
    PATHS
        /usr/include/ /usr/local/include/)

find_library(EXPAT_LIB
    NAMES ${_EXPAT_LIBRARIES} expat
    HINTS
        ${_EXPAT_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Expat DEFAULT_MSG EXPAT_LIB EXPAT_INC)
mark_as_advanced(EXPAT_INC EXPAT_LIB)

if(EXPAT_FOUND)
    set(EXPAT_INCLUDE_DIRS ${EXPAT_INC})
    set(EXPAT_LIBRARIES ${EXPAT_LIB})
endif()