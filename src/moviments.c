/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:43:20 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/07 20:26:35 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

void	push(t_stack *stack, int value, int stack_size)
{
	if (stack->top < stack_size - 1)
	{
		stack->vector[++stack->top] = value;
	}
}

int	pop(t_stack *stack)
{
	if (!is_empty(stack))
	{
		return (stack->vector[stack->top--]);
	}
	return (-1);
}

int	peek(t_stack *stack)
{
	if (!is_empty(stack))
	{
		return (stack->vector[stack->top]);
	}
	return (-1);
}
