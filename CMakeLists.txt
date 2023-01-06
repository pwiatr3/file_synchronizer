cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(FilesSynchornizer)

set(SRC_LIST
    main.cpp
    fileInfo.cpp
    fileContainer.cpp
    fileSynchronization.cpp
    folder.cpp
)

add_compile_definitions(RELEASE) # adds compile definition

add_executable(${PROJECT_NAME} ${SRC_LIST})
# target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})