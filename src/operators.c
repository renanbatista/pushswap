/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:24:24 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/17 23:53:45 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	exec_swap(t_stack *s_stack)
{
	int	i_value;

	if (s_stack->i_top >= 1)
	{
		i_value = s_stack->iv_numbers[0];
		s_stack->iv_numbers[0] = s_stack->iv_numbers[1];
		s_stack->iv_numbers[1] = i_value;
		return (1);
	}
	return (0);
}

int	exec_push(t_stack *s_stack_one, t_stack *s_stack_two)
{
	int	i_count;
	// FIXME: adicionando elemento depois do top ao inves da posicao 0
	if (s_stack_one->i_top != -1)
	{
		i_count = s_stack_one->i_top + 1;
		while (--i_count >= 0)
		{
			s_stack_two->i_top++;
			s_stack_two->iv_numbers[s_stack_two->i_top] = s_stack_one->iv_numbers[s_stack_one->i_top];
			s_stack_one->i_top--;
			s_stack_two->iv_target_position_a[]
			return (1);
		}
	}
	return (0);
}

int	exec_rotate(t_stack *s_stack)
{
	int	i_swap;
	int	i_count;

	i_count = -1;
	i_swap = s_stack->iv_numbers[0];
	if (s_stack->i_top >= -1)
	{
		while (++i_count < s_stack->i_top)
			s_stack->iv_numbers[i_count] = s_stack->iv_numbers[i_count + 1];
		s_stack->iv_numbers[s_stack->i_top] = i_swap;
		return (1);
	}
	return (0);
}

int	exec_rotate_reverse(t_stack *s_stack)
{
	int	swap;
	int	count;

	count = s_stack->i_top + 1;
	swap = s_stack->iv_numbers[s_stack->i_top];
	if (s_stack->i_top >= -1)
	{
		while (--count >= 0)
			s_stack->iv_numbers[count] = s_stack->iv_numbers[count - 1];
		s_stack->iv_numbers[0] = swap;
		return (1);
	}
	return (0);
}
