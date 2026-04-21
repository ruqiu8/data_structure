#include "char_seq_stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

CharSeqStack *char_seq_stack_create() {
    CharSeqStack *stack = (CharSeqStack *) malloc(sizeof(CharSeqStack));
    if (stack == NULL) {
        return NULL;
    }

    stack->data = (ElemType *) malloc(sizeof(ElemType) * CHAR_SEQ_STACK_DEFAULT_CAPACITY);
    if (stack->data == NULL) {
        free(stack);
        return NULL;
    }

    stack->top      = 0;
    stack->capacity = CHAR_SEQ_STACK_DEFAULT_CAPACITY;

    return stack;
}

bool char_seq_stack_empty(CharSeqStack *stack) {
    assert(stack != NULL);
    return stack->top == 0;
}

size_t char_seq_stack_length(CharSeqStack *stack) {
    assert(stack != NULL);
    return stack->top;
}

static int char_seq_stack_grow(CharSeqStack *stack) {
    assert(stack != NULL);
    size_t    new_capacity = stack->capacity * 2;
    ElemType *new_data     = (ElemType *) realloc(stack->data, new_capacity * sizeof(ElemType));

    if (new_data == NULL) {
        return -1;
    }
    stack->data     = new_data;
    stack->capacity = new_capacity;

    return 0;
}

int char_seq_stack_push(CharSeqStack *stack, const ElemType *elem) {
    assert(stack != NULL && elem != NULL);

    if (stack->top >= stack->capacity) {
        if (char_seq_stack_grow(stack) != 0) {
            return -1;
        }
    }

    stack->data[stack->top] = *elem;
    stack->top++;

    return 0;
}

int char_seq_stack_pop(CharSeqStack *stack, ElemType *elem) {
    assert(stack != NULL);

    if (stack->top == 0) {
        return -1;
    }

    stack->top--;
    if (elem != NULL) {
        *elem = stack->data[stack->top];
    }

    return 0;
}

int char_seq_stack_peek(CharSeqStack *stack, ElemType *elem) {
    assert(stack != NULL && elem != NULL);

    if (stack->top == 0) {
        return -1;
    }

    *elem = stack->data[stack->top - 1];

    return 0;
}

void char_seq_stack_print(CharSeqStack *stack) {
    assert(stack != NULL && stack->data != NULL);

    printf("Stack bottom to top: [");
    if (stack->top == 0) {
        printf("]\n");
        return;
    }

    for (size_t i = 0; i < stack->top; i++) {
        printf("%c", stack->data[i]);
        if (i != stack->top - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void char_seq_stack_destroy(CharSeqStack **stack) {
    assert(stack != NULL);

    if (*stack == NULL) {
        return;
    }

    free((*stack)->data);
    free(*stack);

    *stack = NULL;
}