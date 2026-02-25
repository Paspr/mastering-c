#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stddef.h>

typedef struct double_linked_list double_linked_list;

size_t dll_count(const double_linked_list *list);

double_linked_list *dll_create(void);

void dll_clear(double_linked_list *list);
void dll_destroy(double_linked_list **list);

void dll_print_direct(const double_linked_list *list);
void dll_print_reverse(const double_linked_list *list);

int dll_delete(double_linked_list *list, int value);

void dll_insert_at_head(double_linked_list *list, int value);
void dll_insert_at_tail(double_linked_list *list, int value);
int dll_insert_after(double_linked_list *list, int after_value, int new_value);

#endif