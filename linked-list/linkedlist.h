#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>

typedef struct linked_list linked_list;

linked_list *ll_create(void);
void print_linked_list(linked_list *list);

size_t ll_count(const linked_list *list);
int ll_delete(linked_list *list, int value);
void ll_clear(linked_list *list);
void ll_destroy(linked_list **list);

void ll_insert_at_head(linked_list *list, int value);
void ll_insert_at_tail(linked_list *list, int value);
int ll_insert_after(linked_list *list, int after_value, int new_value);

#endif
