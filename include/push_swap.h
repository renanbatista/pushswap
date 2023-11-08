/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:49:34 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/07 20:26:32 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/ft_printf.h"
#include <math.h>
#include <stdio.h>

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct s_stack
{
	int *vector;
	int top;
} t_stack;

int handle_validation(int argc, char ** argv, t_stack *stack_a);
void sort_stack(t_stack *a, t_stack *b, int stack_size);
int	is_empty(t_stack *stack);
void	push(t_stack *stack, int value, int stack_size);
int	pop(t_stack *stack);
int	peek(t_stack *stack);

#endif