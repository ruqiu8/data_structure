//
// Created by ruqiu on 2026/4/10.
//
#include "stack.h"

#include <stdlib.h>

int stack_init(Stack* stack)
{
    if (stack == NULL) return -1;
    SeqList* seq_list = (SeqList*)malloc(sizeof(SeqList));
    if (seq_list == NULL) return -1;
    if (seq_list_init(seq_list) != 0)
    {
        free(seq_list);
        return -1;
    }
    stack->seq_list = seq_list;
    return 0;
}

int stack_empty(Stack* stack, bool* is_empty)
{
    if (stack == NULL) return -1;
    return seq_list_empty(stack->seq_list, is_empty);
}

int stack_push(Stack* stack, ElemType* elem)
{
    if (stack == NULL || elem == NULL) return -1;
    return seq_list_insert_elem(stack->seq_list, stack->seq_list->length + 1, elem);
}

int stack_pop(Stack* stack, ElemType* elem)
{
    if (stack == NULL) return -1;
    return seq_list_delete_elem(stack->seq_list, stack->seq_list->length, elem);
}

int stack_get_top(Stack* stack, ElemType* elem)
{
    if (stack == NULL) return -1;

    return seq_list_get_elem(stack->seq_list, stack->seq_list->length, elem);
}

int stack_destroy(Stack* stack)
{
    if (stack == NULL) return -1;
    if (seq_list_destroy(stack->seq_list) != 0) return -1;
    free(stack->seq_list);
    return 0;
}

int stack_length(Stack* stack, size_t* length)
{
    if (stack == NULL) return -1;
    return  seq_list_length(stack->seq_list, length);
}

int stack_print(Stack* stack, PrintElem print_elem)
{
    if (stack == NULL) return -1;
    return seq_list_print_list(stack->seq_list, print_elem);
}
