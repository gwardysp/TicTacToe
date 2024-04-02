cmake_minimum_required(VERSION 3.22)

project(gtkTic)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-4.0)

add_executable(gtkTic src/TicTac.h src/TicTac.cpp src/main.cpp)

target_link_directories(${PROJECT_NAME} PRIVATE ${GTKMM_LIBRARY_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GTKMM_LIBRARIES})
