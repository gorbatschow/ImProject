cmake_minimum_required(VERSION 3.16.0)

project(imapp VERSION 1.0.0)

set(CXX_CMAKE_STANDARD 20)
set(CXX_CMAKE_STANDARD_REQUIRED ON)

set(IMAPP_SRC
    imapp/ImAppMainWindow.cpp
)

add_library(${PROJECT_NAME} ${IMAPP_SRC})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
target_include_directories(${PROJECT_NAME} PUBLIC imapp)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC imgui)
target_link_libraries(${PROJECT_NAME} PUBLIC implot)
target_link_libraries(${PROJECT_NAME} PUBLIC imfonts)
target_link_libraries(${PROJECT_NAME} PUBLIC stb)

include(FindOpenGL)
target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENGL_LIBRARIES})

