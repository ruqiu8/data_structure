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
    SeqList* seq_list = (SeqList*)malloc(sizeof(SeqList));
    ElemType temp;
    seq_list_init(seq_list);
    // 初始化
    if (seq_list_init(seq_list) == 0) {
        printf("顺序表初始化成功，当前容量: %d\n", seq_list->capacity);
    }

    // 插入元素
    printf("插入元素 10, 20, 30, 40, 50, 60\n");
    for (int i = 1; i <= 6; i++) {
        seq_list_insert_elem(seq_list, i, i * 10);
    }
    seq_list_print_list(seq_list, print_int);
    printf("当前长度: %d, 当前容量: %d\n", seq_list_length(seq_list), seq_list->capacity);

    // 获取特定位置元素
    if (seq_list_get_elem(seq_list, 3, &temp) == 0) {
        printf("第 3 个位置的元素是: %d\n", temp);
    }

    // 查找元素位置
    ElemType target = 40;
    int pos = seq_list_locate_elem(seq_list, target, compare_int);
    if (pos != -1) {
        printf("元素 %d 在表中的位序为: %d\n", target, pos);
    }

    // 删除元素
    printf("删除第 2 个位置的元素");
    if (seq_list_delete_elem(seq_list, 2, &temp) == 0) {
        printf("被删除的元素是: %d\n", temp);
    }
    seq_list_print_list(seq_list, print_int);

    // 销毁
    seq_list_destroy(seq_list);
    printf("顺序表已销毁\n");
    free(seq_list);
    return 0;
}
