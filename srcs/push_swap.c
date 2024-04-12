#include "push_swap.h"

int	main(int argc, const char **argv)
{
    t_data *data = init_data(argc, argv);

	print_list(data->a);
	delete_data(data);
}

