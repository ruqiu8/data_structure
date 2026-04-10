//
// Created by ruqiu on 2026/4/10.
//
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

// 辅助函数:打印单个元素
void print_int(const ElemType* e) {
    printf("%d", *e);
}

int main()
{
    // 创建队列
    Queue queue;

    // 初始化
    if (queue_init(&queue) == 0) {
        printf("队列初始化成功\n");
    } else {
        printf("队列初始化失败\n");
        return -1;
    }

    // 获取长度
    size_t length;
    queue_length(&queue, &length);
    printf("当前长度: %zu\n", length);

    // 判断是否为空
    bool is_empty;
    queue_empty(&queue, &is_empty);
    printf("队列是否为空: %s\n", is_empty ? "是" : "否");

    // 入队操作
    printf("\n入队元素 10, 20, 30, 40, 50\n");
    for (int i = 1; i <= 5; i++) {
        ElemType elem = i * 10;
        if (queue_enqueue(&queue, &elem) == 0) {
            printf("入队元素 %d 成功\n", elem);
        } else {
            printf("入队元素 %d 失败\n", elem);
        }
    }

    // 打印队列
    printf("队列内容: ");
    queue_print(&queue, print_int);

    // 获取长度
    queue_length(&queue, &length);
    printf("当前长度: %zu\n", length);

    // 再次判断是否为空
    queue_empty(&queue, &is_empty);
    printf("队列是否为空: %s\n", is_empty ? "是" : "否");

    // 获取队头元素
    ElemType front_elem;
    if (queue_get_front(&queue, &front_elem) == 0) {
        printf("队头元素是: %d\n", front_elem);
    } else {
        printf("获取队头元素失败\n");
    }

    // 获取队尾元素
    ElemType rear_elem;
    if (queue_get_rear(&queue, &rear_elem) == 0) {
        printf("队尾元素是: %d\n", rear_elem);
    } else {
        printf("获取队尾元素失败\n");
    }

    // 出队操作
    printf("\n出队操作:\n");
    if (queue_dequeue(&queue, &front_elem) == 0) {
        printf("出队元素: %d\n", front_elem);
    }
    printf("队列内容: ");
    queue_print(&queue, print_int);

    // 再次获取队头和队尾元素
    if (queue_get_front(&queue, &front_elem) == 0) {
        printf("队头元素是: %d\n", front_elem);
    }
    if (queue_get_rear(&queue, &rear_elem) == 0) {
        printf("队尾元素是: %d\n", rear_elem);
    }

    // 再次获取长度
    queue_length(&queue, &length);
    printf("当前长度: %zu\n", length);

    // 出队所有元素
    printf("\n出队所有元素:\n");
    queue_empty(&queue, &is_empty);
    while (!is_empty) {
        if (queue_dequeue(&queue, &front_elem) == 0) {
            printf("出队元素: %d\n", front_elem);
        } else {
            printf("出队失败\n");
            break;
        }
        queue_empty(&queue, &is_empty);
    }

    // 判断是否为空
    queue_empty(&queue, &is_empty);
    printf("\n队列是否为空: %s\n", is_empty ? "是" : "否");

    // 再次测试入队和出队
    printf("\n-------测试入队和出队-------\n");
    printf("入队元素 100, 200, 300\n");
    ElemType elems[] = {100, 200, 300};
    for (int i = 0; i < 3; i++) {
        if (queue_enqueue(&queue, &elems[i]) == 0) {
            printf("入队元素 %d 成功\n", elems[i]);
        }
    }

    // 打印队列
    printf("队列内容: ");
    queue_print(&queue, print_int);

    // 获取队头和队尾元素
    if (queue_get_front(&queue, &front_elem) == 0) {
        printf("队头元素是: %d\n", front_elem);
    }
    if (queue_get_rear(&queue, &rear_elem) == 0) {
        printf("队尾元素是: %d\n", rear_elem);
    }

    // 出队部分元素
    printf("\n出队 2 个元素:\n");
    for (int i = 0; i < 2; i++) {
        if (queue_dequeue(&queue, &front_elem) == 0) {
            printf("出队元素: %d\n", front_elem);
        }
    }

    // 打印队列
    printf("队列内容: ");
    queue_print(&queue, print_int);

    // 获取队头和队尾元素
    if (queue_get_front(&queue, &front_elem) == 0) {
        printf("队头元素是: %d\n", front_elem);
    }
    if (queue_get_rear(&queue, &rear_elem) == 0) {
        printf("队尾元素是: %d\n", rear_elem);
    }

    // 获取长度
    queue_length(&queue, &length);
    printf("当前长度: %zu\n", length);

    // 销毁队列
    queue_destroy(&queue);
    printf("\n队列已销毁\n");

    return 0;
}