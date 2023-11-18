/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepar_to_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:06:48 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/17 23:08:04 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*start_stack(int i_argc, int i_top)
{
	t_stack	*stack;

	stack = ft_calloc(sizeof(t_stack), 1);
	stack->iv_numbers = ft_calloc(sizeof(int), i_argc);
	stack->iv_target_position_a = ft_calloc(sizeof(int), i_argc);
	stack->i_top = i_top;
	return (stack);
}

void	make_free(t_stack *s_stack_a, t_stack *s_stack_b, int *iv_stack_ordened)
{
	free(s_stack_a->iv_numbers);
	free(s_stack_b->iv_numbers);
	free(s_stack_a);
	free(s_stack_b);
	free(iv_stack_ordened);
}

int	check_number_of_values(t_stack *s_stack_a, t_stack *s_stack_b)
{
	if (s_stack_a->i_top == 1 && s_stack_a->iv_numbers[0] < s_stack_a->iv_numbers[1])
		return (1);
	else if (s_stack_a->i_top == 1 && s_stack_a->iv_numbers[0] >= s_stack_a->iv_numbers[1])
	{
		handle_operators("sa", s_stack_a, s_stack_b);
		return (1);
	}
	else if (s_stack_a->i_top == 2)
	{
		if (s_stack_a->iv_numbers[0] > s_stack_a->iv_numbers[1]
			&& s_stack_a->iv_numbers[0] > s_stack_a->iv_numbers[2])
			handle_operators("ra", s_stack_a, s_stack_b);
		if (s_stack_a->iv_numbers[1] > s_stack_a->iv_numbers[0]
			&& s_stack_a->iv_numbers[1] > s_stack_a->iv_numbers[2])
			handle_operators("rra", s_stack_a, s_stack_b);
		if (s_stack_a->iv_numbers[0] > s_stack_a->iv_numbers[1])
			handle_operators("sa", s_stack_a, s_stack_b);
		return (1);
	}
	return (0);
}

void	sort_stack_sub(int *iv_stack_sub, int i_size)
{
	int	i_count_sub;
	int	i_swap;
	int	i_count;

	i_count = -1;
	while (++i_count <= i_size)
	{
		i_count_sub = i_count + 1;
		while (i_count_sub <= i_size)
		{
			if (iv_stack_sub[i_count] > iv_stack_sub[i_count_sub])
			{
				i_swap = iv_stack_sub[i_count_sub];
				iv_stack_sub[i_count_sub] = iv_stack_sub[i_count];
				iv_stack_sub[i_count] = i_swap;
			}
			i_count_sub++;
		}
	}
}

void	search_target_pos(t_stack *stack_a, int *iv_stack_sub)
{
	int i_count = -1;
	int i_count_sub = -1;
	
	sort_stack_sub(iv_stack_sub, stack_a->i_top);
	while(++i_count <= stack_a->i_top)
	{
		i_count_sub = -1;
		while(++i_count_sub <=stack_a->i_top)
		{
			if(stack_a->iv_numbers[i_count] == iv_stack_sub[i_count_sub])
				stack_a->iv_target_position_a[i_count] = i_count_sub;  	
		}	
	}
	// while ()
}
