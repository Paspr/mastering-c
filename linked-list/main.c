#include <stdio.h>
#include "linkedlist.h"

int main()
{
    linked_list *new_list = ll_create();

    ll_insert_at_head(new_list, 10);
    ll_insert_at_tail(new_list, 20);
    ll_insert_at_tail(new_list, 30);

    print_linked_list(new_list);
    printf("The lenth of list is %zu\n", ll_count(new_list));

    ll_delete(new_list, 20);

    print_linked_list(new_list);
    printf("The length of list is %zu\n", ll_count(new_list));

    ll_clear(new_list);

    print_linked_list(new_list);
    printf("The length of list is %zu\n", ll_count(new_list));

    ll_insert_at_head(new_list, 40);
    ll_insert_at_tail(new_list, 50);
    ll_insert_at_tail(new_list, 60);

    print_linked_list(new_list);
    printf("The length of list is %zu\n", ll_count(new_list));

    ll_insert_after(new_list, 40, 70);
    print_linked_list(new_list);
    printf("The length of list is %zu\n", ll_count(new_list));

    ll_destroy(&new_list);

    return 0;
}