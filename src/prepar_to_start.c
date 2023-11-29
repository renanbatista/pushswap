/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepar_to_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:06:48 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/25 20:01:41 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*start_stack(int argc, int top)
{
	t_stack	*stack;

	stack = ft_calloc(sizeof(t_stack), 1);
	stack->numbers = ft_calloc(sizeof(int), argc);
	stack->numbers[top + 1] = 0;
	stack->target_position_a = ft_calloc(sizeof(int), argc);
	stack->cost_move_a = ft_calloc(sizeof(int), argc);
	stack->cost_move_b = ft_calloc(sizeof(int), argc);
	stack->top_position = top;
	return (stack);
}

void	make_free(t_stack *stack_a, t_stack *stack_b, int *stack_sub)
{
	free(stack_a->numbers);
	free(stack_b->numbers);
	free(stack_a->target_position_a);
	free(stack_b->target_position_a);
	free(stack_a->cost_move_a);
	free(stack_b->cost_move_a);
	free(stack_a->cost_move_b);
	free(stack_b->cost_move_b);
	free(stack_a);
	free(stack_b);
	free(stack_sub);
}

int	handle_order_three_values(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top_position == 1 && stack_a->numbers[0] < stack_a->numbers[1])
		return (1);
	else if (stack_a->top_position == 1 \
			&& stack_a->numbers[0] >= stack_a->numbers[1])
	{
		handle_operators("sa", stack_a, stack_b);
		return (1);
	}
	else if (stack_a->top_position == 2)
	{
		if (stack_a->numbers[0] > stack_a->numbers[1]
			&& stack_a->numbers[0] > stack_a->numbers[2])
			handle_operators("ra", stack_a, stack_b);
		if (stack_a->numbers[1] > stack_a->numbers[0]
			&& stack_a->numbers[1] > stack_a->numbers[2])
			handle_operators("rra", stack_a, stack_b);
		if (stack_a->numbers[0] > stack_a->numbers[1])
			handle_operators("sa", stack_a, stack_b);
		return (1);
	}
	return (0);
}

void	sort_stack_sub(int *stack_sub, int size)
{
	int	count_sub;
	int	swap;
	int	count;

	count = -1;
	while (++count <= size)
	{
		count_sub = count + 1;
		while (count_sub <= size)
		{
			if (stack_sub[count] > stack_sub[count_sub])
			{
				swap = stack_sub[count_sub];
				stack_sub[count_sub] = stack_sub[count];
				stack_sub[count] = swap;
			}
			count_sub++;
		}
	}
}

void	search_target_pos(t_stack *stack_a, int *stack_sub)
{
	int	count;
	int	count_sub;

	count = -1;
	count_sub = -1;
	sort_stack_sub(stack_sub, stack_a->top_position);
	while (++count <= stack_a->top_position)
	{
		count_sub = -1;
		while (++count_sub <= stack_a->top_position)
		{
			if (stack_a->numbers[count] == stack_sub[count_sub])
			{
				stack_a->target_position_a[count] = count_sub;
				break ;
			}
		}
	}
}
