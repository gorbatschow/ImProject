cmake_minimum_required(VERSION 3.16.0)

project(fonts)

set(FONTS_SOURCES
    # Roboto
    fonts/RobotoRegular.cpp
    fonts/RobotoBold.cpp
    fonts/RobotoItalic.cpp
    # Roboto Mono
    fonts/RobotoMonoRegular.cpp
    fonts/RobotoMonoBold.cpp
    fonts/RobotoMonoItalic.cpp
)

add_library(fonts ${FONTS_SOURCES})
target_include_directories(fonts PUBLIC fonts)
