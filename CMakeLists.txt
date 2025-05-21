cmake_minimum_required(VERSION 3.15)
project(Untitled)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------------------
# Set Paths (Adjust for your layout)
# -------------------------------
set(GLFW_ROOT "C:/libs/glfw-3.4")
set(GLFW_INCLUDE_DIR "${GLFW_ROOT}/include")
set(GLFW_LIB_DIR "${GLFW_ROOT}/lib-vc2022")

set(BGFX_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/third_party/bgfx/include")
set(BX_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/third_party/bx/include")
set(BIMG_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/third_party/bimg/include")
set(BGFX_LIB_DIR "${CMAKE_SOURCE_DIR}/third_party/bgfx/.build/win64_vs2022/bin")

# -------------------------------
# Include Directories
# -------------------------------
include_directories(
    ${GLFW_INCLUDE_DIR}
    ${BGFX_INCLUDE_DIR}
    ${BX_INCLUDE_DIR}
    ${BIMG_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)

# -------------------------------
# Link Directories
# -------------------------------
link_directories(
    ${GLFW_LIB_DIR}
    ${BGFX_LIB_DIR}
)

# -------------------------------
# Source Files
# -------------------------------
file(GLOB_RECURSE GAME_SOURCES "src/*.cpp")

# -------------------------------
# Add Executable
# -------------------------------
add_executable(MyGame ${GAME_SOURCES})

# -------------------------------
# Preprocessor Definitions
# -------------------------------
add_definitions(-DGLFW_STATIC)
add_definitions(-DBGFX_CONFIG_DEBUG=1)

# -------------------------------
# Link Libraries
# -------------------------------
target_link_libraries(MyGame
    glfw3
    bgfxDebug
    bxDebug
    bimgDebug
    gdi32
    user32
    kernel32
    opengl32
)
