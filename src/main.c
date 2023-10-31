/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:54:02 by r-afonso          #+#    #+#             */
/*   Updated: 2023/10/30 16:36:36 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: validate parans
// TODO: move parans to stack_a
// TODO: create alg for execute moviments
// TODO: create moviments
// TODO: validate performance
// TODO: write tests.

#include "../include/push_swap.h"


int	main(int argc, char **argv)
{
	int *stack_a;
	int *stack_b;
	
	stack_b = ft_calloc(sizeof(int), argc);
	stack_a = ft_calloc(sizeof(int), argc);
	if (!handle_validation(argc, argv, stack_a, stack_b))
	{
		ft_printf("Error\n");
		return (1);
	}
	return (1);
}
