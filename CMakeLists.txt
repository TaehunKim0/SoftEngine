cmake_minimum_required(VERSION 3.24)
project(SoftPragram)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Add the source files for the project
file(GLOB_RECURSE SOURCE_FILES src/Program/*.cpp src/Program/*.h)

# Add the executable target for the project
add_executable(SoftPragram WIN32 ${SOURCE_FILES})

add_subdirectory(src/Module/MathModule)
add_subdirectory(src/Module/RenderModule)

target_link_libraries(${PROJECT_NAME} MathModule RenderModule)

# suppress generation of ZERO_CHECK:
set(CMAKE_SUPPRESS_REGENERATION true)

