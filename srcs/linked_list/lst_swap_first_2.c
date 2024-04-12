#include "push_swap.h"

void    lst_swap_first_2(t_list *list) {
    if (!list || !list->head)
        return;
    node_swap_val_with_next(list->head);
}