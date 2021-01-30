#
# SVNRA_INCLUDE_DIRS
# SVNRA_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_SVNRA QUIET libsvn_ra)
endif()

find_path(SVNRA_INC
    NAMES svn_client.h
    HINTS
        ${_SVNRA_INCLUDE_DIRS}
    PATHS
        /usr/include/subversion-1 /usr/local/include/subversion-1)

find_library(SVNRA_LIB
    NAMES ${_SVNRA_LIBRARIES} svn_ra-1
    HINTS
        ${_SVNRA_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SVNra DEFAULT_MSG SVNRA_LIB SVNRA_INC)
mark_as_advanced(SVNRA_INC SVNRA_LIB)

if(SVNRA_FOUND)
    set(SVNRA_INCLUDE_DIRS ${SVNRA_INC})
    set(SVNRA_LIBRARIES ${SVNRA_LIB})
endif()