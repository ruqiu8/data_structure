#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "char_seq_stack.h"

void test_create_and_empty() {
    CharSeqStack *stack = char_seq_stack_create();
    assert(stack != NULL);
    assert(char_seq_stack_empty(stack) == true);
    assert(char_seq_stack_length(stack) == 0);

    char_seq_stack_destroy(&stack);
    assert(stack == NULL);
}

void test_push() {
    CharSeqStack *stack = char_seq_stack_create();

    char a = 'a', b = 'b', c = 'c';

    assert(char_seq_stack_push(stack, &a) == 0);
    assert(char_seq_stack_length(stack) == 1);

    assert(char_seq_stack_push(stack, &b) == 0);
    assert(char_seq_stack_length(stack) == 2);

    assert(char_seq_stack_push(stack, &c) == 0);
    assert(char_seq_stack_length(stack) == 3);

    char_seq_stack_destroy(&stack);
}

void test_pop() {
    CharSeqStack *stack = char_seq_stack_create();

    char a = 'x', b = 'y', c = 'z';
    char_seq_stack_push(stack, &a);
    char_seq_stack_push(stack, &b);
    char_seq_stack_push(stack, &c);

    // 栈是 LIFO，所以弹出顺序是 c, b, a
    char val;
    assert(char_seq_stack_pop(stack, &val) == 0);
    assert(val == c);

    assert(char_seq_stack_pop(stack, &val) == 0);
    assert(val == b);

    assert(char_seq_stack_pop(stack, &val) == 0);
    assert(val == a);

    assert(char_seq_stack_empty(stack) == true);

    char_seq_stack_destroy(&stack);
}

void test_peek() {
    CharSeqStack *stack = char_seq_stack_create();

    char a = 'A', b = 'B';
    char_seq_stack_push(stack, &a);
    char_seq_stack_push(stack, &b);

    char val;
    assert(char_seq_stack_peek(stack, &val) == 0);
    assert(val == b); // 栈顶是 'B'

    assert(char_seq_stack_length(stack) == 2); // peek 不弹出

    char_seq_stack_destroy(&stack);
}

void test_empty_stack_operations() {
    CharSeqStack *stack = char_seq_stack_create();

    char val = '1';
    assert(char_seq_stack_pop(stack, &val) == -1);  // 空栈弹出失败
    assert(char_seq_stack_peek(stack, &val) == -1); // 空栈获取栈顶失败
    assert(char_seq_stack_empty(stack) == true);

    char_seq_stack_destroy(&stack);
}

void test_pop_null_elem() {
    CharSeqStack *stack = char_seq_stack_create();

    char val1 = 'a';
    char_seq_stack_push(stack, &val1);

    // pop 时 elem 为 NULL 应该也成功
    assert(char_seq_stack_pop(stack, NULL) == 0);
    assert(char_seq_stack_empty(stack) == true);

    char_seq_stack_destroy(&stack);
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