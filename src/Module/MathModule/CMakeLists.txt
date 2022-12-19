cmake_minimum_required(VERSION 3.24)
project(MathModule)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Add the source files for the project
file(GLOB_RECURSE SOURCE_FILES ./*.cpp ./*.h)

# Add the executable target for the project
add_library(${PROJECT_NAME} ${SOURCE_FILES})

# suppress generation of ZERO_CHECK:
set(CMAKE_SUPPRESS_REGENERATION true)

# target link libraries 할 때 include 도 같이 될 수 있게 PUBLIC 으로 설정
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})