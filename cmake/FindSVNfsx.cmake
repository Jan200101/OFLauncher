#
# SVNFSX_INCLUDE_DIRS
# SVNFSX_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_SVNFSX QUIET libsvn_fs_x)
endif()

find_path(SVNFSX_INC
    NAMES svn_client.h
    HINTS
        ${_SVNFSX_INCLUDE_DIRS}
    PATHS
        /usr/include/subversion-1 /usr/local/include/subversion-1)

find_library(SVNFSX_LIB
    NAMES ${_SVNFSX_LIBRARIES} svn_fs_x-1
    HINTS
        ${_SVNFSX_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SVNfsx DEFAULT_MSG SVNFSX_LIB SVNFSX_INC)
mark_as_advanced(SVNFSX_INC SVNFSX_LIB)

if(SVNFSX_FOUND)
    set(SVNFSX_INCLUDE_DIRS ${SVNFSX_INC})
    set(SVNFSX_LIBRARIES ${SVNFSX_LIB})
endif()