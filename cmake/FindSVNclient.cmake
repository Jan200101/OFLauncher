#
# SVNCLIENT_INCLUDE_DIRS
# SVNCLIENT_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_SVNCLIENT QUIET libsvn_client)
endif()

find_path(SVNCLIENT_INC
    NAMES svn_client.h
    HINTS
        ${_SVNCLIENT_INCLUDE_DIRS}
    PATHS
        /usr/include/subversion-1 /usr/local/include/subversion-1)

find_library(SVNCLIENT_LIB
    NAMES ${_SVNCLIENT_LIBRARIES} svn_client-1
    HINTS
        ${_SVNCLIENT_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SVNclient DEFAULT_MSG SVNCLIENT_LIB SVNCLIENT_INC)
mark_as_advanced(SVNCLIENT_INC SVNCLIENT_LIB)

if(SVNCLIENT_FOUND)
    set(SVNCLIENT_INCLUDE_DIRS ${SVNCLIENT_INC})
    set(SVNCLIENT_LIBRARIES ${SVNCLIENT_LIB})
endif()