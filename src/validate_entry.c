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

int	handle_validation(int i_argc, char **cv_argv, t_stack *s_stack_a,
		int *s_stack_sub)
{
	int	i_count;
	int	i_size_vector;

	s_stack_a->iv_numbers = ft_calloc(sizeof(int), i_argc);
	if (!s_stack_a)
		return (0);
	i_size_vector = i_argc - 1;
	i_count = -1;
	while (i_count++, cv_argv[i_count + 1])
	{
		if (check_is_number(cv_argv[i_count + 1]))
		{
			s_stack_a->iv_numbers[i_count] = ft_atoi(cv_argv[i_count + 1]);
			s_stack_sub[i_count] = s_stack_a->iv_numbers[i_count];
		}
		else
			return (0);
	}
	if (!check_repeat_number(s_stack_a->iv_numbers, i_size_vector))
		return (0);
	return (1);
}
