#
# SVNFSFS_INCLUDE_DIRS
# SVNFSFS_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_SVNFSFS QUIET libsvn_fs_fs)
endif()

find_path(SVNFSFS_INC
    NAMES svn_client.h
    HINTS
        ${_SVNFSFS_INCLUDE_DIRS}
    PATHS
        /usr/include/subversion-1 /usr/local/include/subversion-1)

find_library(SVNFSFS_LIB
    NAMES ${_SVNFSFS_LIBRARIES} svn_fs_fs-1
    HINTS
        ${_SVNFSFS_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SVNfsfs DEFAULT_MSG SVNFSFS_LIB SVNFSFS_INC)
mark_as_advanced(SVNFSFS_INC SVNFSFS_LIB)

if(SVNFSFS_FOUND)
    set(SVNFSFS_INCLUDE_DIRS ${SVNFSFS_INC})
    set(SVNFSFS_LIBRARIES ${SVNFSFS_LIB})
endif()