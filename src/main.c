/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:54:02 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/15 00:58:21 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: validate params
// TODO: move parans to stack_a
// TODO: create alg for execute moviments
// TODO: create moviments
// TODO: validate performance
// TODO: write tests.

#include "../include/push_swap.h"
#include <threads.h>

t_stack	*start_stack(int argc, int top)
{
	t_stack	*stack;

	stack = ft_calloc(sizeof(t_stack), 1);
	stack->vec = ft_calloc(sizeof(int), argc);
	stack->top = top;
	return (stack);
}

int	check_number_of_values(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top == 1 && stack_a->vec[0] < stack_a->vec[1])
		return (1);
	else if (stack_a->top == 1 && stack_a->vec[0] >= stack_a->vec[1])
	{
		handle_moviments("sa", stack_a, stack_b);
		return (1);
	}
	else if (stack_a->top == 2)
	{
		if (stack_a->vec[0] > stack_a->vec[1]
			&& stack_a->vec[0] > stack_a->vec[2])
			handle_moviments("ra", stack_a, stack_b);
		if (stack_a->vec[1] > stack_a->vec[0]
			&& stack_a->vec[1] > stack_a->vec[2])
			handle_moviments("rra", stack_a, stack_b);
		if (stack_a->vec[0] > stack_a->vec[1])
			handle_moviments("sa", stack_a, stack_b);
		return (1);
	}
	return (0);
}
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = start_stack(argc, argc - 2);
	stack_b = start_stack(argc, -1);
	if (!handle_validation(argc, argv, stack_a))
	{
		ft_printf("Error\n");
		return (1);
	}
	check_number_of_values(stack_a, stack_b);
	// printf("\nStack A:");
	// for (int index = 0; index <= stack_a->top; index++)
	// 	printf("\n%d", stack_a->vec[index]);
	// printf("\nStack B:");
	// for(int index = 0; index <= stack_b->top; index++)
	// 	printf("\n%d", stack_b->vector[index]);
	free(stack_a->vec);
	free(stack_b->vec);
	free(stack_a);
	free(stack_b);
	return (1);
}
