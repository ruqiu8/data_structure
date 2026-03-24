//
// Created by ruqiu on 2026/3/19.
//
#include <stdio.h>
#include <stdlib.h>

#include "seqlist.h"

// 辅助函数：比较两个元素是否相等
int compare_int(const ElemType* a, const ElemType* b) {
    return (*a == *b) ? 0 : -1;
}

// 辅助函数：打印单个元素
void print_int(const ElemType* e) {
    printf("%d", *e);
}

int main()
{
    // 创建顺序表
    SeqList* seq_list = (SeqList*)malloc(sizeof(SeqList));
    if (seq_list == NULL) {
        printf("内存分配失败\n");
        return -1;
    }

    // 初始化
    if (seq_list_init(seq_list) == 0) {
        printf("顺序表初始化成功，当前容量: %zu\n", seq_list->capacity);
    } else {
        printf("顺序表初始化失败\n");
        free(seq_list);
        return -1;
    }

    // 插入元素
    printf("插入元素 10, 20, 30, 40, 50, 60\n");
    for (size_t i = 1; i <= 6; i++) {
        ElemType elem = i * 10;
        seq_list_insert_elem(seq_list, i, &elem);
    }
    seq_list_print_list(seq_list, print_int);

    // 获取长度
    size_t length;
    seq_list_length(seq_list, &length);
    printf("当前长度: %zu, 当前容量: %zu\n", length, seq_list->capacity);

    // 判断是否为空
    bool is_empty;
    seq_list_empty(seq_list, &is_empty);
    printf("顺序表是否为空: %s\n", is_empty ? "是" : "否");

    // 获取特定位置元素
    ElemType elem;
    if (seq_list_get_elem(seq_list, 3, &elem) == 0) {
        printf("第 3 个位置的元素是: %d\n", elem);
    }

    // 查找元素位置
    ElemType target = 40;
    size_t pos;
    if (seq_list_locate_elem(seq_list, &target, compare_int, &pos) == 0) {
        printf("元素 %d 在表中的位序为: %zu\n", target, pos);
    }

    // 查找不存在的元素
    target = 100;
    if (seq_list_locate_elem(seq_list, &target, compare_int, &pos) != 0) {
        printf("元素 %d 不存在\n", target);
    }

    // 删除元素
    printf("删除第 2 个位置的元素: ");
    if (seq_list_delete_elem(seq_list, 2, &elem) == 0) {
        printf("%d\n", elem);
    }
    seq_list_print_list(seq_list, print_int);

    // 再次获取长度
    seq_list_length(seq_list, &length);
    printf("当前长度: %zu, 当前容量: %zu\n", length, seq_list->capacity);

    // 删除最后一个元素
    printf("删除最后一个位置元素: ");
    seq_list_length(seq_list, &length);
    if (seq_list_delete_elem(seq_list, length, &elem) == 0) {
        printf("%d\n", elem);
    }
    seq_list_print_list(seq_list, print_int);

    // 在头部插入
    printf("在头部插入元素 5\n");
    elem = 5;
    seq_list_insert_elem(seq_list, 1, &elem);
    seq_list_print_list(seq_list, print_int);

    // 在尾部插入
    printf("在尾部插入元素 70\n");
    seq_list_length(seq_list, &length);
    elem = 70;
    seq_list_insert_elem(seq_list, length + 1, &elem);
    seq_list_print_list(seq_list, print_int);

    // 销毁
    seq_list_destroy(seq_list);
    printf("顺序表已销毁\n");
    free(seq_list);

    return 0;
}
