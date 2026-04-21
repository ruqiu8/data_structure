//
// Created by ruqiu on 2026/3/19.
//

#include "seq_queue.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

SeqQueue *seq_queue_create() {
    SeqQueue *queue = (SeqQueue *) malloc(sizeof(SeqQueue));
    if (queue == NULL) {
        return NULL;
    }

    queue->data = (ElemType *) malloc(sizeof(ElemType) * SEQ_QUEUE_DEFAULT_CAPACITY);
    if (queue->data == NULL) {
        free(queue);
        return NULL;
    }

    queue->capacity = SEQ_QUEUE_DEFAULT_CAPACITY;
    queue->front    = 0;
    queue->rear     = 0;

    return queue;
}

// 销毁循环队列
void seq_queue_destroy(SeqQueue **queue) {
    assert(queue != NULL);
    if (*queue == NULL) {
        return;
    }

    if ((*queue)->data != NULL) {
        free((*queue)->data);
    }
    free(*queue);
    *queue = NULL;
}

// 当 front == rear 时，队列为空
bool seq_queue_empty(SeqQueue *queue) {
    assert(queue != NULL);
    return queue->front == queue->rear;
}

// 使用 (rear - front + capacity) % capacity 计算实际长度
size_t seq_queue_length(SeqQueue *queue) {
    assert(queue != NULL);
    // 需要考虑 rear 可能小于 front 的情况
    return (queue->rear + queue->capacity - queue->front) % queue->capacity;
}

// 当 (rear + 1) % capacity == front 时，队列已满
static bool seq_queue_full(SeqQueue *queue) {
    assert(queue != NULL);
    return (queue->rear + 1) % queue->capacity == queue->front;
}

int seq_queue_enqueue(SeqQueue *queue, const ElemType *elem) {
    assert(queue != NULL && elem != NULL);

    // 检查队列是否已满
    if (seq_queue_full(queue)) {
        return -1;
    }

    // 将元素添加到队尾
    queue->data[queue->rear] = *elem;
    // 更新队尾索引（循环）
    queue->rear = (queue->rear + 1) % queue->capacity;

    return 0;
}

int seq_queue_dequeue(SeqQueue *queue, ElemType *elem) {
    assert(queue != NULL);

    // 检查队列是否为空
    if (seq_queue_empty(queue)) {
        return -1;
    }
    if (elem != NULL) {
        // 获取队首元素
        *elem = queue->data[queue->front];
    }

    // 更新队首索引（循环）
    queue->front = (queue->front + 1) % queue->capacity;

    return 0;
}

int seq_queue_get_front(SeqQueue *queue, ElemType *elem) {
    assert(queue != NULL && elem != NULL);

    // 检查队列是否为空
    if (seq_queue_empty(queue)) {
        return -1;
    }

    // 获取队首元素
    *elem = queue->data[queue->front];

    return 0;
}

void seq_queue_print(SeqQueue *queue, PrintElem print_elem) {
    assert(queue != NULL && queue->data != NULL);
    printf("Queue: [");

    // 循环队列遍历的核心逻辑
    size_t i = queue->front;
    while (i != queue->rear) {
        print_elem(&queue->data[i]); // 调用传入的打印函数

        i = (i + 1) % queue->capacity; // 索引向后移动，注意取模实现循环

        if (i != queue->rear) {
            printf(", ");
        }
    }

    printf("]\n");
}