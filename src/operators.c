/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:24:24 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/22 09:40:41 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	exec_swap(t_stack *stack)
{
	int	swap;

	if (stack->top_position >= 1)
	{
		swap = stack->numbers[0];
		stack->numbers[0] = stack->numbers[1];
		stack->numbers[1] = swap;
		return (1);
	}
	return (0);
}

void	exec_push_a(t_stack *stack_one, t_stack *stack_two, int count)
{
	count = ++stack_two->top_position + 1;
	while (--count > 0)
	{
		stack_two->numbers[count] = stack_two->numbers[count - 1];
		stack_two->target_position_a[count] = stack_two->target_position_a[count
			- 1];
	}
	stack_two->numbers[count] = stack_one->numbers[count];
	stack_two->target_position_a[count] = stack_one->target_position_a[count];
	stack_one->top_position--;
}
int	exec_push(t_stack *stack_one, t_stack *stack_two)
{
	int	index;

	index = 0;
	if (stack_one->top_position != -1)
	{
		exec_push_a(stack_one, stack_two, index);
		index = -1;
		while (++index <= stack_one->top_position)
		{
			stack_one->numbers[index] = stack_one->numbers[index
				+ 1];
			stack_one->target_position_a[index] = stack_one->target_position_a[index
				+ 1];
		}
		return (1);
	}
	return (0);
}

int	exec_rotate(t_stack *stack)
{
	int	swap;
	int	index;
	int target;

	index = -1;
	swap = stack->numbers[0];
	target = stack->target_position_a[0];
	if (stack->top_position >= -1)
	{
		while (++index < stack->top_position)
		{
			stack->numbers[index] = stack->numbers[index + 1];
			stack->target_position_a[index] = stack->target_position_a[index + 1];
			
		}
		stack->numbers[stack->top_position] = swap;
		stack->target_position_a[stack->top_position] = target;
		return (1);
	}
	return (0);
}

int	exec_rotate_reverse(t_stack *stack)
{
	int	swap;
	int	count;

	count = stack->top_position + 1;
	swap = stack->numbers[stack->top_position];
	if (stack->top_position >= -1)
	{
		while (--count >= 0)
			stack->numbers[count] = stack->numbers[count - 1];
		stack->numbers[0] = swap;
		return (1);
	}
	return (0);
}
