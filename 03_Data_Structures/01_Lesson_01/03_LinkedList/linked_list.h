/*
 *           File: linked_list.h
 *     Created on: Friday 22/04/2022 15:09
 *         Author: Makram Maher Makram
 *        Subject: Create Generic Linked List Data structure
 *
 *
 */

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    void*   dataPTR;
    struct node* nextNode;
} node_t;

typedef struct
{
    node_t *start_node;
    uint16_t count;
    uint8_t element_size;
} linked_list_t;

typedef enum
{
    LINKED_LIST_no_error,
    LINKED_LIST_empty,
    LINKED_LIST_null
} linked_list_status_t;


linked_list_status_t linked_list_Init(linked_list_t *list, uint8_t element_size);
linked_list_status_t linked_list_Add(linked_list_t *list, void *data);
linked_list_status_t linked_list_Delete_Index(linked_list_t *list, uint16_t index);
linked_list_status_t linked_list_Delete_All(linked_list_t *list);
linked_list_status_t linked_list_Print(linked_list_t *list, void(*printFun)(void *, uint8_t, uint16_t));

#endif