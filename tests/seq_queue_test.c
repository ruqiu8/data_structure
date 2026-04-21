#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "seq_queue.h"

void test_create_and_empty() {
    SeqQueue *queue = seq_queue_create();
    assert(queue != NULL);
    assert(seq_queue_empty(queue) == true);
    assert(seq_queue_length(queue) == 0);

    seq_queue_destroy(&queue);
    assert(queue == NULL);
}

void test_enqueue() {
    SeqQueue *queue = seq_queue_create();

    int a = 1, b = 2, c = 3;

    assert(seq_queue_enqueue(queue, &a) == 0);
    assert(seq_queue_enqueue(queue, &b) == 0);
    assert(seq_queue_enqueue(queue, &c) == 0);

    assert(seq_queue_length(queue) == 3);
    assert(seq_queue_empty(queue) == false);

    seq_queue_destroy(&queue);
}

void test_dequeue() {
    SeqQueue *queue = seq_queue_create();

    int a = 10, b = 20, c = 30;
    seq_queue_enqueue(queue, &a);
    seq_queue_enqueue(queue, &b);
    seq_queue_enqueue(queue, &c);

    int val;
    assert(seq_queue_dequeue(queue, &val) == 0);
    assert(val == 10);

    assert(seq_queue_length(queue) == 2);

    assert(seq_queue_dequeue(queue, &val) == 0);
    assert(val == 20);

    assert(seq_queue_dequeue(queue, &val) == 0);
    assert(val == 30);

    assert(seq_queue_length(queue) == 0);
    assert(seq_queue_empty(queue) == true);

    seq_queue_destroy(&queue);
}

void test_get_front() {
    SeqQueue *queue = seq_queue_create();

    int a = 100, b = 200;
    seq_queue_enqueue(queue, &a);
    seq_queue_enqueue(queue, &b);

    int front;
    assert(seq_queue_get_front(queue, &front) == 0);
    assert(front == 100);

    // 获取队首不会删除元素
    assert(seq_queue_get_front(queue, &front) == 0);
    assert(front == 100);

    assert(seq_queue_length(queue) == 2);

    seq_queue_destroy(&queue);
}

void test_full_queue() {
    // 默认容量是10，但只能用9个（预留一个空位判断满）
    SeqQueue *queue = seq_queue_create();

    // 尝试填满队列
    for (int i = 0; i < 9; i++) {
        assert(seq_queue_enqueue(queue, &i) == 0);
    }

    assert(seq_queue_length(queue) == 9);

    // 再入队应该失败（队列已满）
    int x = 100;
    assert(seq_queue_enqueue(queue, &x) == -1);

    seq_queue_destroy(&queue);
}

int main() {
    test_create_and_empty();
    test_enqueue();
    test_dequeue();
    test_get_front();
    test_full_queue();

    printf("All tests passed!\n");
    return 0;
}