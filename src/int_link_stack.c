#include "int_link_stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

IntLinkStack *int_link_stack_create() {
    IntLinkStack *stack = (IntLinkStack *) malloc(sizeof(IntLinkStack));
    if (stack == NULL) {
        return NULL;
    }

    stack->top  = NULL;
    stack->size = 0;

    return stack;
}

bool int_link_stack_empty(IntLinkStack *stack) {
    assert(stack != NULL);
    return stack->size == 0;
}

size_t int_link_stack_length(IntLinkStack *stack) {
    assert(stack != NULL);
    return stack->size;
}

int int_link_stack_push(IntLinkStack *stack, const IntElemType *elem) {
    assert(stack != NULL && elem != NULL);

    StackNode *new_node = (StackNode *) malloc(sizeof(StackNode));
    if (new_node == NULL) {
        return -1;
    }

    new_node->data = *elem;
    new_node->next = stack->top;
    stack->top     = new_node;
    stack->size++;

    return 0;
}

int int_link_stack_pop(IntLinkStack *stack, IntElemType *elem) {
    assert(stack != NULL);

    if (stack->size == 0) {
        return -1;
    }

    StackNode *top_node = stack->top;

    if (elem != NULL) {
        *elem = top_node->data;
    }

    stack->top = top_node->next;
    free(top_node);
    stack->size--;

    return 0;
}

int int_link_stack_peek(IntLinkStack *stack, IntElemType *elem) {
    assert(stack != NULL && elem != NULL);

    if (stack->size == 0) {
        return -1;
    }

    *elem = stack->top->data;

    return 0;
}

void int_link_stack_print(IntLinkStack *stack) {
    assert(stack != NULL);

    printf("Stack top to bottom: [");
    if (stack->size == 0) {
        printf("]\n");
        return;
    }

    StackNode *p = stack->top;
    while (p) {
        printf("%d", p->data);
        if (p->next) {
            printf(", ");
        }
        p = p->next;
    }
    printf("]\n");
}

void int_link_stack_destroy(IntLinkStack **stack) {
    assert(stack != NULL);

    if (*stack == NULL) {
        return;
    }

    StackNode *p = (*stack)->top;
    while (p) {
        StackNode *temp = p;
        p               = p->next;
        free(temp);
    }

    free(*stack);
    *stack = NULL;
}