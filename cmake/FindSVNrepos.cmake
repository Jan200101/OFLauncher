#
# SVNREPOS_INCLUDE_DIRS
# SVNREPOS_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_SVNREPOS QUIET libsvn_repos)
endif()

find_path(SVNREPOS_INC
    NAMES svn_client.h
    HINTS
        ${_SVNREPOS_INCLUDE_DIRS}
    PATHS
        /usr/include/subversion-1 /usr/local/include/subversion-1)

find_library(SVNREPOS_LIB
    NAMES ${_SVNREPOS_LIBRARIES} svn_repos-1
    HINTS
        ${_SVNREPOS_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SVNrepos DEFAULT_MSG SVNREPOS_LIB SVNREPOS_INC)
mark_as_advanced(SVNREPOS_INC SVNREPOS_LIB)

if(SVNREPOS_FOUND)
    set(SVNREPOS_INCLUDE_DIRS ${SVNREPOS_INC})
    set(SVNREPOS_LIBRARIES ${SVNREPOS_LIB})
endif()