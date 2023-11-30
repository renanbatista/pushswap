/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sort_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:53:36 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/26 02:20:31 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	send_minor_index(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	minor_index;
	int	minor_number;

	minor_index = 0;
	index = 0;
	while (++index <= stack_a->top_position)
		if (stack_a->numbers[minor_index] > stack_a->numbers[index])
			minor_index = index;
	minor_number = stack_a->numbers[minor_index];
	if (minor_index <= stack_a->top_position / 2)
	{
		while (stack_a->numbers[0] != minor_number)
			handle_operators("ra", stack_a, stack_b);
	}
	else
	{
		while (stack_a->numbers[0] != minor_number)
			handle_operators("rra", stack_a, stack_b);
	}
	handle_operators("pb", stack_a, stack_b);
}

int	check_is_order_a(t_stack *stack_a)
{
	int	index;

	index = -1;
	while (++index <= stack_a->top_position)
		if (index != stack_a->target_position_a[index])
			return (0);
	return (1);
}

void	handle_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	all_top_position;

	if (check_is_order_a(stack_a))
		return ;
	all_top_position = stack_a->top_position;
	if (all_top_position == 4)
		send_minor_index(stack_a, stack_b);
	send_minor_index(stack_a, stack_b);
	handle_order_three_values(stack_a, stack_a);
	if (stack_b->numbers[0] < stack_b->numbers[1])
		handle_operators("sb", stack_a, stack_b);
	if (all_top_position == 4)
		handle_operators("pa", stack_a, stack_b);
	handle_operators("pa", stack_a, stack_b);
}
