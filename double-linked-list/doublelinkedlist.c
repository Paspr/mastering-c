#include <stdlib.h>
#include <stdio.h>
#include "doublelinkedlist.h"

typedef struct dll_node
{
    int data;
    struct dll_node *next;
    struct dll_node *prev;
} dll_node;

typedef struct double_linked_list
{
    dll_node *head;
    dll_node *tail;
} double_linked_list;

size_t dll_count(const double_linked_list *list)
{
    /* Return the length of a double linked list */
    if (list == NULL)
        return 0;

    size_t length = 0;
    const dll_node *current = list->head;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

double_linked_list *dll_create(void)
{
    /* Create a linked list */
    double_linked_list *list = malloc(sizeof(*list));
    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->tail = NULL;
    return list;
}

static dll_node *dll_create_node(int value)
{
    /* Create a new node with given value */
    dll_node *new = malloc(sizeof(*new));
    if (new == NULL)
        return NULL; /* malloc has failed */
    new->data = value;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void dll_clear(double_linked_list *list)
{
    /* Clear the list (keep it) and free all nodes */
    if (list == NULL)
        return;

    dll_node *current = list->head;
    dll_node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
}

void dll_destroy(double_linked_list **list)
{
    /* Completely free memory and delete linked list container  */
    if (list == NULL || *list == NULL)
        return;

    dll_clear(*list);
    free(*list);
    *list = NULL;
}

void dll_print_direct(const double_linked_list *list)
{
    /* Prints out double linked list in the direct order */
    if (list == NULL)
    {
        printf("List is NULL\n");
        return;
    }

    const dll_node *current = list->head;

    if (current == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Direct double linked list order: ");
    printf("NULL");
    while (current != NULL)
    {
        printf(" <= %d => ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void dll_print_reverse(const double_linked_list *list)
{
    /* Prints out double linked list in the reverse order */
    if (list == NULL)
    {
        printf("List is NULL\n");
        return;
    }

    const dll_node *current = list->tail;

    if (current == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Reverse double linked list order: ");
    printf("NULL");
    while (current != NULL)
    {
        printf(" <= %d => ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

int dll_delete(double_linked_list *list, int value)
{
    /* Delete a node with the defined value */
    if (list == NULL)
        return 0;

    dll_node *current = list->head;

    while (current != NULL)
    {
        if (current->data == value)
        {
            if (current->prev != NULL)
                current->prev->next = current->next;
            else
                list->head = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;
            else
                list->tail = current->prev;

            free(current);
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void dll_insert_at_head(double_linked_list *list, int value)
{
    /* Insert a node with the defined value at the head of the list */
    if (list == NULL)
        return;
    dll_node *node = dll_create_node(value);
    if (node == NULL)
        return;

    node->next = list->head;

    if (list->head != NULL)
        list->head->prev = node;
    else
        /* case of an empty list */
        list->tail = node;
    list->head = node;
}

void dll_insert_at_tail(double_linked_list *list, int value)
{
    /* Insert a node with the defined value at the tail of the list */
    if (list == NULL)
        return;
    dll_node *node = dll_create_node(value);
    if (node == NULL)
        return;
    if (list->tail == NULL)
    {
        /* case of an empty list */
        list->head = node;
        list->tail = node;
        return;
    }
    node->prev = list->tail;
    list->tail->next = node;
    list->tail = node;
}

static dll_node *find_node(double_linked_list *list, int value)
{
    /* Find node with the defined value and return pointer to it */
    if (list == NULL)
        return NULL;

    dll_node *current = list->head;
    while (current != NULL)
    {
        if (current->data == value)
            return current;
        current = current->next;
    }
    return NULL;
}

int dll_insert_after(double_linked_list *list, int after_value, int new_value)
{
    /* Insert a node with the defined value after the node with specified value */

    if (list == NULL)
        return 0;

    dll_node *node_after_insert = find_node(list, after_value);
    if (node_after_insert == NULL)
        return 0;

    dll_node *node_to_insert = dll_create_node(new_value);
    if (node_to_insert == NULL)
        return 0;

    node_to_insert->next = node_after_insert->next;
    node_to_insert->prev = node_after_insert;

    if (node_after_insert->next != NULL)
        node_after_insert->next->prev = node_to_insert;
    else
        list->tail = node_to_insert;

    node_after_insert->next = node_to_insert;
    return 1;
}
