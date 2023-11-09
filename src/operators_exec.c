/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:24:24 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/08 22:05:05 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	exec_swap(t_stack *stack)
{
	int	value;

	if (stack->top >= 1)
	{
		value = stack->vector[stack->top];
		stack->vector[stack->top] = stack->vector[stack->top -1];
		stack->vector[stack->top - 1] = value;
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
			stack_two->vector[stack_two->top] = stack_one->vector[stack_one->top];
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
	// FIXME: 
	count = stack->top + 1;
	if(stack->top > 0)
	{
		swap = stack->vector[stack->top];
		while(count--, count >= 0)
		{
			stack->vector[count + 1] = stack->vector[count];
		}
		stack->vector[stack->top] = swap;
		return (1);
	}
	return (0);
}

int	exec_rotate_reverse(t_stack *stack)
{
	if(stack)
		return (1);
	return (1);
}
