# ImProject

cmake_minimum_required(VERSION 3.16.0)

project(ImProject VERSION 1.0.0)

# GLFW
add_subdirectory(external/glfw)

# IMGUI
add_subdirectory(external/imgui)

# IMPLOT
add_subdirectory(external/implot)

# FONTS
add_subdirectory(external/fonts)

# COMMON
add_subdirectory(common)

# SOURCES
add_subdirectory(src)



