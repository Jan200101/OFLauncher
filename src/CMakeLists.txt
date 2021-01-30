set(C_STANDARD 99)

set(CORE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/common.c
    ${CMAKE_CURRENT_SOURCE_DIR}/common.h
    ${CMAKE_CURRENT_SOURCE_DIR}/config.c
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h
    ${CMAKE_CURRENT_SOURCE_DIR}/steam.c
    ${CMAKE_CURRENT_SOURCE_DIR}/steam.h
    ${CMAKE_CURRENT_SOURCE_DIR}/svn.c
    ${CMAKE_CURRENT_SOURCE_DIR}/svn.h
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(SVN REQUIRED)
find_package(APR REQUIRED)
find_package(APRutil REQUIRED)

set(APR_INCLUDES ${APR_INCLUDE_DIRS})
set(APR_LIBS ${APR_LIBRARIES} ${APRUTIL_LIBRARIES})

if (WIN32)
    set(WIN_LIBS version ws2_32 rpcrt4 mswsock)
    if (MXE)
        find_package(SQLite REQUIRED)
        find_package(Expat REQUIRED)
        find_package(Iconv REQUIRED)
        set(WIN_LIBS ${WIN_LIBS} z ${SQLITE_LIBRARIES} ${EXPAT_LIBRARIES} ${ICONV_LIBRARIES})
    endif()
endif()

add_library(core STATIC ${CORE_SOURCES})
target_include_directories(core PUBLIC ${APR_INCLUDES} ${SVN_INCLUDES})
target_link_libraries(core LINK_PUBLIC ${SVN_LIBRARIES} ${APRUTIL_LIBRARIES} ${APR_LIBRARIES} ${WIN_LIBS})

foreach(VER ${VERSIONS})
    if(COMPILE_${VER})
        string(TOLOWER ${VER} VER_LOWER)
        add_subdirectory(${VER_LOWER})
    endif()
endforeach()
