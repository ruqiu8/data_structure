#include "seqlist.h"

#include <stdio.h>
#include <stdlib.h>

int seq_list_init(SeqList* list)
{
    if (list == NULL) return -1;
    list->data = (ElemType*) malloc(sizeof(ElemType) * SEQ_LIST_DEFAULT_CAPACITY);
    if (list->data == NULL) return -1;
    list->length = 0;
    list->capacity = SEQ_LIST_DEFAULT_CAPACITY;
    return 0;
}

int seq_list_length(const SeqList* seq_list)
{
    if (seq_list == NULL) return -1;
    return seq_list->length;
}

int seq_list_empty(const SeqList* seq_list)
{
    if (seq_list == NULL) return -1;
    return seq_list->length == 0;
}

int seq_list_locate_elem(const SeqList* seq_list, ElemType elem, Operation operation)
{
    if (seq_list == NULL || seq_list->length == 0 || operation == NULL) {
        return -1;
    }

    for (int i = 0; i < seq_list->length; i++)
    {
        if (operation(&elem, &seq_list->data[i]) == 0)
        {
            return i + 1;
        }
    }
    return -1;
}

int seq_list_get_elem(const SeqList* seq_list, int index, ElemType* elem)
{
    if (seq_list == NULL) return -1;

    if (index < 1 || index > seq_list->length)
    {
        return -1;
    }

    *elem = seq_list->data[index - 1];
    return 0;
}

int seq_list_grow_list(SeqList* seq_list)
{
    if (seq_list == NULL) return -1;
    int new_capacity = (seq_list->capacity == 0) ? 10 : seq_list->capacity * 2;
    ElemType* new_data = (ElemType*)realloc(seq_list->data, new_capacity * sizeof(ElemType));

    if (new_data == NULL) return -1;

    seq_list->data = new_data;
    seq_list->capacity = new_capacity;

    return 0;
}

int seq_list_insert_elem(SeqList* seq_list, int index, ElemType elem)
{
    if (seq_list == NULL) return -1;

    if (index < 1 || index > seq_list->length+1)
    {
        return -1;
    }

    if (seq_list->length >= seq_list->capacity) {
        if (seq_list_grow_list(seq_list) != 0) {
            return -1;
        }
    }

    for (int i = seq_list->length; i >= index; i--) {
        seq_list->data[i] = seq_list->data[i - 1];
    }
    seq_list->data[index-1] = elem;
    seq_list->length++;
    return 0;
}

int seq_list_delete_elem(SeqList* seq_list, int index, ElemType* elem)
{
    if (seq_list == NULL) {
        return -1;
    }

    if (index < 1 || index > seq_list->length)
    {
        return -1;
    }

    if (elem != NULL) {
        *elem = seq_list->data[index - 1];
    }

    for (int i = index; i < seq_list->length; i++) {
        seq_list->data[i - 1] = seq_list->data[i];
    }

    seq_list->length--;

    return 0;
}

int seq_list_destroy(SeqList* seq_list)
{
    if (seq_list == NULL) return -1;

    if (seq_list->data != NULL) {
        free(seq_list->data);
        seq_list->data = NULL;
    }

    seq_list->length = 0;
    seq_list->capacity = 0;

    return 0;
}

int seq_list_print_list(const SeqList* seq_list, PrintElem print_elem)
{
    if (seq_list == NULL || seq_list->data == NULL || print_elem == NULL) {
        return -1;
    }

    printf("[");
    // 处理空表
    if (seq_list->length == 0) {
        printf("]\n");
        return 0;
    }

    // 遍历打印元素
    for (int i = 0; i < seq_list->length; i++) {
        print_elem(&seq_list->data[i]);
        // 元素之间添加逗号分隔
        if (i != seq_list->length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    return 0;
}
