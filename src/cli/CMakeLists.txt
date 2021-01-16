SET(NAME ${CMAKE_PROJECT_NAME})

SET(CLI_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/main.c
    ${CMAKE_CURRENT_LIST_DIR}/command.h
)

add_executable(${NAME} ${CLI_SOURCES})
target_link_libraries(${NAME} PRIVATE core)