#include "../include/push_swap.h"
#include <stdlib.h>

int	check_is_number(char *str)
{
	while(*str)
	{
		if(ft_isdigit(*str))
			str++;
		else
		 	return (0);
	}
	return (1);
}

int	check_repeat_number(int *vector)
{
	// int sizeof
}

int handle_validation(int argc, char ** argv, int *stack_a, int *stack_b)
{
	long int	number;
	int			count;
	int			*vector;

	vector = ft_calloc(sizeof(int), argc);
	count = -1;
	while (count++, argv[count])
		if(check_is_number(argv[count]))
			vector[count] = ft_atoi(argv[count]);
		else
		 	return (0);
	if(!check_repeat_number(vector))
		return(0);
	return (1);
}
