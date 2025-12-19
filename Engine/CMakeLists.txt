cmake_minimum_required(VERSION 3.15)
project(3DPhysicsEngine VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Vulkan and GLFW packages
find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

# Main
add_executable(${PROJECT_NAME} main.cpp PhysicsEngine/engine.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Vulkan glfw)

# Tests
add_executable(EngineTests Tests/engine_tests.cpp PhysicsEngine/engine.cpp)
target_link_libraries(EngineTests PRIVATE Vulkan::Vulkan glfw)

