# ImProject
# CMakeLists.txt
cmake_minimum_required(VERSION 3.16.0)

project(audiogront VERSION 1.0.0)

set(CXX_CMAKE_STANDARD 17)
set(CXX_CMAKE_STANDARD_REQUIRED ON)

# GLFW
add_subdirectory(vendor/glfw)

# IMGUI
add_subdirectory(vendor/imgui)

# IMPLOT
add_subdirectory(vendor/implot)

# SOURCES
add_subdirectory(src)



