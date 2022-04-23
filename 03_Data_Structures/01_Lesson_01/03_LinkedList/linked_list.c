/*
 *           File: linked_list.c
 *     Created on: Friday 22/04/2022 15:09
 *         Author: Makram Maher Makram
 *        Subject: Create Generic Linked List Data structure
 *
 *
 */
#include "linked_list.h"

void static linked_list_Fill_The_Record(void *srcPTR, void *dstPTR, uint8_t element_size)
{
    uint8_t i;
    for (i = 0; i < element_size; i++)
    {
        *((uint8_t *)dstPTR + i) = *((uint8_t *)srcPTR + i);
    }
}

linked_list_status_t linked_list_Init(linked_list_t *list, uint8_t element_size)
{
    if (list == NULL)
        return LINKED_LIST_null;
    list->start_node = NULL;
    list->count = 0;
    list->element_size = element_size;
    return LINKED_LIST_no_error;
}

linked_list_status_t linked_list_Add(linked_list_t *list, void *data)
{
    /* Check for null */
    if (list == NULL || data == NULL)
        return LINKED_LIST_null;

    /* check startnode */
    node_t *lastnode = list->start_node;
    if (lastnode == NULL)
    {
        /* allocate start node with sizeof(node_t) */
        list->start_node = malloc(sizeof(node_t));
        /* set last node as start node */
        lastnode = list->start_node;
    }
    else
    {
        /* get the lastnode */
        while (lastnode->nextNode != NULL)
        {
            lastnode = lastnode->nextNode;
        }
        /* allocate new node with sizeof(node_t) and set it as a lastnode */
        lastnode->nextNode = malloc(sizeof(node_t));
        lastnode = lastnode->nextNode;
    }
    /* initialize new node and allocate new data size according to list->element-size */
    lastnode->dataPTR = malloc(list->element_size);
    lastnode->nextNode = NULL;
    /* copy date byte by byte in the new node */
    linked_list_Fill_The_Record(data, lastnode->dataPTR, list->element_size);
    list->count++;

    return LINKED_LIST_no_error;
}

linked_list_status_t linked_list_Delete_Index(linked_list_t *list, uint16_t index)
{
    /* Check for null */
    if (list == NULL)
        return LINKED_LIST_null;

    /* check for empty */
    if (list->count == 0 || list->count <= index)
        return LINKED_LIST_empty;

    uint16_t i;
    node_t *nodePTR = list->start_node;
    node_t *prevNodePTR = NULL;
    if (index == 0)
    {
        /* skip first node from list */
        list ->start_node = nodePTR->nextNode;
    }
    else
    {
        for (i = 0; i < list->count; i++)
        {
            if (i == index)
            {
                /* skip current node from list */
                prevNodePTR->nextNode = nodePTR->nextNode;
                break;
            }
            else
            {
                /* go to next node and save previous node */
                prevNodePTR = nodePTR;
                nodePTR = nodePTR->nextNode;
            }
        }
    }
    /* deallocate nodePTR->dataPTR and nodePTR */
    list->count--;
    free(nodePTR->dataPTR);
    free(nodePTR);
    return LINKED_LIST_no_error;
}

linked_list_status_t linked_list_Delete_All(linked_list_t *list)
{
    /* Check for null */
    if (list == NULL)
        return LINKED_LIST_null;

    /* check for empty */
    if (list->count == 0)
        return LINKED_LIST_empty;
    
    node_t *tempNode = list->start_node;
    node_t* currentnode = list->start_node;
    while (currentnode != NULL)
    {
        tempNode = currentnode;
        /* deallocate data and node */
        currentnode = currentnode->nextNode;
        free(tempNode->dataPTR);
        free(tempNode);
        
    }
    list->count = 0;
    list->start_node = NULL;

    return LINKED_LIST_no_error;
}

linked_list_status_t linked_list_Print(linked_list_t *list, void (*printFun)(void *, uint8_t, uint16_t))
{
    /* Check for null */
    if (list == NULL || printFun == NULL)
        return LINKED_LIST_null;

    /* check for empty */
    if (list->count == 0)
        return LINKED_LIST_empty;

    uint8_t i;
    node_t *node = list->start_node;
    printf("\n=============( Linked List Print )=============\n");
    for (i = 0; i < list->count; i++)
    {
        printFun(node->dataPTR, list->element_size, i);
        node = node->nextNode;
    }
    printf("===============================================\n");

    return LINKED_LIST_no_error;
}