#include "seqlist.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

SeqList *seq_list_create() {
    SeqList *seq_list = (SeqList *) malloc(sizeof(SeqList));
    if (seq_list == NULL) {
        return NULL;
    }

    seq_list->data = (ElemType *) malloc(sizeof(ElemType) * SEQ_LIST_DEFAULT_CAPACITY);
    if (seq_list->data == NULL) {
        free(seq_list);
        return NULL;
    }

    seq_list->length   = 0;
    seq_list->capacity = SEQ_LIST_DEFAULT_CAPACITY;

    return seq_list;
}

size_t seq_list_length(SeqList *seq_list) {
    assert(seq_list != NULL);
    return seq_list->length;
}

bool seq_list_empty(SeqList *seq_list) {
    assert(seq_list != NULL);
    return seq_list->length == 0;
}

size_t seq_list_locate_elem(SeqList *seq_list, ElemType *elem, Comparer comparer) {
    assert(seq_list != NULL && comparer != NULL && elem != NULL);

    for (size_t i = 0; i < seq_list->length; i++) {
        if (comparer(elem, &seq_list->data[i]) == 0) {
            return i;
        }
    }
    return SIZE_MAX;
}

int seq_list_get_elem(SeqList *seq_list, size_t index, ElemType *elem) {
    assert(seq_list != NULL);

    if (index >= seq_list->length) {
        return -1;
    }

    *elem = seq_list->data[index];
    return 0;
}

int seq_list_grow_list(SeqList *seq_list) {
    assert(seq_list != NULL);
    size_t    new_capacity = (seq_list->capacity == 0) ? 10 : seq_list->capacity * 2;
    ElemType *new_data     = (ElemType *) realloc(seq_list->data, new_capacity * sizeof(ElemType));

    if (new_data == NULL) {
        return -1;
    }
    seq_list->data     = new_data;
    seq_list->capacity = new_capacity;

    return 0;
}

int seq_list_insert_elem(SeqList *seq_list, size_t index, const ElemType *elem) {
    assert(seq_list != NULL && elem != NULL);

    if (index > seq_list->length) {
        return -1;
    }

    if (seq_list->length >= seq_list->capacity) {
        if (seq_list_grow_list(seq_list) != 0) {
            return -1;
        }
    }

    for (size_t i = seq_list->length; i > index; i--) {
        seq_list->data[i] = seq_list->data[i - 1];
    }
    seq_list->data[index] = *elem;
    seq_list->length++;
    return 0;
}

int seq_list_delete_elem(SeqList *seq_list, size_t index, ElemType *elem) {
    assert(seq_list != NULL);

    if (index >= seq_list->length) {
        return -1;
    }

    if (elem != NULL) {
        *elem = seq_list->data[index];
    }

    for (size_t i = index; i < seq_list->length - 1; i++) {
        seq_list->data[i] = seq_list->data[i + 1];
    }

    seq_list->length--;

    return 0;
}

void seq_list_destroy(SeqList **seq_list) {
    assert(seq_list != NULL);

    if (*seq_list == NULL) {
        return;
    }

    free((*seq_list)->data);
    free(*seq_list);

    *seq_list = NULL;
}

void seq_list_print_list(SeqList *seq_list, PrintElem print_elem) {
    assert(seq_list != NULL && seq_list->data != NULL && print_elem != NULL);

    printf("[");
    if (seq_list->length == 0) {
        printf("]\n");
        return;
    }

    for (size_t i = 0; i < seq_list->length; i++) {
        print_elem(&seq_list->data[i]);
        if (i != seq_list->length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}