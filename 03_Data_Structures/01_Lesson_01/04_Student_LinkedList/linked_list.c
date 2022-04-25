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

linked_list_status_t linked_list_Get_By_Index(linked_list_t *list, uint16_t index, void **data)
{
    /* Check for null */
    if (list == NULL || list->start_node == NULL)
        return LINKED_LIST_null;

    /* check for empty */
    if (list->count == 0)
        return LINKED_LIST_empty;

    uint16_t i;
    node_t *nodePTR = list->start_node;
    for (i = 0; i < list->count; i++)
    {
        if (i == index)
        {
            /* return index */
            *data = nodePTR->dataPTR;
            return LINKED_LIST_no_error;
        }
        /* next please */
        nodePTR = nodePTR->nextNode;
    }
    return LINKED_LIST_not_found;
}

linked_list_status_t linked_list_Get_By_Index_From_End(linked_list_t *list, uint16_t indexFromEnd, void **data)
{
    /* Check for null */
    if (list == NULL || list->start_node == NULL)
        return LINKED_LIST_null;

    /* check for empty */
    if (list->count == 0)
        return LINKED_LIST_empty;

    uint16_t i = 0;
    node_t *nodePTR = list->start_node;
    node_t *nodeNthPTR = NULL;
    while (nodePTR != NULL)
    {
        if (nodeNthPTR == NULL)
        {
            if (i >= indexFromEnd)
            {
                nodeNthPTR = list->start_node;
            }
        }
        else
        {
            /* next node */
            nodeNthPTR = nodeNthPTR->nextNode;
        }
        /* next please */
        nodePTR = nodePTR->nextNode;
        i++;
    }
    if (nodeNthPTR == NULL)
    {
        return LINKED_LIST_not_found;
    }
    else
    {
        *data = nodeNthPTR->dataPTR;
        return LINKED_LIST_no_error;
    }
}

linked_list_status_t linked_list_Get_Middle(linked_list_t *list, void **data)
{
    /* Check for null */
    if (list == NULL || list->start_node == NULL)
        return LINKED_LIST_null;

    /* check for empty */
    if (list->count == 0)
        return LINKED_LIST_empty;

    uint16_t i = 0;
    node_t *nodePTR = list->start_node;
    node_t *middleNodePTR = list->start_node;

    while (nodePTR != NULL)
    {
        if (i != 0 && i % 2 != 0)
        {
            /* i = 1, 3, 5, 7, ... */
            middleNodePTR = middleNodePTR->nextNode;
        }
        /* next please */
        nodePTR = nodePTR->nextNode;
        i++;
    }
    *data = middleNodePTR->dataPTR;
    return LINKED_LIST_no_error;
}

linked_list_status_t linked_list_Detect_Loop(linked_list_t *list)
{
    /* Check for null */
    if (list == NULL || list->start_node == NULL)
        return LINKED_LIST_null;

    /* check for empty */
    if (list->count == 0)
        return LINKED_LIST_empty;

    uint16_t i = 0;
    node_t *fastNodePTR = list->start_node;
    node_t *slowNodePTR = list->start_node;

    while (fastNodePTR != NULL && slowNodePTR != NULL)
    {
        if (i != 0 && i % 2 != 0)
        {
            /* i = 1, 3, 5, 7, ... */
            slowNodePTR = slowNodePTR->nextNode;
        }
        /* next please */
        fastNodePTR = fastNodePTR->nextNode;
        i++;
        if (fastNodePTR == slowNodePTR)
        {
            /* loop is found */
            return LINKED_LIST_loop_detected;
        }
    }
    return LINKED_LIST_no_error;
}

linked_list_status_t linked_list_Reverse(linked_list_t *list)
{
    /* Check for null */
    if (list == NULL || list->start_node == NULL)
        return LINKED_LIST_null;

    /* check for empty */
    if (list->count == 0)
        return LINKED_LIST_empty;

    node_t *prevNodePTR = NULL;
    node_t *currNodePTR = list->start_node;
    node_t *nextNodePTR = list->start_node;

    while (currNodePTR != NULL)
    {
        nextNodePTR = currNodePTR->nextNode;
        currNodePTR->nextNode = prevNodePTR;
        prevNodePTR = currNodePTR;
        currNodePTR = nextNodePTR;
    }
    list->start_node = prevNodePTR;
    return LINKED_LIST_no_error;
}

linked_list_status_t linked_list_Get_Length_Iterative(linked_list_t *list, uint16_t *length)
{
    /* Check for null */
    if (list == NULL || list->start_node == NULL)
        return LINKED_LIST_null;

    uint16_t i = 0;
    node_t *nodePTR = list->start_node;
    while (nodePTR->nextNode != NULL)
    {
        /* next please */
        i++;
        nodePTR = nodePTR->nextNode;
    }
    *length = i + 1;
    return LINKED_LIST_no_error;
}

linked_list_status_t linked_list_Get_Length_count(linked_list_t *list, uint16_t *length)
{
    /* Check for null */
    if (list == NULL || list->start_node == NULL)
        return LINKED_LIST_null;

    *length = list->count;

    return LINKED_LIST_no_error;
}

linked_list_status_t linked_list_Delete_Index(linked_list_t *list, uint16_t index)
{
    /* Check for null */
    if (list == NULL || list->start_node == NULL)
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
        list->start_node = nodePTR->nextNode;
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
    if (list == NULL || list->start_node == NULL)
        return LINKED_LIST_null;

    /* check for empty */
    if (list->count == 0)
        return LINKED_LIST_empty;

    node_t *tempNode = list->start_node;
    node_t *currentnode = list->start_node;
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

uint16_t linked_list_Search(linked_list_t *list, uint8_t (*conditionFun)(void *, void *), void *condtionData)
{
    /* Check for null */
    if (list == NULL || list->start_node == NULL || conditionFun == NULL)
        return LINKED_LIST_null;

    /* check for empty */
    if (list->count == 0)
        return LINKED_LIST_empty;

    uint16_t i;
    node_t *nodePTR = list->start_node;
    for (i = 0; i < list->count; i++)
    {
        if (conditionFun(nodePTR->dataPTR, condtionData))
        {
            /* return index */
            return i;
        }
        /* next please */
        nodePTR = nodePTR->nextNode;
    }
    return -1;
}

linked_list_status_t linked_list_Print(linked_list_t *list, void (*printFun)(void *, uint16_t))
{
    /* Check for null */
    if (list == NULL || list->start_node == NULL || printFun == NULL)
        return LINKED_LIST_null;

    /* check for empty */
    if (list->count == 0)
        return LINKED_LIST_empty;

    uint8_t i;
    node_t *node = list->start_node;
    printf("\n-------------------( Linked List Print )-------------------\n");
    for (i = 0; i < list->count; i++)
    {
        printFun(node->dataPTR, i);
        node = node->nextNode;
    }
    printf("-----------------------------------------------------------\n");

    return LINKED_LIST_no_error;
}