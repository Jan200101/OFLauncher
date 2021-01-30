#
# SVNFS_INCLUDE_DIRS
# SVNFS_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_SVNFS QUIET libsvn_fs)
endif()

find_path(SVNFS_INC
    NAMES svn_fs.h
    HINTS
        ${_SVNFS_INCLUDE_DIRS}
    PATHS
        /usr/include/subversion-1 /usr/local/include/subversion-1)

find_library(SVNFS_LIB
    NAMES ${_SVNFS_LIBRARIES} svn_fs-1
    HINTS
        ${_SVNFS_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SVNfs DEFAULT_MSG SVNFS_LIB SVNFS_INC)
mark_as_advanced(SVNFS_INC SVNFS_LIB)

if(SVNFS_FOUND)
    set(SVNFS_INCLUDE_DIRS ${SVNFS_INC})
    set(SVNFS_LIBRARIES ${SVNFS_LIB})
endif()