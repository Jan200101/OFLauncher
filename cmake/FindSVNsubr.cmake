#
# SVNSUBR_INCLUDE_DIRS
# SVNSUBR_LIBRARIES

find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(_SVNSUBR QUIET libsvn_subr)
endif()

find_library(SVNSUBR_LIB
    NAMES ${_SVNSUBR_LIBRARIES} svn_subr-1
    HINTS
        ${_SVNSUBR_LIBRARY_DIRS}
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SVNsubr DEFAULT_MSG SVNSUBR_LIB)
mark_as_advanced(SVNSUBR_INC SVNSUBR_LIB)

if(SVNSUBR_FOUND)
    set(SVNSUBR_LIBRARIES ${SVNSUBR_LIB})
endif()