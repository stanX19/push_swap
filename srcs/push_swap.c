#include "push_swap.h"

int	main(int argc, const char **argv)
{
    t_list *list = lst_new();

	int	i;
	
	i = 1;
	while (i < argc)
	{
		lst_append_val(list, atoi(argv[i]));
		i++;
	}
    // Printing the initial list
    printf("Initial list:\n");
    print_list(list);
    printf("\n");

    // Swapping the first two nodes
    lst_swap_first_2(list);
    printf("After swapping first two nodes:\n");
    print_list(list);
    printf("\n");

    // Rotating the list backward
    lst_rotate_backward(list);
    printf("After rotating backward:\n");
    print_list(list);
    printf("\n");

    // Checking if the list is sorted
    if (lst_is_sorted(list))
        printf("The list is sorted.\n");
    else
        printf("The list is not sorted.\n");

    // Creating a copy of the list
    t_list *copy = lst_copy(list);
    printf("Copied list:\n");
    print_list(copy);
    printf("\n");

    // Deleting the original list
    lst_delete(list);
    list = NULL;

    // Deleting the copied list
    lst_delete(copy);
    copy = NULL;

    return 0;
}

