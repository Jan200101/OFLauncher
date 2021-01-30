#
# SVNCLIENT_INCLUDE_DIRS
# SVNCLIENT_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_APRUTIL QUIET apr-util-1)
endif()

find_library(APRUTIL_LIB
    NAMES ${_APRUTIL_LIBRARIES} aprutil-1
    HINTS
        ${_APRUTIL_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(APRutil DEFAULT_MSG APRUTIL_LIB)
mark_as_advanced(APRUTIL_LIB)

if(APRUTIL_FOUND)
    set(APRUTIL_LIBRARIES ${APRUTIL_LIB})
endif()