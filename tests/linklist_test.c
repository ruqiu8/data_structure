#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "linklist.h"

int int_comparer(const ElemType *a, const ElemType *b) {
    return (*a) - (*b);
}

void int_printer(const ElemType *a) {
    printf("%d", *a);
}

void test_init_and_empty() {
    LinkList list = link_list_create();
    assert(list != NULL);
    assert(link_list_empty(list) == true);
    assert(link_list_length(list) == 0);

    link_list_destroy(&list);
    assert(list == NULL);
}

void test_insert() {
    LinkList list = link_list_create();

    int a = 1, b = 2, c = 3;

    assert(link_list_insert_elem(list, 0, &a) == 0); // [1]
    assert(link_list_insert_elem(list, 1, &b) == 0); // [1,2]
    assert(link_list_insert_elem(list, 1, &c) == 0); // [1,3,2]

    assert(link_list_length(list) == 3);

    int val;
    link_list_get_elem(list, 0, &val);
    assert(val == 1);

    link_list_get_elem(list, 1, &val);
    assert(val == 3);

    link_list_get_elem(list, 2, &val);
    assert(val == 2);

    link_list_destroy(&list);
}

void test_delete() {
    LinkList list = link_list_create();

    int a = 10, b = 20, c = 30;
    link_list_insert_elem(list, 0, &a);
    link_list_insert_elem(list, 1, &b);
    link_list_insert_elem(list, 2, &c);

    int deleted;
    assert(link_list_delete_elem(list, 1, &deleted) == 0);
    assert(deleted == 20);

    assert(link_list_length(list) == 2);

    int val;
    link_list_get_elem(list, 1, &val);
    assert(val == 30);

    link_list_destroy(&list);
}

void test_locate() {
    LinkList list = link_list_create();

    int a = 5, b = 10, c = 15;
    link_list_insert_elem(list, 0, &a);
    link_list_insert_elem(list, 1, &b);
    link_list_insert_elem(list, 2, &c);

    size_t index = link_list_locate_elem(list, &b, int_comparer);
    assert(index == 1);

    int x = 100;
    index = link_list_locate_elem(list, &x, int_comparer);
    assert(index == SIZE_MAX);

    link_list_destroy(&list);
}

void test_out_of_bounds() {
    LinkList list = link_list_create();

    int val;
    assert(link_list_get_elem(list, 0, &val) == -1);

    int a = 1;
    assert(link_list_insert_elem(list, 5, &a) == -1);

    assert(link_list_delete_elem(list, 0, NULL) == -1);

    link_list_destroy(&list);
}

void test_create_head() {
    LinkList list = link_list_create();

    int arr[] = {1, 2, 3};
    assert(link_list_create_head(list, arr, 3) == 0);

    // 头插法：顺序是逆序的 [3, 2, 1]
    assert(link_list_length(list) == 3);

    int val;
    link_list_get_elem(list, 0, &val);
    assert(val == 3);

    link_list_get_elem(list, 1, &val);
    assert(val == 2);

    link_list_get_elem(list, 2, &val);
    assert(val == 1);

    link_list_destroy(&list);
}

void test_create_tail() {
    LinkList list = link_list_create();

    int arr[] = {1, 2, 3};
    assert(link_list_create_tail(list, arr, 3) == 0);

    // 尾插法：顺序是原序的 [1, 2, 3]
    assert(link_list_length(list) == 3);

    int val;
    link_list_get_elem(list, 0, &val);
    assert(val == 1);

    link_list_get_elem(list, 1, &val);
    assert(val == 2);

    link_list_get_elem(list, 2, &val);
    assert(val == 3);

    link_list_destroy(&list);
}

void test_print() {
    LinkList list = link_list_create();

    int a = 10, b = 20, c = 30;
    link_list_insert_elem(list, 0, &a);
    link_list_insert_elem(list, 1, &b);
    link_list_insert_elem(list, 2, &c);

    printf("Testing print: ");
    link_list_print_list(list, int_printer);

    link_list_destroy(&list);
}

int main() {
    test_init_and_empty();
    test_insert();
    test_delete();
    test_locate();
    test_out_of_bounds();
    test_create_head();
    test_create_tail();
    test_print();

    printf("All tests passed!\n");
    return 0;
}