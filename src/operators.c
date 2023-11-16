/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:24:24 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/15 21:15:01 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	exec_swap(t_stack *stack)
{
	int	value;

	if (stack->top >= 1)
	{
		value = stack->vec[0];
		stack->vec[0] = stack->vec[1];
		stack->vec[1] = value;
		return (1);
	}
	return (0);
}

int	exec_push(t_stack *stack_one, t_stack *stack_two)
{
	int	count;

	if (stack_one->top != -1)
	{
		count = stack_one->top + 1;
		while (count--, count >= 0)
		{
			stack_two->top++;
			stack_two->vec[stack_two->top] = stack_one->vec[stack_one->top];
			stack_one->top--;
			return (1);
		}
	}
	return (0);
}

int	exec_rotate(t_stack *stack)
{
	int	swap;
	int	count;

	count = -1;
	swap = stack->vec[0];
	if (stack->top >= -1)
	{
		while (++count < stack->top)
			stack->vec[count] = stack->vec[count + 1];
		stack->vec[stack->top] = swap;
		return (1);
	}
	return (0);
}

int	exec_rotate_reverse(t_stack *stack)
{
	int	swap;
	int	count;

	count = stack->top + 1;
	swap = stack->vec[stack->top];
	if (stack->top >= -1)
	{
		while (--count >= 0)
			stack->vec[count] = stack->vec[count - 1];
		stack->vec[0] = swap;
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
