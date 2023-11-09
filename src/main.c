/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:54:02 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/08 21:23:29 by r-afonso         ###   ########.fr       */
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
 
t_stack *start_stack(int argc, int top) 
{
    t_stack *stack;
	
	stack = ft_calloc(sizeof(t_stack), 1);
	stack->vector = ft_calloc(sizeof(int), argc);
	stack->top = top;
	stack->size_max = argc - 1;
	return (stack); 
}

// void	sort_stack(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	tmp;

// 	while (!is_empty(stack_a))
// 	{
// 		tmp = pop(stack_a);
// 		while (!is_empty(stack_b) && peek(stack_b) > tmp)
// 			push(stack_a, pop(stack_b));
// 		push(stack_b, tmp);
// 	}
// 	while (!is_empty(stack_b))
// 	{
// 		push(stack_a, pop(stack_b));
// 	}
// }

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = start_stack(argc, argc - 2);  
	stack_b = start_stack(argc, -1);
	if (!handle_validation(argc, argv, stack_a))
	{
		ft_printf("Error\n");
		return (1);
	}
	// sort_stack(stack_a, stack_b);
	// TEST
	// handle_moviments("sa",stack_a,stack_b);
	// handle_moviments("pb",stack_a,stack_b);
	// handle_moviments("pb",stack_a,stack_b);
	handle_moviments("ra",stack_a,stack_b);
	// handle_moviments("rr",stack_a,stack_b);
	printf("\nStack A:");
	for(int index = 0; index <= stack_a->top; index++)
		printf("\n%d", stack_a->vector[index]);
	printf("\nStack B:");
	for(int index = 0; index <= stack_b->top; index++)
		printf("\n%d", stack_b->vector[index]);
	free(stack_a->vector);
	free(stack_b->vector);
	free(stack_a);
	free(stack_b);
	return (1);
}
