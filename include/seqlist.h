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
typedef int (*Comparer)(const ElemType* elem1, const ElemType* elem2);

// 打印 ElemType 不要换行
typedef void (*PrintElem)(const ElemType*);

// 顺序表结构体
typedef struct {
    ElemType* data;   // 指向动态数组的指针
    size_t length;       // 当前有效元素的个数
    size_t capacity;     // 数组的总容量
} SeqList;

extern int seq_list_init(SeqList* seq_list);
extern int seq_list_length(const SeqList* seq_list, size_t* length);
extern int seq_list_empty(const SeqList* seq_list, bool* is_empty);
extern int seq_list_locate_elem(const SeqList* seq_list, const ElemType* elem, Comparer comparer, size_t* index);
extern int seq_list_get_elem(const SeqList* seq_list, size_t index, ElemType* elem);
extern int seq_list_insert_elem(SeqList* seq_list, size_t index, const ElemType* elem);
extern int seq_list_delete_elem(SeqList* seq_list, size_t index, ElemType* elem);
extern int seq_list_print_list(const SeqList* seq_list, PrintElem print_elem);
extern int seq_list_destroy(SeqList* seq_list);


#endif //DATA_STRUCTURE_SEQLIST_H