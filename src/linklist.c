//
// Created by ruqiu on 2026/3/23.
//
#include "linklist.h"

#include <stdio.h>
#include <stdlib.h>

int link_list_init(LinkList link_list)
{
    if (link_list == NULL) return -1;
    link_list->length = 0;
    link_list->head = NULL;
    return 0;
}

int link_list_length(LinkList link_list, size_t *length)
{
    if (link_list == NULL) return -1;
    *length = link_list->length;
    return 0;
}

int link_list_empty(LinkList link_list, bool* is_empty)
{
    if (link_list == NULL) return -1;
    *is_empty =  link_list->length == 0;
    return 0;
}

int link_list_get_elem(LinkList link_list, size_t index, LNode** node)
{
    if (link_list == NULL || index < 1 || index > link_list->length) {
        return -1;
    }

    LNode* p = link_list->head;
    for (size_t i = 1; i < index; i++) {
        p = p->next;
    }
    *node = p;
    return 0;
}

int link_list_locate_elem(LinkList link_list, const ElemType* elem, Comparer comparer, size_t* index)
{
    if (link_list == NULL || elem == NULL || comparer == NULL || index == NULL) {
        return -1;
    }

    LNode* node = link_list->head;

    for (size_t i = 1;i <= link_list->length; i++)
    {
        if (comparer(&(node->data), elem) == 0) {
            *index = i;  // 将找到的索引写入指针
            return 0;    // 返回成功
        }
        node = node->next;
    }
    return -1;
}

int link_list_insert_elem(LinkList link_list, size_t index, const ElemType* elem)
{
    if (link_list == NULL || elem == NULL) {
        return -1;
    }
    if (index < 1 || index > link_list->length + 1) {
        return -1;
    }

    // 创建新节点
    LNode* new_node = (LNode*)malloc(sizeof(LNode));
    if (new_node == NULL) {
        return -1;  // 内存分配失败
    }
    new_node->data = *elem;
    new_node->next = NULL;

    // 在头部插入（index = 1）
    if (index == 1) {
        new_node->next = link_list->head;
        link_list->head = new_node;
    } else {
        // 找到第 index-1 个节点
        LNode* prev = link_list->head;
        for (size_t i = 1; i < index - 1; i++) {
            prev = prev->next;
        }
        // 在第 index-1 个节点后插入
        new_node->next = prev->next;
        prev->next = new_node;
    }

    link_list->length++;
    return 0;
}

int link_list_delete_elem(LinkList link_list, size_t index, ElemType* elem)
{
    if (link_list == NULL) {
        return -1;
    }
    if (index < 1 || index > link_list->length) {
        return -1;
    }

    LNode* to_delete;

    // 删除第一个节点
    if (index == 1) {
        to_delete = link_list->head;
        link_list->head = to_delete->next;
    } else {
        // 找到第 index-1 个节点
        LNode* prev = link_list->head;
        for (size_t i = 1; i < index - 1; i++) {
            prev = prev->next;
        }
        // 要删除的节点是第 index 个节点
        to_delete = prev->next;
        prev->next = to_delete->next;
    }

    if (elem != NULL)
    {
        // 保存被删除元素的数据
        *elem = to_delete->data;
    }
    // 释放节点内存
    free(to_delete);
    link_list->length--;
    return 0;
}

int link_list_print_list(LinkList link_list, PrintElem print_elem)
{
    if (link_list == NULL  || print_elem == NULL) {
        return -1;
    }

    printf("[");
    // 处理空表
    if (link_list->length == 0) {
        printf("]\n");
        return 0;
    }

    // 遍历打印元素
    LNode* node = link_list->head;
    for (size_t i = 0; i < link_list->length; i++) {
        print_elem(&node->data);
        // 元素之间添加逗号分隔
        if (i != link_list->length - 1) {
            printf(", ");
        }
        node = node->next;
    }
    printf("]\n");
    return 0;
}

int link_list_destroy(LinkList link_list)
{
    if (link_list == NULL) return -1;

    LNode* node = link_list->head;
    for (size_t i = 1;i <= link_list->length;i++)
    {
        LNode* next = node->next;
        free(node);
        node = next;
    }
    link_list->length = 0;
    link_list->head = NULL;
    return 0;
}