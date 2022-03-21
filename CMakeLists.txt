cmake_minimum_required(VERSION 3.1)
project("libIGL polyscope example project")
file(GLOB SRC_FILES ./src/*)
file(GLOB HEADER_FILES ./include/*)

# libigl
add_subdirectory(./deps/libigl/)

add_subdirectory(./deps/polyscope/)



add_executable(frame_update_benchmark main.cpp)
target_link_libraries(frame_update_benchmark igl::core polyscope Eigen3::Eigen)
