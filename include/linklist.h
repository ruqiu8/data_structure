//
// Created by ruqiu on 2026/3/23.
//

#ifndef DATA_STRUCTURE_LINKLIST_H
#define DATA_STRUCTURE_LINKLIST_H
#include <stdbool.h>
#include <stddef.h>

// 单链表的类型，这里是 int
typedef int ElemType;

// 比较两个数据元素的函数，相等返回0
typedef int (*Comparer)(const ElemType* elem1, const ElemType* elem2);

// 打印 ElemType 不要换行
typedef void (*PrintElem)(const ElemType*);

// 单链表数据节点
typedef struct LNode {
    ElemType data;           // 数据域
    struct LNode* next; // 指针域
} LNode;

// 头节点
typedef struct
{
    size_t length;
    LNode* head;
} LinkListHeader;

typedef LinkListHeader* LinkList;

extern int link_list_init(LinkList link_list);
extern int link_list_length(LinkList link_list, size_t *length);
extern int link_list_empty(LinkList link_list, bool* is_empty);
extern int link_list_get_elem(LinkList link_list, size_t index, LNode** node);
extern int link_list_locate_elem(LinkList link_list, const ElemType* elem, Comparer comparer, size_t* index);
extern int link_list_insert_elem(LinkList link_list, size_t index, const ElemType* elem);
extern int link_list_delete_elem(LinkList link_list, size_t index, ElemType* elem);
extern int link_list_print_list(LinkList link_list, PrintElem print_elem);
extern int link_list_destroy(LinkList link_list);
#endif //DATA_STRUCTURE_LINKLIST_H
