#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "seqlist.h"

int int_comparer(const ElemType *a, const ElemType *b) {
    return (*a) - (*b);
}

void int_printer(const ElemType *a) {
    printf("%d", *a);
}

void test_create_and_empty() {
    SeqList *list = seq_list_create();
    assert(list != NULL);
    assert(seq_list_empty(list) == true);
    assert(seq_list_length(list) == 0);

    seq_list_destroy(&list);
    assert(list == NULL);
}

void test_insert() {
    SeqList *list = seq_list_create();

    int a = 1, b = 2, c = 3;

    assert(seq_list_insert_elem(list, 0, &a) == 0); // [1]
    assert(seq_list_insert_elem(list, 1, &b) == 0); // [1,2]
    assert(seq_list_insert_elem(list, 1, &c) == 0); // [1,3,2]

    assert(seq_list_length(list) == 3);

    int val;
    seq_list_get_elem(list, 0, &val);
    assert(val == 1);

    seq_list_get_elem(list, 1, &val);
    assert(val == 3);

    seq_list_get_elem(list, 2, &val);
    assert(val == 2);

    seq_list_destroy(&list);
}

void test_delete() {
    SeqList *list = seq_list_create();

    int a = 10, b = 20, c = 30;
    seq_list_insert_elem(list, 0, &a);
    seq_list_insert_elem(list, 1, &b);
    seq_list_insert_elem(list, 2, &c);

    int deleted;
    assert(seq_list_delete_elem(list, 1, &deleted) == 0);
    assert(deleted == 20);

    assert(seq_list_length(list) == 2);

    int val;
    seq_list_get_elem(list, 1, &val);
    assert(val == 30);

    seq_list_destroy(&list);
}

void test_locate() {
    SeqList *list = seq_list_create();

    int a = 5, b = 10, c = 15;
    seq_list_insert_elem(list, 0, &a);
    seq_list_insert_elem(list, 1, &b);
    seq_list_insert_elem(list, 2, &c);

    size_t index = seq_list_locate_elem(list, &b, int_comparer);
    assert(index == 1);

    int x = 100;
    index = seq_list_locate_elem(list, &x, int_comparer);
    assert(index == SIZE_MAX);

    seq_list_destroy(&list);
}

void test_out_of_bounds() {
    SeqList *list = seq_list_create();

    int val;
    assert(seq_list_get_elem(list, 0, &val) == -1);

    int a = 1;
    assert(seq_list_insert_elem(list, 5, &a) == -1);

    assert(seq_list_delete_elem(list, 0, NULL) == -1);

    seq_list_destroy(&list);
}

int main() {
    test_create_and_empty();
    test_insert();
    test_delete();
    test_locate();
    test_out_of_bounds();

    printf("All tests passed!\n");
    return 0;
}