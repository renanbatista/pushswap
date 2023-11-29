/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:53:49 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/26 02:11:55 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_inumber(char *cv_str)
{
	char	*first_sinal;

	first_sinal = cv_str;
	if (ft_strlen(cv_str) == 0)
		return (0);
	while (*cv_str)
	{
		if (*cv_str == '-' && *first_sinal != '-')
			return (0);
		if (ft_isdigit(*cv_str) || (*cv_str == '-' && ft_isdigit(*(cv_str
						+ 1))))
			cv_str++;
		else
			return (0);
	}
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

int	check_errors(long int value)
{
	if (value > __INT_MAX__)
		return (0);
	if (value < -2147483648)
		return (0);
	return (1);
}

int	handle_validation(int argc, char **cv_argv, t_stack *stack_a,
		int *stack_sub)
{
	int		count;
	int		size_vector;
	long	swap_int;

	size_vector = argc - 2;
	count = -1;
	while (count++, cv_argv[count + 1])
	{
		if (check_inumber(cv_argv[count + 1]))
		{
			swap_int = ft_atoi(cv_argv[count + 1]);
			if (!check_errors(swap_int))
				return (0);
			stack_a->numbers[count] = swap_int;
			stack_sub[count] = stack_a->numbers[count];
		}
		else
			return (0);
	}
	stack_sub[count] = 0;
	if (!check_repeat_number(stack_a->numbers, size_vector))
		return (0);
	return (1);
}
