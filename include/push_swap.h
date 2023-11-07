/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:49:34 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/06 20:37:24 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/ft_printf.h"
#include <math.h>
#include <stdio.h>

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct s_control
{
	int *stack_a;
	int *stack_b;
	int size;
} t_control;

int handle_validation(int argc, char ** argv, int **stack_a);

#endif