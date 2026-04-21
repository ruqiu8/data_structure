#include "linklist.h"

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

LinkList link_list_create() {
    LinkList L = (LinkList) malloc(sizeof(LNode));
    if (L == NULL) {
        return NULL;
    }

    L->next = NULL;
    return L;
}

size_t link_list_length(LinkList L) {
    assert(L != NULL);
    size_t length = 0;
    LNode *p      = L->next;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

bool link_list_empty(LinkList L) {
    assert(L != NULL);
    return (L->next == NULL);
}

size_t link_list_locate_elem(LinkList L, const ElemType *elem, Comparer comparer) {
    assert(L != NULL && elem != NULL && comparer != NULL);
    LNode *p     = L->next;
    size_t index = 0;
    while (p) {
        if (comparer(&(p->data), elem) == 0) {
            return index;
        }
        p = p->next;
        index++;
    }
    return SIZE_MAX;
}

int link_list_get_elem(LinkList L, size_t index, ElemType *elem) {
    assert(L != NULL && elem != NULL);

    LNode *p = L->next;
    size_t j = 0;
    while (p && j < index) {
        p = p->next;
        j++;
    }

    if (p == NULL) {
        return -1;
    }
    *elem = p->data;
    return 0;
}

int link_list_insert_elem(LinkList L, size_t index, const ElemType *elem) {
    assert(L != NULL && elem != NULL);

    LNode *p = L;
    size_t j = 0;

    // 寻找第 index 个节点的前驱
    while (p != NULL && j < index) {
        p = p->next;
        j++;
    }

    // 如果 p 为空，说明 index 超出了链表长度范围
    if (p == NULL) {
        return -1;
    }

    LNode *new_node = (LNode *) malloc(sizeof(LNode));
    if (new_node == NULL) {
        return -1;
    }

    new_node->data = *elem;
    new_node->next = p->next;
    p->next        = new_node;

    return 0;
}

int link_list_delete_elem(LinkList L, size_t index, ElemType *elem) {
    assert(L != NULL);

    LNode *p = L;
    size_t j = 0;

    // 寻找待删除节点的前驱节点
    while (p->next != NULL && j < index) {
        p = p->next;
        j++;
    }

    if (p->next == NULL) {
        return -1;
    }

    LNode *q = p->next; // q 是真正要删除的节点
    p->next  = q->next; // 断开连接

    if (elem != NULL) {
        *elem = q->data;
    }
    free(q);

    return 0;
}

void link_list_print_list(LinkList L, PrintElem print_elem) {
    assert(L != NULL && print_elem != NULL);
    LNode *p = L->next;
    printf("List: [");
    while (p) {
        print_elem(&(p->data));
        if (p->next) {
            printf(", ");
        }
        p = p->next;
    }
    printf("]\n");
}

void link_list_destroy(LinkList *L) {
    assert(L != NULL);

    if (*L == NULL) {
        return;
    }

    LNode *p = *L;
    while (p) {
        LNode *temp = p;
        p           = p->next;
        free(temp);
    }
    *L = NULL;
}

int link_list_create_head(LinkList L, const ElemType *elem, size_t length) {
    assert(L != NULL && elem != NULL);

    for (size_t i = 0; i < length; i++) {
        LNode *new_node = (LNode *) malloc(sizeof(LNode));
        if (new_node == NULL) {
            // 由调用者决定创建失败时是否销毁 L
            return -1;
        }
        new_node->data = elem[i];
        new_node->next = L->next;
        L->next        = new_node;
    }
    return 0;
}

int link_list_create_tail(LinkList L, const ElemType *elem, size_t length) {
    assert(L != NULL && elem != NULL);

    LNode *rear = L;

    while (rear->next != NULL) {
        rear = rear->next;
    }

    for (size_t i = 0; i < length; i++) {
        LNode *new_node = (LNode *) malloc(sizeof(LNode));
        if (new_node == NULL) {
            return -1;
        }

        new_node->data = elem[i];
        new_node->next = NULL;

        rear->next = new_node; // 链接到当前末尾
        rear       = new_node; // 更新末尾指针
    }
    return 0;
}