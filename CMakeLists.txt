cmake_minimum_required(VERSION 3.10)
project(TinyInfer)

# C++ 标准
set(CMAKE_CXX_STANDARD 17)

# 1. 寻找 Glog 库
find_package(glog REQUIRED)

# 2. 【关键修改】告诉编译器头文件在 tiny/include
include_directories(tiny/include)

# 3. 【关键修改】告诉编译器源文件在 tiny/source
file(GLOB SOURCES "tiny/source/*.cpp")

# 4. 生成可执行文件
add_executable(TinyInfer ${SOURCES})

# 5. 链接 Glog
target_link_libraries(TinyInfer glog::glog)