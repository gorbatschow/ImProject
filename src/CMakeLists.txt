cmake_minimum_required(VERSION 3.16.0)

project(ImProjectExe)

set(CXX_CMAKE_STANDARD 20)
set(CXX_CMAKE_STANDARD_REQUIRED ON)

set(IMPROJECTEXE_SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${IMPROJECTEXE_SOURCES})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_link_libraries(${PROJECT_NAME} PUBLIC ImApplication)
target_link_libraries(${PROJECT_NAME} PUBLIC mini)
target_link_libraries(${PROJECT_NAME} PUBLIC ImWrapper)
