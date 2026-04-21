#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "int_link_stack.h"

void test_create_and_empty() {
    IntLinkStack *stack = int_link_stack_create();
    assert(stack != NULL);
    assert(int_link_stack_empty(stack) == true);
    assert(int_link_stack_length(stack) == 0);

    int_link_stack_destroy(&stack);
    assert(stack == NULL);
}

void test_push() {
    IntLinkStack *stack = int_link_stack_create();

    int a = 1, b = 2, c = 3;

    assert(int_link_stack_push(stack, &a) == 0);
    assert(int_link_stack_length(stack) == 1);

    assert(int_link_stack_push(stack, &b) == 0);
    assert(int_link_stack_length(stack) == 2);

    assert(int_link_stack_push(stack, &c) == 0);
    assert(int_link_stack_length(stack) == 3);

    int_link_stack_destroy(&stack);
}

void test_pop() {
    IntLinkStack *stack = int_link_stack_create();

    int a = 10, b = 20, c = 30;
    int_link_stack_push(stack, &a);
    int_link_stack_push(stack, &b);
    int_link_stack_push(stack, &c);

    // 栈是 LIFO，所以弹出顺序是 c, b, a
    int val;
    assert(int_link_stack_pop(stack, &val) == 0);
    assert(val == c);

    assert(int_link_stack_pop(stack, &val) == 0);
    assert(val == b);

    assert(int_link_stack_pop(stack, &val) == 0);
    assert(val == a);

    assert(int_link_stack_empty(stack) == true);

    int_link_stack_destroy(&stack);
}

void test_peek() {
    IntLinkStack *stack = int_link_stack_create();

    int a = 100, b = 200;
    int_link_stack_push(stack, &a);
    int_link_stack_push(stack, &b);

    int val;
    assert(int_link_stack_peek(stack, &val) == 0);
    assert(val == b); // 栈顶是 200

    assert(int_link_stack_length(stack) == 2); // peek 不弹出

    int_link_stack_destroy(&stack);
}

void test_empty_stack_operations() {
    IntLinkStack *stack = int_link_stack_create();

    int val;
    assert(int_link_stack_pop(stack, &val) == -1);  // 空栈弹出失败
    assert(int_link_stack_peek(stack, &val) == -1); // 空栈获取栈顶失败
    assert(int_link_stack_empty(stack) == true);

    int_link_stack_destroy(&stack);
}

void test_pop_null_elem() {
    IntLinkStack *stack = int_link_stack_create();

    int a = 123;
    int_link_stack_push(stack, &a);

    // pop 时 elem 为 NULL 应该也成功
    assert(int_link_stack_pop(stack, NULL) == 0);
    assert(int_link_stack_empty(stack) == true);

    int_link_stack_destroy(&stack);
}

int main() {
    test_create_and_empty();
    test_push();
    test_pop();
    test_peek();
    test_empty_stack_operations();
    test_pop_null_elem();
    printf("All tests passed!\n");
    return 0;
}