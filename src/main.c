/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:54:02 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/07 20:30:03 by r-afonso         ###   ########.fr       */
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
	return (stack); 
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int stack_size)
{
	int	tmp;

	while (!is_empty(stack_a))
	{
		tmp = pop(stack_a);
		while (!is_empty(stack_b) && peek(stack_b) > tmp)
			push(stack_a, pop(stack_b), stack_size);
		push(stack_b, tmp, stack_size);
	}
	while (!is_empty(stack_b))
	{
		push(stack_a, pop(stack_b), stack_size);
	}
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int		max_stack_size;
	stack_a = start_stack(argc, argc - 2);  
	stack_b = start_stack(argc, -1);
	max_stack_size = argc - 1;
	if (!handle_validation(argc, argv, stack_a))
	{
		ft_printf("Error\n");
		return (1);
	}
	sort_stack(stack_a, stack_b, max_stack_size);
	for(int index = 0; index < argc - 1; index++)
		printf("\n%d", stack_a->vector[index]);
	return (1);
}
