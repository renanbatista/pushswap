/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:54:02 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/26 02:03:59 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*stack_sub;

	stack_a = start_stack(argc, argc - 2);
	stack_b = start_stack(argc, -1);
	stack_sub = ft_calloc(sizeof(int), argc);
	if (!handle_validation(argc, argv, stack_a, stack_sub) && stack_a)
	{
		make_free(stack_a, stack_b, stack_sub);
		if (argc != 1)
			write(2, "Error\n", 6);
		return (0);
	}
	if (!stack_a)
		return (0);
	search_target_pos(stack_a, stack_sub);
	if (!handle_sort(stack_a, stack_b))
	{
		make_free(stack_a, stack_b, stack_sub);
		return (0);
	}
	make_free(stack_a, stack_b, stack_sub);
	return (1);
}
