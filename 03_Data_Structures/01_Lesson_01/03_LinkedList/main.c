/*
 *           File: main.c
 *     Created on: Friday 22/04/2022 15:09
 *         Author: Makram Maher Makram
 *        Subject: Create Generic Linked List Data structure
 *
 *
 */

#include <stdio.h>
#include "linked_list.h"

void LinkedList_print_float(void* ptr, uint16_t num)
{
    printf("%d --> %.3f\n", num, *((float*)ptr));
}

void LinkedList_print_uint16(void* ptr, uint16_t num)
{
    printf("%d --> %d\n", num, *((uint16_t*)ptr));
}

int main(void)
{
    printf("create new linked list of float elements\n");
    linked_list_t myLinkedList;
    linked_list_Init(&myLinkedList, sizeof(float));

    /* add two nodes in linked list with values 2.342 and 1.231 */
    printf("add two element in float linked list\n");
    float dataHolder = 2.342;
    linked_list_Add(&myLinkedList, &dataHolder);
    dataHolder = 1.231;
    linked_list_Add(&myLinkedList, &dataHolder);
    

    /* print linked list */
    linked_list_Print(&myLinkedList, &LinkedList_print_float);

    /* delete all nodes in linked list */
    printf("Delete all element in float linked list\n");
    linked_list_Delete_All(&myLinkedList);

    /* add other four nodes to linked list */
    printf("add four element in float linked list\n");
    dataHolder = 12.231;
    linked_list_Add(&myLinkedList, &dataHolder);
    dataHolder = 125.231;
    linked_list_Add(&myLinkedList, &dataHolder);
    dataHolder = 5.231;
    linked_list_Add(&myLinkedList, &dataHolder);
    dataHolder = 15.231;
    linked_list_Add(&myLinkedList, &dataHolder);

    /* print linked list */
    linked_list_Print(&myLinkedList, &LinkedList_print_float);
    /* Delete node of index 1 (2nd node) */
    printf("Delete index number 1 element in float linked list\n");
    linked_list_Delete_Index(&myLinkedList, 1);
    /* print linked list */
    linked_list_Print(&myLinkedList, &LinkedList_print_float);


    printf("\n\ncreate new linked list of integers elements\n");
    linked_list_t myLinkedList2;
    linked_list_Init(&myLinkedList2, sizeof(uint16_t));

    /* add two nodes in linked list with values 2.342 and 1.231 */
    printf("add two element in integers linked list\n");
    uint16_t dataHolder2 = 2;
    linked_list_Add(&myLinkedList2, &dataHolder2);
    dataHolder2 = 12;
    linked_list_Add(&myLinkedList2, &dataHolder2);

    /* print linked list */
    linked_list_Print(&myLinkedList2, &LinkedList_print_uint16);

    printf("Delete all element in integer linked list\n");
    /* delete all nodes in linked list */
    linked_list_Delete_All(&myLinkedList2);

    printf("add five element in integer linked list\n");
    /* add other three nodes to linked list */
    dataHolder2 = 12;
    linked_list_Add(&myLinkedList2, &dataHolder2);
    dataHolder2 = 125;
    linked_list_Add(&myLinkedList2, &dataHolder2);
    dataHolder2 = 231;
    linked_list_Add(&myLinkedList2, &dataHolder2);
    dataHolder2 = 31;
    linked_list_Add(&myLinkedList2, &dataHolder2);
    dataHolder2 = 1;
    linked_list_Add(&myLinkedList2, &dataHolder2);

    /* print linked list */
    linked_list_Print(&myLinkedList2, &LinkedList_print_uint16);
    /* Delete node of index 1 (2nd node) */
    printf("Delete index number 1 element in integer linked list\n");
    linked_list_Delete_Index(&myLinkedList2, 1);
    printf("Delete index number 3 element in integer linked list\n");
    linked_list_Delete_Index(&myLinkedList2, 3);
    /* print linked list */
    linked_list_Print(&myLinkedList2, &LinkedList_print_uint16);


    return 0;
}