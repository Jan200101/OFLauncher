set(NAME ${CMAKE_PROJECT_NAME}_qt)

enable_language(CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Gui REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Gui REQUIRED)

SET(QT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/settings.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/settings.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/settings.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/settings.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/workers.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/workers.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/images.qrc
)

if(WIN32)
    string(REPLACE "." "," CMAKE_PROJECT_COMMAVERSION ${CMAKE_PROJECT_VERSION})
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/version.rc.in ${CMAKE_CURRENT_BINARY_DIR}/version.rc @ONLY)
    set(QT_SOURCES ${QT_SOURCES} ${CMAKE_CURRENT_BINARY_DIR}/version.rc)
endif()

add_executable(${NAME} WIN32 ${QT_SOURCES})
target_link_libraries(${NAME} PRIVATE core Qt${QT_VERSION_MAJOR}::Widgets)
set_property(TARGET ${NAME} PROPERTY CXX_STANDARD 11)
