
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "c_list.h"

c_list_node *list_node_new(int unit)
{
    c_list_node *nd = (c_list_node *)malloc(sizeof(c_list_node));
    memset(nd, 0, sizeof(c_list_node));
    nd->data = malloc(unit);
    return nd;
}

c_list *list_init(int unit)
{
    c_list *list = (c_list *)malloc(sizeof(c_list));
    assert(list != NULL);

    c_list_node *head = list_node_new(unit);
    assert(head != NULL);

    c_list_node *tail = list_node_new(unit);
    assert(tail != NULL);

    memset(list, 0, sizeof(c_list));

    list->head = head;
    list->tail = tail;

    list->head->next = list->tail;
    list->tail->pre = list->head;

    list->size = 0;

    return list;
}

void list_free(c_list *list)
{
    assert(list != NULL);

    c_list_node *tmp;
    for (c_list_node *node = list->head; node; node = tmp)
    {
        free(node->data);
        tmp = node->next;
        free(node);
    }
    free(list);
}

void _list_push_back(c_list *list, c_list_node *nd)
{
    assert(list != NULL);
    assert(nd != NULL);

    list->tail->pre->next = nd;
    nd->next = list->tail;
    nd->pre = list->tail->pre;
    list->tail->pre = nd;
    list->size++;
}

void _list_push_front(c_list *list, c_list_node *nd)
{
    assert(list != NULL);
    assert(nd != NULL);

    list->head->next->pre = nd;
    nd->next = list->head->next;
    nd->pre = list->head;
    list->head->next = nd;
    list->size++;
}

void list_push_back(c_list *list, void *value, int unit)
{
    c_list_node *node = list_node_new(unit);
    memcpy(node->data, value, unit);
    _list_push_back(list, node);
}

void list_push_front(c_list *list, void *value, int unit)
{
    c_list_node *nd = list_node_new(unit);
    memcpy(nd->data, value, unit);
    _list_push_back(list, nd);
}

c_list_node *_list_read_back(c_list *list)
{
    assert(list != NULL);
    return list->tail->pre;
}

c_list_node *_list_read_front(c_list *list)
{
    assert(list != NULL);
    return list->head->next;
}

void *list_read_back(c_list *list)
{
    return _list_read_back(list)->data;
}

void *list_read_front(c_list *list)
{
    return _list_read_front(list)->data;
}

void list_erase_back(c_list *list)
{
    c_list_node *nd = list->tail->pre;
    list->tail->pre = nd->pre;
    nd->pre->next = list->tail;
    free(nd);
    list->size--;
}

void list_erase_front(c_list *list)
{
    c_list_node *nd = list->head->next;
    list->head->next = nd->next;
    nd->next->pre = list->head;
    free(nd);
    list->size--;
}

void list_erase(c_list *list, c_list_node *nd)
{
    assert(nd != list->head && nd != list->tail);

    for (c_list_node *cur = list->head->next; cur; cur = cur->next)
    {
        if (cur->data == nd->data)
        {
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
            free(cur);
            list->size--;
            break;
        }
    }
}

int main()
{
    return 0;
}
