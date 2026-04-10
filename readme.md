本仓库是王道数据结构教材中出现的数据结构的 C 语言实现，但对函数名和实现逻辑进行了一些修改。

目录说明：

- `include`：公共头文件
- `src`：实际代码实现
- `samples`：代码的一些示例

命名规则：

- 文件名采用下划线命名，代码文件和头文件名词相同，示例命名为 `xxx_sample.c`，`xxx` 为代码文件名。
- 函数采用下划线命名，结构体和 `typeof` 使用驼峰命名。

开发环境：Ubuntu、GCC 和 Cmake，IDE 使用 Clion。

部署：

1. 执行 `mkdir build && cd build`
2. 执行 `cmake .. && make`
3. 执行 `./xxx_sample` 运行相应的示例
