#include <stdio.h>
#include "doublelinkedlist.h"

int main()
{
    double_linked_list *new_list = dll_create();
    dll_insert_at_head(new_list, 10);
    dll_insert_at_tail(new_list, 20);
    dll_insert_at_tail(new_list, 30);
    dll_insert_at_head(new_list, 40);

    dll_print_direct(new_list);
    printf("The length of list is %zu\n", dll_count(new_list));
    dll_print_reverse(new_list);

    dll_delete(new_list, 40);

    dll_print_direct(new_list);
    printf("The length of list is %zu\n", dll_count(new_list));

    dll_clear(new_list);
    dll_print_direct(new_list);
    printf("The length of list is %zu\n", dll_count(new_list));

    dll_insert_at_head(new_list, 50);
    dll_insert_at_tail(new_list, 60);
    dll_insert_at_tail(new_list, 70);

    dll_print_direct(new_list);
    printf("The length of list is %zu\n", dll_count(new_list));

    dll_insert_after(new_list, 60, 65);
    dll_print_direct(new_list);
    dll_print_reverse(new_list);
    printf("The length of list is %zu\n", dll_count(new_list));

    dll_destroy(&new_list);
    return 0;
}