cmake_minimum_required(VERSION 3.24)
project(RenderModule)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Add the source files for the project
file(GLOB_RECURSE SOURCE_FILES ./*.cpp ./*.h)

# Add the executable target for the project
# lib module 로 생성
add_library(${PROJECT_NAME} ${SOURCE_FILES})

# suppress generation of ZERO_CHECK:
set(CMAKE_SUPPRESS_REGENERATION true)

# subdirectory를 추가 -> target link 로 연결
# add_subdirectory(../MathModule ../../../build)
# target_link_libraries(${PROJECT_NAME} MathModule)


# PRIVATE MathModule 은 중복으로 되지 않기 위해. 
# target link 할 때 RenderModule만 되게
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR} PRIVATE ../MathModule )