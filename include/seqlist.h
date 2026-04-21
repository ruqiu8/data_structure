//
// Created by ruqiu on 2026/3/19.
//

#ifndef DATA_STRUCTURE_SEQLIST_H
#define DATA_STRUCTURE_SEQLIST_H
// 顺序表默认初始容量
#define SEQ_LIST_DEFAULT_CAPACITY 10
#include <stdbool.h>
#include <stddef.h>

// 顺序表的类型，这里是 int
typedef int ElemType;

// 比较两个数据元素的函数，相等返回0
typedef int (*Comparer)(const ElemType *elem1, const ElemType *elem2);

// 打印 ElemType 不要换行
typedef void (*PrintElem)(const ElemType *);

// 顺序表结构体
typedef struct {
    ElemType *data;     // 指向动态数组的指针
    size_t    length;   // 当前有效元素的个数
    size_t    capacity; // 数组的总容量
} SeqList;

// 创建一个顺序表
extern SeqList *seq_list_create();

// 获取顺序表现有的元素个数
extern size_t seq_list_length(SeqList *seq_list);

// 判断顺序表是否为空
extern bool seq_list_empty(SeqList *seq_list);

// 在顺序表中查找第一个与指定元素匹配的索引
extern size_t seq_list_locate_elem(SeqList *seq_list, ElemType *elem, Comparer comparer);

// 根据索引获取顺序表中的元素
extern int seq_list_get_elem(SeqList *seq_list, size_t index, ElemType *elem);

// 在指定索引位置插入新元素
extern int seq_list_insert_elem(SeqList *seq_list, size_t index, const ElemType *elem);

// 删除指定索引的元素
extern int seq_list_delete_elem(SeqList *seq_list, size_t index, ElemType *elem);

// 打印顺序表
extern void seq_list_print_list(SeqList *seq_list, PrintElem print_elem);

// 销毁顺序表
extern void seq_list_destroy(SeqList **seq_list);

#endif // DATA_STRUCTURE_SEQLIST_H