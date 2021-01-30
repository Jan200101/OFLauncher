#
# SVNRASERF_INCLUDE_DIRS
# SVNRASERF_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_SVNRASERF QUIET libsvn_ra_serf)
endif()

find_path(SVNRASERF_INC
    NAMES svn_client.h
    HINTS
        ${_SVNRASERF_INCLUDE_DIRS}
    PATHS
        /usr/include/subversion-1 /usr/local/include/subversion-1)

find_library(SVNRASERF_LIB
    NAMES ${_SVNRASERF_LIBRARIES} svn_ra_serf-1
    HINTS
        ${_SVNRASERF_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SVNraserf DEFAULT_MSG SVNRASERF_LIB SVNRASERF_INC)
mark_as_advanced(SVNRASERF_INC SVNRASERF_LIB)

if(SVNRASERF_FOUND)
    set(SVNRASERF_INCLUDE_DIRS ${SVNRASERF_INC})
    set(SVNRASERF_LIBRARIES ${SVNRASERF_LIB})
endif()