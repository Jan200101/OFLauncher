#
# SVNRALOCAL_INCLUDE_DIRS
# SVNRALOCAL_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_SVNRALOCAL QUIET libsvn_ra_local)
endif()

find_path(SVNRALOCAL_INC
    NAMES svn_fs.h
    HINTS
        ${_SVNRALOCAL_INCLUDE_DIRS}
    PATHS
        /usr/include/subversion-1 /usr/local/include/subversion-1)

find_library(SVNRALOCAL_LIB
    NAMES ${_SVNRALOCAL_LIBRARIES} svn_ra_local-1
    HINTS
        ${_SVNRALOCAL_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SVNralocal DEFAULT_MSG SVNRALOCAL_LIB SVNRALOCAL_INC)
mark_as_advanced(SVNRALOCAL_INC SVNRALOCAL_LIB)

if(SVNRALOCAL_FOUND)
    set(SVNRALOCAL_INCLUDE_DIRS ${SVNRALOCAL_INC})
    set(SVNRALOCAL_LIBRARIES ${SVNRALOCAL_LIB})
endif()