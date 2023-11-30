/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cost_move_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:53:25 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/25 19:56:15 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_best_for_move(t_stack *stack_b)
{
	int	index;
	int	index_to_move;
	int	cost_move_minor;
	int	swap_cost_move_minor;

	index = -1;
	cost_move_minor = __INT_MAX__;
	while (++index <= stack_b->top_position)
	{
		swap_cost_move_minor = 0;
		if (stack_b->cost_move_a[index] < 0)
			swap_cost_move_minor += stack_b->cost_move_a[index] * -1;
		else
			swap_cost_move_minor += stack_b->cost_move_a[index];
		if (stack_b->cost_move_b[index] < 0)
			swap_cost_move_minor += stack_b->cost_move_b[index] * -1;
		else
			swap_cost_move_minor += stack_b->cost_move_b[index];
		if (cost_move_minor > swap_cost_move_minor)
		{
			cost_move_minor = swap_cost_move_minor;
			index_to_move = index;
		}
	}
	return (index_to_move);
}
