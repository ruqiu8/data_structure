//
// Created by ruqiu on 2026/4/10.
//

#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

#include "seqlist.h"

typedef struct
{
    SeqList* seq_list;
} Stack;

extern int stack_init(Stack* stack);
extern int stack_empty(Stack* stack, bool* is_empty);
extern int stack_push(Stack* stack, ElemType* elem);
extern int stack_pop(Stack* stack, ElemType* elem);
extern int stack_get_top(Stack* stack, ElemType* elem);
extern int stack_destroy(Stack* stack);
extern int stack_length(Stack* stack, size_t* length);
extern int stack_print(Stack* stack, PrintElem print_elem);
#endif //DATA_STRUCTURE_STACK_H