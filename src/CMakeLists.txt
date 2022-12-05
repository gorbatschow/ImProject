cmake_minimum_required(VERSION 3.16.0)

project(ImProjectApp VERSION 1.0.0)

set(CXX_CMAKE_STANDARD 17)
set(CXX_CMAKE_STANDARD_REQUIRED ON)

set(IMPROJECTAPP_HEADERS
    ImProjectApp.h
)

set(IMPROJECTAPP_SOURCES
    main.cpp
    ImProjectApp.cpp
)

add_executable(ImProjectApp ${IMPROJECTAPP_SOURCES} ${IMPROJECTAPP_HEADERS})
target_include_directories(ImProjectApp PUBLIC .)
target_link_libraries(ImProjectApp PUBLIC glfw)
target_link_libraries(ImProjectApp PUBLIC imgui)
target_link_libraries(ImProjectApp PUBLIC implot)
target_link_libraries(ImProjectApp PUBLIC fonts)

include(FindOpenGL)
target_link_libraries(ImProjectApp PUBLIC ${OPENGL_LIBRARIES})

