#
# SVNRASVN_INCLUDE_DIRS
# SVNRASVN_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_SVNRASVN QUIET libsvn_ra_svn)
endif()

find_path(SVNRASVN_INC
    NAMES svn_client.h
    HINTS
        ${_SVNRASVN_INCLUDE_DIRS}
    PATHS
        /usr/include/subversion-1 /usr/local/include/subversion-1)

find_library(SVNRASVN_LIB
    NAMES ${_SVNRASVN_LIBRARIES} svn_ra_svn-1
    HINTS
        ${_SVNRASVN_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SVNrasvn DEFAULT_MSG SVNRASVN_LIB SVNRASVN_INC)
mark_as_advanced(SVNRASVN_INC SVNRASVN_LIB)

if(SVNRASVN_FOUND)
    set(SVNRASVN_INCLUDE_DIRS ${SVNRASVN_INC})
    set(SVNRASVN_LIBRARIES ${SVNRASVN_LIB})
endif()