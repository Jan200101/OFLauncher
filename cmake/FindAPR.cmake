#
# SVNCLIENT_INCLUDE_DIRS
# SVNCLIENT_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_APR QUIET apr-1)
endif()

find_path(APR_INC
    NAMES apr.h
    HINTS
        ${_APR_INCLUDE_DIRS}
    PATHS
        /usr/include/apr-1 /usr/local/include/apr-1)

find_library(APR_LIB
    NAMES ${_APR_LIBRARIES} apr-1
    HINTS
        ${_APR_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(APR DEFAULT_MSG APR_LIB APR_INC)
mark_as_advanced(APR_INC APR_LIB)

if(APR_FOUND)
    set(APR_INCLUDE_DIRS ${APR_INC})
    set(APR_LIBRARIES ${APR_LIB})
endif()