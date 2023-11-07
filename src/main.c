/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:54:02 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/06 20:40:51 by r-afonso         ###   ########.fr       */
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
	t_control *control;
	
	control = ft_calloc(sizeof(t_control), 1);
	control->stack_b = ft_calloc(sizeof(int), argc);
	control->stack_a = ft_calloc(sizeof(int), argc);
	if (!handle_validation(argc, argv, &control->stack_a))
	{
		ft_printf("Error\n");
		return (1);
	}
	for(int index = 0; index < argc - 1; index++)
	{
		printf("\n%d", control->stack_a[index]);
	}
	return (1);
}
