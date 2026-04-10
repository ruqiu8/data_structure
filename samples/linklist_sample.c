//
// Created by ruqiu on 2026/3/24.
//
#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"

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
    // 创建链表头节点
    LinkList link_list = (LinkList)malloc(sizeof(*link_list));
    if (link_list == NULL) {
        printf("内存分配失败\n");
        return -1;
    }

    // 初始化
    if (link_list_init(link_list) == 0) {
        printf("链表初始化成功\n");
    } else {
        printf("链表初始化失败\n");
        free(link_list);
        return -1;
    }

    // 插入元素
    printf("插入元素 10, 20, 30, 40, 50, 60\n");
    for (size_t i = 1; i <= 6; i++) {
        ElemType elem = i * 10;
        link_list_insert_elem(link_list, i, &elem);
    }
    link_list_print_list(link_list, print_int);

    // 获取长度
    size_t length;
    link_list_length(link_list, &length);
    printf("当前长度: %zu\n", length);

    // 判断是否为空
    bool is_empty;
    link_list_empty(link_list, &is_empty);
    printf("链表是否为空: %s\n", is_empty ? "是" : "否");

    // 获取特定位置元素
    ElemType elem;
    if (link_list_get_elem(link_list, 3, &elem) == 0) {
        printf("第 3 个位置的元素是: %d\n", elem);
    }

    // 查找元素位置
    ElemType target = 40;
    size_t pos;
    if (link_list_locate_elem(link_list, &target, compare_int, &pos) == 0) {
        printf("元素 %d 在表中的位序为: %zu\n", target, pos);
    }

    // 查找不存在的元素
    target = 100;
    if (link_list_locate_elem(link_list, &target, compare_int, &pos) != 0) {
        printf("元素 %d 不存在\n", target);
    }

    // 删除元素
    printf("删除第 2 个位置的元素: ");
    if (link_list_delete_elem(link_list, 2, &elem) == 0) {
        printf("%d\n", elem);
    }
    link_list_print_list(link_list, print_int);

    // 再次获取长度
    link_list_length(link_list, &length);
    printf("当前长度: %zu\n", length);

    // 删除最后一个元素
    printf("删除最后一个位置元素: ");
    link_list_length(link_list, &length);
    if (link_list_delete_elem(link_list, length, &elem) == 0) {
        printf("%d\n", elem);
    }
    link_list_print_list(link_list, print_int);

    // 在头部插入
    printf("在头部插入元素 5\n");
    elem = 5;
    link_list_insert_elem(link_list, 1, &elem);
    link_list_print_list(link_list, print_int);

    // 在尾部插入
    printf("在尾部插入元素 70\n");
    link_list_length(link_list, &length);
    elem = 70;
    link_list_insert_elem(link_list, length + 1, &elem);
    link_list_print_list(link_list, print_int);

    // 销毁链表
    link_list_destroy(link_list);
    printf("链表已销毁\n");

    // 释放头节点内存
    free(link_list);

    // ========== 测试头插法建立链表 ==========
    printf("\n-------测试头插法建立链表-------\n");
    link_list = (LinkList)malloc(sizeof(*link_list));
    if (link_list == NULL) {
        printf("内存分配失败\n");
        return -1;
    }
    link_list_init(link_list);

    ElemType elems[] = {10, 20, 30, 40, 50};
    printf("使用头插法建立链表，原始数组: [10, 20, 30, 40, 50]\n");
    if (link_list_create_head_insert(link_list, elems, 5) == 0) {
        printf("头插法建立链表成功\n");
        link_list_print_list(link_list, print_int);
    } else {
        printf("头插法建立链表失败\n");
    }

    link_list_destroy(link_list);
    free(link_list);

    printf("\n-------测试尾插法建立链表-------\n");
    link_list = (LinkList)malloc(sizeof(*link_list));
    if (link_list == NULL) {
        printf("内存分配失败\n");
        return -1;
    }
    link_list_init(link_list);

    printf("使用尾插法建立链表，原始数组: [10, 20, 30, 40, 50]\n");
    if (link_list_create_tail_insert(link_list, elems, 5) == 0) {
        printf("尾插法建立链表成功\n");
        link_list_print_list(link_list, print_int);
    } else {
        printf("尾插法建立链表失败\n");
    }

    link_list_destroy(link_list);
    free(link_list);

    return 0;
}
