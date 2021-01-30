#
# SVNWC_INCLUDE_DIRS
# SVNWC_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_SVNWC QUIET libsvn_wc)
endif()

find_path(SVNWC_INC
    NAMES svn_client.h
    HINTS
        ${_SVNWC_INCLUDE_DIRS}
    PATHS
        /usr/include/subversion-1 /usr/local/include/subversion-1)

find_library(SVNWC_LIB
    NAMES ${_SVNWC_LIBRARIES} svn_wc-1
    HINTS
        ${_SVNWC_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SVNwc DEFAULT_MSG SVNWC_LIB SVNWC_INC)
mark_as_advanced(SVNWC_INC SVNWC_LIB)

if(SVNWC_FOUND)
    set(SVNWC_INCLUDE_DIRS ${SVNWC_INC})
    set(SVNWC_LIBRARIES ${SVNWC_LIB})
endif()