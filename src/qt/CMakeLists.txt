set(NAME ${CMAKE_PROJECT_NAME}_qt)

enable_language(CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Gui REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Gui REQUIRED)

SET(QT_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mainwindow.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mainwindow.hpp
    ${CMAKE_CURRENT_LIST_DIR}/mainwindow.ui
    ${CMAKE_CURRENT_LIST_DIR}/settings.cpp
    ${CMAKE_CURRENT_LIST_DIR}/settings.cpp
    ${CMAKE_CURRENT_LIST_DIR}/settings.hpp
    ${CMAKE_CURRENT_LIST_DIR}/settings.ui
    ${CMAKE_CURRENT_LIST_DIR}/workers.cpp
    ${CMAKE_CURRENT_LIST_DIR}/workers.hpp
    ${CMAKE_CURRENT_LIST_DIR}/images.qrc
)

add_executable(${NAME} ${QT_SOURCES})
target_link_libraries(${NAME} PRIVATE core Qt${QT_VERSION_MAJOR}::Widgets)
set_property(TARGET ${NAME} PROPERTY CXX_STANDARD 11)