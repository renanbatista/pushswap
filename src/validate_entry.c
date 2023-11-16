#include "../include/push_swap.h"

static int	check_is_number(char *str)
{
	while (*str)
		if (ft_isdigit(*str) || (*str == '-' && ft_isdigit(*(str + 1))))
			str++;
		else
			return (0);
	return (1);
}

static int	check_repeat_number(int *stack_a, int size_vector)
{
	int	index;
	int	index_compar;

	index = -1;
	index_compar = -1;
	while (index++, index < size_vector)
		while (index_compar++, index_compar < size_vector)
			if (stack_a[index] == stack_a[index_compar]
				&& index != index_compar)
				return (0);
	return (1);
}

int	handle_validation(int argc, char **argv, t_stack *stack_a,
		int *stack_sub)
{
	int	count;
	int	size_vector;

	stack_a->vec = ft_calloc(sizeof(int), argc);
	if (!stack_a)
		return (0);
	size_vector = argc - 1;
	count = -1;
	while (count++, argv[count + 1])
	{
		if (check_is_number(argv[count + 1]))
		{
			stack_a->vec[count] = ft_atoi(argv[count + 1]);
			stack_sub[count] = stack_a->vec[count];
		}
		else
			return (0);
	}
	if (!check_repeat_number(stack_a->vec, size_vector))
		return (0);
	return (1);
}
