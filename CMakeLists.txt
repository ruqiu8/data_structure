cmake_minimum_required(VERSION 3.10)

# 项目名称和版本
project(data_structure VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 打印编译信息
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# 加载头文件
include_directories(include)

# 查找源文件
file(GLOB SOURCES "src/*.c")

# 示例源文件
file(GLOB SAMPLE_SOURCES "samples/*.c")

# 批量生成可执行文件
foreach(SAMPLE_PATH ${SAMPLE_SOURCES})
    # 获取文件名不带后缀
    get_filename_component(SAMPLE_NAME ${SAMPLE_PATH} NAME_WE)

    # 为每个示例创建一个可执行文件
    # 名字就是文件名，源代码包含该示例文件 + src 目录下的通用实现
    add_executable(${SAMPLE_NAME} ${SAMPLE_PATH} ${SOURCES})

    message(STATUS "Created executable: ${SAMPLE_NAME}")
endforeach()