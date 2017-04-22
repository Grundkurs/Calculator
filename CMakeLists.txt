cmake_minimum_required(VERSION 3.5)
project(calculator)

set(SFML_ROOT "C:/Program Files (x86)/SFML")
find_package(SFML 2.4.1 COMPONENTS system window graphics main)
include_directories(${SFML_INCLUDE_DIR})
set(SOURCE_FILES main.cpp Application.cpp Application.hpp Calculator.cpp Calculator.hpp Button.cpp Button.hpp Display.cpp Display.hpp Compute.cpp Compute.hpp)

add_executable(calculator WIN32 ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})