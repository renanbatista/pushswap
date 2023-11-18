/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:54:02 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/17 23:27:46 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: validate params
// TODO: move parans to stack_a
// TODO: create alg for execute moviments
// TODO: create moviments
// TODO: validate performance
// TODO: write tests.

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*s_stack_a;
	t_stack	*s_stack_b;
	int	*iv_stack_sub;

	s_stack_a = start_stack(argc, argc - 2);
	s_stack_b = start_stack(argc, -1);
	iv_stack_sub = ft_calloc(sizeof(int), 1);
	if (!handle_validation(argc, argv, s_stack_a, iv_stack_sub))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (!s_stack_a)
		return (0);
	search_target_pos(s_stack_a, iv_stack_sub);
	// if(!handle_sort(stack_a, stack_a, stack_sub))
	// {
	// 	make_free(stack_a, stack_b, stack_sub);
	// 	return (0);
	// }
	for (int index = 0; index <= s_stack_a->i_top; index++)
	{		
		printf("\nindex: %d", s_stack_a->iv_numbers[index]);
		printf(", targe_position: %d", s_stack_a->iv_target_position_a[index]);
	}
	// for (int index = 0; index <= stack_a->top; index++)
	// 	printf("\n%d", stack_sub[index]);
	// check_number_of_values(stack_a, stack_b);
	// printf("\nStack A:");
	// for (int index = 0; index <= stack_a->top; index++)
	// 	printf("\n%d", stack_a->vec[index]);
	// printf("\nStack B:");
	// for(int index = 0; index <= stack_b->top; index++)
	// 	printf("\n%d", stack_b->vector[index]);
	make_free(s_stack_a, s_stack_b, iv_stack_sub);
	return (1);
}
