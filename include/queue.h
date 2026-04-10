//
// Created by ruqiu on 2026/4/10.
//

#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#include "linklist.h"


// 链队列节点
typedef struct Queue {
    LNode* front;
    LNode* rear;
    size_t length;
} Queue;


extern int queue_init(Queue* queue);
extern int queue_length(Queue* queue, size_t* length);
extern int queue_empty(Queue* queue, bool* is_empty);
extern int queue_enqueue(Queue* queue, const ElemType* elem);
extern int queue_dequeue(Queue* queue, ElemType* elem);
extern int queue_get_front(Queue* queue, ElemType* elem);
extern int queue_get_rear(Queue* queue, ElemType* elem);
extern int queue_print(Queue* queue, PrintElem print_elem);
extern int queue_destroy(Queue* queue);

#endif //DATA_STRUCTURE_QUEUE_H