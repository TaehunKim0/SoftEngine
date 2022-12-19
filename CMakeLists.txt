cmake_minimum_required(VERSION 3.10)
project(SoftRenderer)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Add the source files for the project
file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.h)

# Add the executable target for the project
add_executable(SoftRenderer WIN32 ${SOURCE_FILES})

# Add the include directories for the project
target_include_directories(SoftRenderer PRIVATE src)

# suppress generation of ZERO_CHECK:
set(CMAKE_SUPPRESS_REGENERATION true)

