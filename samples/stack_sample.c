//
// Created by ruqiu on 2026/4/10.
//
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

// 辅助函数：打印单个元素
void print_int(const ElemType* e) {
    printf("%d", *e);
}

int main()
{
    // 创建栈
    Stack stack;
    stack.seq_list = (SeqList*)malloc(sizeof(SeqList));
    if (stack.seq_list == NULL) {
        printf("内存分配失败\n");
        return -1;
    }

    // 初始化
    if (stack_init(&stack) == 0) {
        printf("栈初始化成功\n");
    } else {
        printf("栈初始化失败\n");
        free(stack.seq_list);
        return -1;
    }

    // 获取长度
    size_t length;
    stack_length(&stack, &length);
    printf("当前长度: %zu\n", length);

    // 判断是否为空
    bool is_empty;
    stack_empty(&stack, &is_empty);
    printf("栈是否为空: %s\n", is_empty ? "是" : "否");

    // 压栈操作
    printf("\n压入元素 10, 20, 30, 40, 50\n");
    for (int i = 1; i <= 5; i++) {
        ElemType elem = i * 10;
        if (stack_push(&stack, &elem) == 0) {
            printf("压入元素 %d 成功\n", elem);
        } else {
            printf("压入元素 %d 失败\n", elem);
        }
    }

    // 打印栈
    printf("栈内容: ");
    stack_print(&stack, print_int);
    printf("\n");

    // 获取长度
    stack_length(&stack, &length);
    printf("当前长度: %zu\n", length);

    // 再次判断是否为空
    stack_empty(&stack, &is_empty);
    printf("栈是否为空: %s\n", is_empty ? "是" : "否");

    // 获取栈顶元素
    ElemType top_elem;
    if (stack_get_top(&stack, &top_elem) == 0) {
        printf("栈顶元素是: %d\n", top_elem);
    } else {
        printf("获取栈顶元素失败\n");
    }

    // 弹栈操作
    printf("\n弹出第 1 个元素: ");
    if (stack_pop(&stack, &top_elem) == 0) {
        printf("%d\n", top_elem);
    }
    printf("栈内容: ");
    stack_print(&stack, print_int);
    printf("\n");

    // 再次获取栈顶元素
    if (stack_get_top(&stack, &top_elem) == 0) {
        printf("栈顶元素是: %d\n", top_elem);
    }

    // 再次获取长度
    stack_length(&stack, &length);
    printf("当前长度: %zu\n", length);

    // 弹出所有元素
    printf("\n弹栈操作:\n");
    stack_empty(&stack, &is_empty);
    while (!is_empty) {
        if (stack_pop(&stack, &top_elem) == 0) {
            printf("弹出元素: %d\n", top_elem);
        } else {
            printf("弹栈失败\n");
            break;
        }
        stack_empty(&stack, &is_empty);
    }

    // 判断是否为空
    stack_empty(&stack, &is_empty);
    printf("\n栈是否为空: %s\n", is_empty ? "是" : "否");

    // 再次测试压栈和弹栈
    printf("\n-------测试压栈和弹栈-------\n");
    printf("压入元素 100, 200, 300\n");
    ElemType elems[] = {100, 200, 300};
    for (int i = 0; i < 3; i++) {
        if (stack_push(&stack, &elems[i]) == 0) {
            printf("压入元素 %d 成功\n", elems[i]);
        }
    }

    // 打印栈
    printf("栈内容: ");
    stack_print(&stack, print_int);
    printf("\n");

    // 获取栈顶元素
    if (stack_get_top(&stack, &top_elem) == 0) {
        printf("栈顶元素是: %d\n", top_elem);
    }

    // 弹出部分元素
    printf("\n弹出 2 个元素:\n");
    for (int i = 0; i < 2; i++) {
        if (stack_pop(&stack, &top_elem) == 0) {
            printf("弹出元素: %d\n", top_elem);
        }
    }

    // 打印栈
    printf("栈内容: ");
    stack_print(&stack, print_int);
    printf("\n");

    // 获取栈顶元素
    if (stack_get_top(&stack, &top_elem) == 0) {
        printf("栈顶元素是: %d\n", top_elem);
    }

    // 获取长度
    stack_length(&stack, &length);
    printf("当前长度: %zu\n", length);

    // 销毁栈
    stack_destroy(&stack);
    printf("\n栈已销毁\n");

    // 释放内存
    free(stack.seq_list);

    return 0;
}