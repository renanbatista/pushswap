#include "../include/push_swap.h"

static int	check_inumber(char *cv_str)
{
	while (*cv_str)
		if (ft_isdigit(*cv_str) || (*cv_str == '-' && ft_isdigit(*(cv_str + 1))))
			cv_str++;
		else
			return (0);
	return (1);
}

static int	check_repeat_number(int *stack_a, int size_vector)
{
	int	index;
	int	index_compar;

	index = -1;
	while (++index < size_vector)
	{
		index_compar = -1;
		while (++index_compar <= size_vector)
		{
			if (stack_a[index] == stack_a[index_compar]
				&& index != index_compar)
				return (0);
		}
	}
	return (1);
}

int	handle_validation(int argc, char **cv_argv, t_stack *stack_a,
		int *stack_sub)
{
	int	count;
	int	size_vector;

	if (!stack_a)
		return (0);
	size_vector = argc - 2;
	count = -1;
	while (count++, cv_argv[count + 1])
	{
		if (check_inumber(cv_argv[count + 1]))
		{
			stack_a->numbers[count] = ft_atoi(cv_argv[count + 1]);
			stack_sub[count] = stack_a->numbers[count];
		}
		else
			return (0);
	}
	if (!check_repeat_number(stack_a->numbers, size_vector))
		return (0);
	return (1);
}
