//
// Created by ruqiu on 2026/3/19.
//

#ifndef DATA_STRUCTURE_LINK_QUEUE_H
#define DATA_STRUCTURE_LINK_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

// 队列元素类型
typedef int ElemType;

// 链表队列节点结构体
typedef struct QueueNode {
    ElemType          data;
    struct QueueNode *next;
} QueueNode;

// 链表队列结构体
typedef struct {
    QueueNode *front;  // 头节点
    QueueNode *rear;   // 队尾节点
    size_t     length; // 队列长度
} LinkQueue;

// 创建一个链表队列
extern LinkQueue *link_queue_create();

// 销毁链表队列
extern void link_queue_destroy(LinkQueue **queue);

// 判断链表队列是否为空
extern bool link_queue_empty(LinkQueue *queue);

// 获取链表队列的长度
extern size_t link_queue_length(LinkQueue *queue);

// 入队（队尾插入元素）
extern int link_queue_enqueue(LinkQueue *queue, const ElemType *elem);

// 出队（队首删除元素）
// 返回值：0 表示成功，-1 表示队列为空
extern int link_queue_dequeue(LinkQueue *queue, ElemType *elem);

// 获取队首元素（不删除）
// 返回值：0 表示成功，-1 表示队列为空
extern int link_queue_get_front(LinkQueue *queue, ElemType *elem);

#endif // DATA_STRUCTURE_LINK_QUEUE_H