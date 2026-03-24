#include "seqlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int seq_list_init(SeqList* seq_list)
{
    if (seq_list == NULL) return -1;
    seq_list->data = (ElemType*) malloc(sizeof(ElemType) * SEQ_LIST_DEFAULT_CAPACITY);
    if (seq_list->data == NULL) return -1;
    seq_list->length = 0;
    seq_list->capacity = SEQ_LIST_DEFAULT_CAPACITY;
    return 0;
}

int seq_list_length(const SeqList* seq_list, size_t* length)
{
    if (seq_list == NULL || length == NULL) return -1;
    *length = seq_list->length;
    return 0;
}

int seq_list_empty(const SeqList* seq_list, bool* is_empty)
{
    if (seq_list == NULL || is_empty == NULL) return -1;
    *is_empty = seq_list->length == 0;
    return 0;
}

int seq_list_locate_elem(const SeqList* seq_list, const ElemType* elem, Comparer comparer, size_t* index)
{
    if (seq_list == NULL || elem == NULL || comparer == NULL || index == NULL) return -1;

    for (size_t i = 0; i < seq_list->length; i++)
    {
        if (comparer(elem, &seq_list->data[i]) == 0)
        {
            *index = i + 1;
            return 0;
        }
    }
    return -1;
}

int seq_list_get_elem(const SeqList* seq_list, size_t index, ElemType* elem)
{
    if (seq_list == NULL) return -1;

    if (index < 1 || index > seq_list->length)
    {
        return -1;
    }

    if (elem == NULL) return -1;
    *elem = seq_list->data[index - 1];
    return 0;
}

int seq_list_grow_list(SeqList* seq_list)
{
    if (seq_list == NULL) return -1;
    size_t new_capacity = (seq_list->capacity == 0) ? 10 : seq_list->capacity * 2;
    ElemType* new_data = (ElemType*)realloc(seq_list->data, new_capacity * sizeof(ElemType));

    if (new_data == NULL) return -1;

    seq_list->data = new_data;
    seq_list->capacity = new_capacity;

    return 0;
}

int seq_list_insert_elem(SeqList* seq_list, size_t index, const ElemType* elem)
{
    if (seq_list == NULL || elem == NULL) return -1;

    if (index < 1 || index > seq_list->length + 1)
    {
        return -1;
    }

    if (seq_list->length >= seq_list->capacity) {
        if (seq_list_grow_list(seq_list) != 0) {
            return -1;
        }
    }

    for (size_t i = seq_list->length; i >= index; i--) {
        seq_list->data[i] = seq_list->data[i - 1];
    }
    seq_list->data[index-1] = *elem;
    seq_list->length++;
    return 0;
}

int seq_list_delete_elem(SeqList* seq_list, size_t index, ElemType* elem)
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

    for (size_t i = index; i < seq_list->length; i++) {
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
    for (size_t i = 0; i < seq_list->length; i++) {
        print_elem(&seq_list->data[i]);
        // 元素之间添加逗号分隔
        if (i != seq_list->length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    return 0;
}
