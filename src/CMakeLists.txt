cmake_minimum_required(VERSION 3.16.0)

project(ImProjectApp)

set(CXX_CMAKE_STANDARD 17)
set(CXX_CMAKE_STANDARD_REQUIRED ON)

set(IMPROJECTAPP_SOURCES
    main.cpp
)

add_executable(ImProjectApp ${IMPROJECTAPP_SOURCES})
target_include_directories(ImProjectApp PUBLIC .)
target_link_libraries(ImProjectApp PUBLIC ImProjectCommon)
