cmake_minimum_required(VERSION 3.0)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING
        "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()

option(COMPILE_CLI "Compile the commandline version" ON)
option(COMPILE_QT "Compile the Qt version" OFF)

project(OFLauncher VERSION 0.1.0 LANGUAGES C)
if(COMPILE_QT)
    enable_language(CXX)
endif()

add_compile_definitions(NAME="${CMAKE_PROJECT_NAME}")
message(STATUS "Name: ${CMAKE_PROJECT_NAME}")
add_compile_definitions(VERSION="${CMAKE_PROJECT_VERSION}")
message(STATUS "Version: ${CMAKE_PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(COMPILE_OPTIONS -Wall -Wextra -Wpedantic -Wconversion)

set(COMMON_SOURCES
    src/common.c
    src/common.h
    src/config.c
    src/config.h
    src/steam.c
    src/steam.h
    src/svn.c
    src/svn.h
)

SET(CLI_SOURCES
    src/cli/main.c
    src/cli/command.h
    ${COMMON_SOURCES}
)

SET(QT_SOURCES
    src/qt/main.cpp
    src/qt/mainwindow.cpp
    src/qt/mainwindow.hpp
    src/qt/mainwindow.ui
    src/qt/images.qrc
    ${COMMON_SOURCES}
)

if(COMPILE_QT)
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)

    find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
    find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
endif()

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()

if(COMPILE_CLI)
    add_executable(${CMAKE_PROJECT_NAME} ${CLI_SOURCES})
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE ${COMPILE_OPTIONS})
    target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE src)
endif()

if(COMPILE_QT)
    add_executable(${CMAKE_PROJECT_NAME}_qt ${QT_SOURCES})
    target_compile_options(${CMAKE_PROJECT_NAME}_qt PRIVATE ${COMPILE_OPTIONS})
    target_link_libraries(${CMAKE_PROJECT_NAME}_qt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
endif()

