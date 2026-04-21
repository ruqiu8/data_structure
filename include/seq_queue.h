//
// Created by ruqiu on 2026/3/19.
//

#ifndef DATA_STRUCTURE_SEQ_QUEUE_H
#define DATA_STRUCTURE_SEQ_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

// 循环队列默认容量
#define SEQ_QUEUE_DEFAULT_CAPACITY 10

// 队列元素类型
typedef int ElemType;

// 打印 ElemType 不要换行
typedef void (*PrintElem)(const ElemType *);

// 循环队列结构体
typedef struct {
    ElemType *data;     // 指向数组的指针
    size_t    capacity; // 数组容量
    size_t    front;    // 队首索引
    size_t    rear;     // 队尾索引（下一个可入队的位置）
} SeqQueue;

// 创建一个循环队列
extern SeqQueue *seq_queue_create(void);

// 销毁循环队列
extern void seq_queue_destroy(SeqQueue **queue);

// 判断循环队列是否为空
extern bool seq_queue_empty(SeqQueue *queue);

// 获取循环队列的长度
extern size_t seq_queue_length(SeqQueue *queue);

// 入队
// 返回值：0 表示成功，-1 表示队列已满
extern int seq_queue_enqueue(SeqQueue *queue, const ElemType *elem);

// 出队
// 返回值：0 表示成功，--1 表示队列为空
extern int seq_queue_dequeue(SeqQueue *queue, ElemType *elem);

// 获取队首元素
// 返回值：0 表示成功，-1 表示队列为空
extern int seq_queue_get_front(SeqQueue *queue, ElemType *elem);

extern void seq_queue_print(SeqQueue *queue, PrintElem print_elem);

#endif // DATA_STRUCTURE_SEQ_QUEUE_H