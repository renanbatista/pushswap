/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:54:02 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/25 02:35:39 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: validate params
// TODO: move parans to stack_a
// TODO: create alg for execute moviments
// TODO: create moviments
// TODO: validate performance
// TODO: write tests.

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*stack_sub;

	stack_a = start_stack(argc, argc - 2);
	stack_b = start_stack(argc, -1);
	stack_sub = ft_calloc(sizeof(int), argc - 2);
	
	if (!handle_validation(argc, argv, stack_a, stack_sub))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (!stack_a)
		return (0);
	search_target_pos(stack_a, stack_sub);
	if (!handle_sort(stack_a, stack_b))
	{
		make_free(stack_a, stack_b);
		return (0);
	}
	ft_printf("\nStack A");
	ft_printf(", Top: %d", stack_a->top_position);
	for (int index = 0; index <= stack_a->top_position; index++)
	{
		ft_printf("\nIndex: %d", index);
		ft_printf(", number: %d", stack_a->numbers[index]);
		ft_printf(", targe_position: %d", stack_a->target_position_a[index]);
	}
	ft_printf("\n\nStack B");
	ft_printf(", Top: %d", stack_b->top_position);
	for (int index = 0; index <= stack_b->top_position; index++)
	{
		ft_printf(" \nIndex: %d", index);
		ft_printf(", number: %d", stack_b->numbers[index]);
		ft_printf(", targe_position: %d", stack_b->target_position_a[index]);
		ft_printf(", cost A: %d", stack_b->cost_move_a[index]);
		ft_printf(", cost B: %d", stack_b->cost_move_b[index]);
	}
	make_free(stack_a, stack_b);
	return (1);
}
