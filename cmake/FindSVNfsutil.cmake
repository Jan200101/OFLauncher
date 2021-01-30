#
# SVNFSUTIL_INCLUDE_DIRS
# SVNFSUTIL_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_SVNFSUTIL QUIET libsvn_fs_util)
endif()

find_path(SVNFSUTIL_INC
    NAMES svn_client.h
    HINTS
        ${_SVNFSUTIL_INCLUDE_DIRS}
    PATHS
        /usr/include/subversion-1 /usr/local/include/subversion-1)

find_library(SVNFSUTIL_LIB
    NAMES ${_SVNFSUTIL_LIBRARIES} svn_fs_util-1
    HINTS
        ${_SVNFSUTIL_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SVNfsutil DEFAULT_MSG SVNFSUTIL_LIB SVNFSUTIL_INC)
mark_as_advanced(SVNFSUTIL_INC SVNFSUTIL_LIB)

if(SVNFSUTIL_FOUND)
    set(SVNFSUTIL_INCLUDE_DIRS ${SVNFSUTIL_INC})
    set(SVNFSUTIL_LIBRARIES ${SVNFSUTIL_LIB})
endif()