#
# SVNDIFF_INCLUDE_DIRS
# SVNDIFF_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_SVNDIFF QUIET libsvn_diff)
endif()

find_path(SVNDIFF_INC
    NAMES svn_fs.h
    HINTS
        ${_SVNDIFF_INCLUDE_DIRS}
    PATHS
        /usr/include/subversion-1 /usr/local/include/subversion-1)

find_library(SVNDIFF_LIB
    NAMES ${_SVNDIFF_LIBRARIES} svn_diff-1
    HINTS
        ${_SVNDIFF_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SVNdiff DEFAULT_MSG SVNDIFF_LIB SVNDIFF_INC)
mark_as_advanced(SVNDIFF_INC SVNDIFF_LIB)

if(SVNDIFF_FOUND)
    set(SVNDIFF_INCLUDE_DIRS ${SVNDIFF_INC})
    set(SVNDIFF_LIBRARIES ${SVNDIFF_LIB})
endif()