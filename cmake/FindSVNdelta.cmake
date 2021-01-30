#
# SVNDELTA_INCLUDE_DIRS
# SVNDELTA_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_SVNDELTA QUIET libsvn_delta)
endif()

find_path(SVNDELTA_INC
    NAMES svn_client.h
    HINTS
        ${_SVNDELTA_INCLUDE_DIRS}
    PATHS
        /usr/include/subversion-1 /usr/local/include/subversion-1)

find_library(SVNDELTA_LIB
    NAMES ${_SVNDELTA_LIBRARIES} svn_delta-1
    HINTS
        ${_SVNDELTA_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SVNdelta DEFAULT_MSG SVNDELTA_LIB SVNDELTA_INC)
mark_as_advanced(SVNDELTA_INC SVNDELTA_LIB)

if(SVNDELTA_FOUND)
    set(SVNDELTA_INCLUDE_DIRS ${SVNDELTA_INC})
    set(SVNDELTA_LIBRARIES ${SVNDELTA_LIB})
endif()