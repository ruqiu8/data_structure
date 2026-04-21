//
// Created by ruqiu on 2026/3/19.
//

#ifndef DATA_STRUCTURE_INT_LINK_STACK_H
#define DATA_STRUCTURE_INT_LINK_STACK_H

#include <stdbool.h>
#include <stddef.h>

// 链式栈存储的数据类型
typedef int IntElemType;

// 链式栈节点结构体
typedef struct StackNode {
    IntElemType       data; // 数据域
    struct StackNode *next; // 指针域
} StackNode;

// 链式栈结构体
typedef struct {
    StackNode *top;  // 栈顶指针
    size_t     size; // 栈中有效元素的个数
} IntLinkStack;

// 创建一个链式栈
extern IntLinkStack *int_link_stack_create();

// 判断链式栈是否为空
extern bool int_link_stack_empty(IntLinkStack *stack);

// 获取链式栈中有效元素的个数
extern size_t int_link_stack_length(IntLinkStack *stack);

// 将元素压入栈顶
extern int int_link_stack_push(IntLinkStack *stack, const IntElemType *elem);

// 弹出栈顶元素
// 栈为空时返回 -1
extern int int_link_stack_pop(IntLinkStack *stack, IntElemType *elem);

// 获取栈顶元素但不出栈
// 栈为空时返回 -1
extern int int_link_stack_peek(IntLinkStack *stack, IntElemType *elem);

// 打印链式栈
extern void int_link_stack_print(IntLinkStack *stack);

// 销毁链式栈
extern void int_link_stack_destroy(IntLinkStack **stack);

#endif // DATA_STRUCTURE_INT_LINK_STACK_H