#ifndef DATA_STRUCTURE_LINKLIST_H
#define DATA_STRUCTURE_LINKLIST_H

#include <stdbool.h>
#include <stddef.h>

// 数据元素类型定义
typedef int ElemType;

// 比较函数指针
typedef int (*Comparer)(const ElemType *elem1, const ElemType *elem2);

// 打印函数指针
typedef void (*PrintElem)(const ElemType *);

typedef struct LNode {
    ElemType      data; // 数据域
    struct LNode *next; // 指针域
} LNode, *LinkList;

// 创建一个头节点
extern LinkList link_list_create();

// 获取有效元素个数(不含头节点)
extern size_t link_list_length(LinkList L);

// 判断链表是否为空
extern bool link_list_empty(LinkList L);

// 在链表中查找第一个与指定元素匹配的索引
// 索引从0开始，0表示第一个元素节点
extern size_t link_list_locate_elem(LinkList L, const ElemType *elem, Comparer comparer);

// 获取链表中指定索引的元素
// 索引从0开始，0表示第一个元素节点
extern int link_list_get_elem(LinkList L, size_t index, ElemType *elem);

// 在链表指定的索引插入元素 elem
// 索引从0开始，0表示第一个元素节点
extern int link_list_insert_elem(LinkList L, size_t index, const ElemType *elem);

// 删除链表中指定索引的节点
extern int link_list_delete_elem(LinkList L, size_t index, ElemType *elem);

// 遍历打印链表
extern void link_list_print_list(LinkList L, PrintElem print_elem);

// 销毁链表
extern void link_list_destroy(LinkList *L);

// 头插法建立单链表
extern int link_list_create_head(LinkList L, const ElemType *elem, size_t length);

// 尾插法建立单链表
extern int link_list_create_tail(LinkList L, const ElemType *elem, size_t length);

#endif // DATA_STRUCTURE_LINKLIST_H