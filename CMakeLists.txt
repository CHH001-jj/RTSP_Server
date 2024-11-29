# 最低 CMake 版本要求
cmake_minimum_required(VERSION 3.10)

# 定义项目名称
project(RTSP_Server)

# 设置 C++ 标准（可选）
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加可执行文件
add_executable(RTSP_Server main.cpp rtp.cpp utils.cpp)
