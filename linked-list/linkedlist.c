
#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

typedef struct ll_node
{
    int data;
    struct ll_node *next;
} ll_node;

typedef struct linked_list
{
    ll_node *head;
    ll_node *tail;
} linked_list;

size_t ll_count(const linked_list *list)
{
    /* Return the length of a linked list */
    if (!list)
        return 0;

    size_t length = 0;
    ll_node *current = list->head;
    while (current)
    {
        length++;
        current = current->next;
    }
    return length;
}

int ll_delete(linked_list *list, int value)
{
    /* Delete a node with the defined value */
    if (!list || !list->head)
        return 0;

    ll_node *current = list->head;
    ll_node *prev = NULL;
    if (current->data == value)
    {
        /* removing the only node in the list */
        if (list->head->next == NULL)
        {
            list->head = NULL;
            list->tail = NULL;
        }
        else
            list->head = current->next;
        free(current);
        return 1;
    }

    while (current)
    {
        if (current->data == value)
        {
            prev->next = current->next;
            if (current->next == NULL)
                list->tail = prev;
            free(current);
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}

static ll_node *create_node(int value)
{
    /* Create and return a pointer on a new node with the defined value */
    ll_node *new = malloc(sizeof(*new));
    if (!new)
        return NULL; /* malloc has failed */
    new->data = value;
    new->next = NULL;
    return new;
}

linked_list *ll_create(void)
{
    /* Create a linked list */
    linked_list *list = malloc(sizeof(*list));
    if (!list)
        return NULL;

    list->head = NULL;
    list->tail = NULL;
    return list;
}

static ll_node *find_node(const linked_list *list, int value)
{
    /* Find node with the defined value and return pointer to it */
    if (!list)
        return NULL;

    ll_node *current = list->head;
    while (current)
    {
        if (current->data == value)
            return current;
        current = current->next;
    }
    return NULL;
}

void ll_clear(linked_list *list)
{
    /* Clear the list (keep it) and free all nodes */
    if (!list)
        return;

    ll_node *current = list->head;
    ll_node *next;

    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
}

void ll_destroy(linked_list **list)
{
    /* Completely free memory and delete linked list container  */
    if (!list || !*list)
        return;

    ll_clear(*list);
    free(*list);
    *list = NULL;
}

void print_linked_list(linked_list *list)
{
    /* Prints out linked list */
    if (!list)
    {
        printf("List is NULL\n");
        return;
    }

    ll_node *current = list->head;

    if (!current)
    {
        printf("List is empty\n");
        return;
    }

    printf("Linked list: ");
    while (current)
    {
        printf("%d => ",
               current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void ll_insert_at_head(linked_list *list, int value)
{
    /* Insert a node with the defined value at the head of the list */
    if (!list)
        return;
    ll_node *node = create_node(value);
    if (!node)
        return;
    node->next = list->head;
    list->head = node;
    /* case of empty list */
    if (list->tail == NULL)
        list->tail = node;
}

void ll_insert_at_tail(linked_list *list, int value)
{
    /* Insert a node with the defined value at the tail of the list */
    if (!list)
        return;
    ll_node *node = create_node(value);
    if (!node)
        return;
    if (list->head == NULL)
        list->head = node;
    else
        list->tail->next = node;
    list->tail = node;
    list->tail->next = NULL;
}

int ll_insert_after(linked_list *list, int after_value, int new_value)
{
    /* Insert a node with the defined value after the node with specified value */

    if (!list)
        return 0;

    ll_node *node_after_insert = find_node(list, after_value);
    if (!node_after_insert)
        return 0;

    ll_node *node_to_insert = create_node(new_value);
    if (!node_to_insert)
        return 0;

    node_to_insert->next = node_after_insert->next;
    node_after_insert->next = node_to_insert;

    if (node_after_insert == list->tail)
        list->tail = node_to_insert;

    return 1;
}
