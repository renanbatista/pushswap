/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:54:02 by r-afonso          #+#    #+#             */
/*   Updated: 2023/10/25 19:41:21 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argv, char **argc)
{
	if (argv == 1 && argc)
	{
		ft_printf("\n");
		return(1);
	}
	if(!handle_validation(argc))
	{
		ft_printf("Error");
		return (1);
	}
	return (1);
}