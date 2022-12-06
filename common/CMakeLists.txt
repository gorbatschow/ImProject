cmake_minimum_required(VERSION 3.16.0)

project(ImProjectCommon VERSION 1.0.0)

set(CXX_CMAKE_STANDARD 17)
set(CXX_CMAKE_STANDARD_REQUIRED ON)

set(IMPROJECTCOMMON_SOURCES
    ImProjectApp.cpp
)

add_library(ImProjectCommon ${IMPROJECTCOMMON_SOURCES})
target_include_directories(ImProjectCommon PUBLIC .)
target_link_libraries(ImProjectCommon PUBLIC glfw)
target_link_libraries(ImProjectCommon PUBLIC imgui)
target_link_libraries(ImProjectCommon PUBLIC implot)
target_link_libraries(ImProjectCommon PUBLIC fonts)
target_link_libraries(ImProjectCommon PUBLIC stb)

include(FindOpenGL)
target_link_libraries(ImProjectCommon PUBLIC ${OPENGL_LIBRARIES})

