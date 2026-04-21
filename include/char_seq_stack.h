//
// Created by ruqiu on 2026/3/19.
//

#ifndef DATA_STRUCTURE_CHAR_SEQ_STACK_H
#define DATA_STRUCTURE_CHAR_SEQ_STACK_H

#include <stdbool.h>
#include <stddef.h>

// 顺序栈默认初始容量
#define CHAR_SEQ_STACK_DEFAULT_CAPACITY 10

// 顺序栈存储的数据类型
typedef char ElemType;

// 顺序栈结构体
typedef struct {
    ElemType *data;     // 指向动态数组的指针
    size_t    top;      // 栈顶指针，指向下一个可用位置
    size_t    capacity; // 数组的总容量
} CharSeqStack;

// 创建一个顺序栈
extern CharSeqStack *char_seq_stack_create();

// 判断顺序栈是否为空
extern bool char_seq_stack_empty(CharSeqStack *stack);

// 获取顺序栈中有效元素的个数
extern size_t char_seq_stack_length(CharSeqStack *stack);

// 将元素压入栈顶
extern int char_seq_stack_push(CharSeqStack *stack, const ElemType *elem);

// 弹出栈顶元素
// 栈为空时返回 -1
extern int char_seq_stack_pop(CharSeqStack *stack, ElemType *elem);

// 获取栈顶元素但不出栈
// 栈为空时返回 -1
extern int char_seq_stack_peek(CharSeqStack *stack, ElemType *elem);

// 打印顺序栈
extern void char_seq_stack_print(CharSeqStack *stack);

// 销毁顺序栈
extern void char_seq_stack_destroy(CharSeqStack **stack);

#endif // DATA_STRUCTURE_CHAR_SEQ_STACK_H