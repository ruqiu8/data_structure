# 数据结构

一个用 C 语言实现的基础数据结构库，包含线性表、栈、队列等常用数据结构及其应用。

## 项目结构

```
data_structure/
├── include/              # 头文件目录
│   ├── seqlist.h          # 顺序表
│   ├── linklist.h         # 链表
│   ├── char_seq_stack.h   # 字符顺序栈
│   ├── int_link_stack.h   # 整型链式栈
│   ├── seq_queue.h        # 循环队列
│   ├── link_queue.h       # 链表队列
│   └── infix.h            # 表达式求值
├── src/                  # 源文件目录
│   ├── seqlist.c
│   ├── linklist.c
│   ├── char_seq_stack.c
│   ├── int_link_stack.c
│   ├── seq_queue.c
│   ├── link_queue.c
│   └── infix.c
├── tests/                # 单元测试目录
│   ├── seqlist_test.c
│   ├── linklist_test.c
│   ├── char_seq_stack_test.c
│   ├── int_link_stack_test.c
│   ├── seq_queue_test.c
│   ├── link_queue_test.c
│   └── infix_test.c
├── CMakeLists.txt        # CMake 构建配置
```

## 构建与测试

### 环境要求

- CMake 3.10+
- C 编译器 (GCC/Clang)
- C11 标准

### 构建项目

```bash
# 创建构建目录
mkdir build && cd build

# 配置项目
cmake ..

# 编译
make
```

### 运行测试

```bash
# 运行所有测试
ctest

# 或直接运行单个测试
./seqlist_test
./linklist_test
./char_seq_stack_test
./int_link_stack_test
./seq_queue_test
./link_queue_test
./infix_test
```

### 示例输出

```
$ ./seqlist_test
All tests passed!

$ ./linklist_test
All tests passed!
```

