#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "link_queue.h"

void test_create_and_empty() {
    LinkQueue *queue = link_queue_create();
    assert(queue != NULL);
    assert(link_queue_empty(queue) == true);
    assert(link_queue_length(queue) == 0);

    link_queue_destroy(&queue);
    assert(queue == NULL);
}

void test_enqueue() {
    LinkQueue *queue = link_queue_create();

    int a = 1, b = 2, c = 3;

    assert(link_queue_enqueue(queue, &a) == 0);
    assert(link_queue_enqueue(queue, &b) == 0);
    assert(link_queue_enqueue(queue, &c) == 0);

    assert(link_queue_length(queue) == 3);
    assert(link_queue_empty(queue) == false);

    link_queue_destroy(&queue);
}

void test_dequeue() {
    LinkQueue *queue = link_queue_create();

    int a = 10, b = 20, c = 30;
    link_queue_enqueue(queue, &a);
    link_queue_enqueue(queue, &b);
    link_queue_enqueue(queue, &c);

    int val;
    assert(link_queue_dequeue(queue, &val) == 0);
    assert(val == 10);

    assert(link_queue_length(queue) == 2);

    assert(link_queue_dequeue(queue, &val) == 0);
    assert(val == 20);

    assert(link_queue_dequeue(queue, &val) == 0);
    assert(val == 30);

    assert(link_queue_length(queue) == 0);
    assert(link_queue_empty(queue) == true);

    link_queue_destroy(&queue);
}

void test_get_front() {
    LinkQueue *queue = link_queue_create();

    int a = 100, b = 200;
    link_queue_enqueue(queue, &a);
    link_queue_enqueue(queue, &b);

    int front;
    assert(link_queue_get_front(queue, &front) == 0);
    assert(front == 100);

    // 获取队首不会删除元素
    assert(link_queue_get_front(queue, &front) == 0);
    assert(front == 100);

    assert(link_queue_length(queue) == 2);

    link_queue_destroy(&queue);
}

void test_empty_queue_error() {
    LinkQueue *queue = link_queue_create();

    int val;
    assert(link_queue_dequeue(queue, &val) == -1);
    assert(link_queue_get_front(queue, &val) == -1);

    link_queue_destroy(&queue);
}

void test_large_queue() {
    // 测试入队和出队多个元素
    LinkQueue *queue = link_queue_create();

    // 入队 100 个元素
    for (int i = 0; i < 100; i++) {
        assert(link_queue_enqueue(queue, &i) == 0);
    }

    assert(link_queue_length(queue) == 100);

    // 出队 50 个元素
    for (int i = 0; i < 50; i++) {
        int val;
        assert(link_queue_dequeue(queue, &val) == 0);
        assert(val == i);
    }

    assert(link_queue_length(queue) == 50);

    // 再入队 50 个元素
    for (int i = 100; i < 150; i++) {
        assert(link_queue_enqueue(queue, &i) == 0);
    }

    assert(link_queue_length(queue) == 100);

    // 出队所有元素
    for (int i = 50; i < 150; i++) {
        int val;
        assert(link_queue_dequeue(queue, &val) == 0);
        assert(val == i);
    }

    assert(link_queue_empty(queue) == true);

    link_queue_destroy(&queue);
}

int main() {
    test_create_and_empty();
    test_enqueue();
    test_dequeue();
    test_get_front();
    test_empty_queue_error();
    test_large_queue();

    printf("All tests passed!\n");
    return 0;
}