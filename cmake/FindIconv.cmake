#
# ICONV_INCLUDE_DIRS
# ICONV_LIBRARIES

find_path(ICONV_INC
    NAMES iconv.h
    PATHS
        /usr/include/ /usr/local/include/)

find_library(ICONV_LIB
    NAMES iconv
    PATHS
        /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Iconv DEFAULT_MSG ICONV_LIB ICONV_INC)
mark_as_advanced(ICONV_INC ICONV_LIB)

if(ICONV_FOUND)
    set(ICONV_INCLUDE_DIRS ${ICONV_INC})
    set(ICONV_LIBRARIES ${ICONV_LIB})
endif()