//
// Created by ruqiu on 2026/3/19.
//

#include "link_queue.h"

#include <assert.h>
#include <stdlib.h>

LinkQueue *link_queue_create() {
    LinkQueue *queue = (LinkQueue *) malloc(sizeof(LinkQueue));
    if (queue == NULL) {
        return NULL;
    }

    // 创建一个头节点，简化操作
    QueueNode *sentinel = (QueueNode *) malloc(sizeof(QueueNode));
    if (sentinel == NULL) {
        free(queue);
        return NULL;
    }

    sentinel->next = NULL;
    queue->front   = sentinel;
    queue->rear    = sentinel;
    queue->length  = 0;

    return queue;
}

void link_queue_destroy(LinkQueue **queue) {
    assert(queue != NULL);
    if (*queue == NULL) {
        return;
    }

    // 释放所有节点
    QueueNode *current = (*queue)->front;
    while (current != NULL) {
        QueueNode *next = current->next;
        free(current);
        current = next;
    }

    free(*queue);
    *queue = NULL;
}

// 当 front == rear 时，队列为空
bool link_queue_empty(LinkQueue *queue) {
    assert(queue != NULL);
    return queue->front == queue->rear;
}

size_t link_queue_length(LinkQueue *queue) {
    assert(queue != NULL);
    return queue->length;
}

int link_queue_enqueue(LinkQueue *queue, const ElemType *elem) {
    assert(queue != NULL && elem != NULL);

    // 创建新节点
    QueueNode *new_node = (QueueNode *) malloc(sizeof(QueueNode));
    if (new_node == NULL) {
        return -1;
    }

    new_node->data = *elem;
    new_node->next = NULL;

    // 将新节点添加到队尾
    queue->rear->next = new_node;
    queue->rear       = new_node;
    queue->length++;

    return 0;
}

int link_queue_dequeue(LinkQueue *queue, ElemType *elem) {
    assert(queue != NULL);
    // 检查队列是否为空
    if (link_queue_empty(queue)) {
        return -1;
    }

    QueueNode *first_node = queue->front->next;
    if (elem != NULL) {
        *elem = first_node->data;
    }

    // 删除队首节点
    queue->front->next = first_node->next;

    // 如果删除的是最后一个节点，需要更新 rear 指针
    if (first_node == queue->rear) {
        queue->rear = queue->front;
    }

    free(first_node);
    queue->length--;

    return 0;
}

int link_queue_get_front(LinkQueue *queue, ElemType *elem) {
    assert(queue != NULL && elem != NULL);

    // 检查队列是否为空
    if (link_queue_empty(queue)) {
        return -1;
    }

    *elem = queue->front->next->data;

    return 0;
}