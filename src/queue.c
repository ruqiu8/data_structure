//
// Created by ruqiu on 2026/4/10.
//
#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

int queue_init(Queue* queue)
{
    if (queue == NULL) return -1;
    queue->length = 0;
    queue->front = NULL;
    queue->rear = NULL;
    return 0;
}

int queue_length(Queue* queue, size_t* length)
{
    if (queue == NULL || length == NULL) return -1;
    *length = queue->length;
    return 0;
}

int queue_empty(Queue* queue, bool* is_empty)
{
    if (queue == NULL || is_empty == NULL) return -1;
    *is_empty = queue->length == 0;
    return 0;
}

int queue_enqueue(Queue* queue, const ElemType* elem)
{
    if (queue == NULL || elem == NULL) return -1;

    // 创建新节点
    LNode* new_node = (LNode*)malloc(sizeof(LNode));
    if (new_node == NULL) return -1;
    new_node->data = *elem;
    new_node->next = NULL;

    // 如果队列为空，front 和 rear 都指向新节点
    if (queue->front == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        // 否则，在 rear 后面插入新节点
        queue->rear->next = new_node;
        queue->rear = new_node;
    }

    queue->length++;
    return 0;
}

int queue_dequeue(Queue* queue, ElemType* elem)
{
    if (queue == NULL || queue->length == 0) return -1;

    LNode* front = queue->front;
    queue->front = front->next;
    if (elem != NULL)
    {
        *elem = front->data;
    }

    // 如果删除的是最后一个元素，需要将 rear 设为 NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(front);
    queue->length--;
    return 0;
}

int queue_get_front(Queue* queue, ElemType* elem)
{
    if (queue == NULL || queue->length == 0 || elem == NULL) return -1;
    LNode* front = queue->front;
    *elem = front->data;
    return 0;
}

int queue_get_rear(Queue* queue, ElemType* elem)
{
    if (queue == NULL || queue->length == 0 || elem == NULL) return -1;
    LNode* rear = queue->rear;
    *elem = rear->data;
    return 0;
}

int queue_print(Queue* queue, PrintElem print_elem)
{
    if (queue == NULL || print_elem == NULL) {
        return -1;
    }

    printf("[");
    // 处理空队列
    if (queue->length == 0 || queue->front == NULL) {
        printf("]\n");
        return 0;
    }

    // 遍历打印元素
    LNode* current = queue->front;
    size_t count = 0;
    while (current != NULL) {
        print_elem(&current->data);
        // 元素之间添加逗号分隔
        if (count < queue->length - 1 && current->next != NULL) {
            printf(", ");
        }
        current = current->next;
        count++;
    }
    printf("]\n");
    return 0;
}

int queue_destroy(Queue* queue)
{
    if (queue == NULL) return -1;

    // 释放所有节点
    LNode* current = queue->front;
    while (current != NULL) {
        LNode* temp = current;
        current = current->next;
        free(temp);
    }

    // 重置队列
    queue->front = NULL;
    queue->rear = NULL;
    queue->length = 0;

    return 0;
}
