/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:49:34 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/15 00:22:38 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/ft_printf.h"
#include <math.h>
#include <stdio.h>

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct s_stack
{
	int	*vec;
	int	top;
}		t_stack;

int		handle_validation(int argc, char **argv, t_stack *stack_a);
void	sort_stack(t_stack *a, t_stack *b);
int		exec_rotate_reverse(t_stack *stack);
int		exec_rotate(t_stack *stack);
int		exec_push(t_stack *stack_one, t_stack *stack_two);
int		exec_swap(t_stack *stack);
int		handle_moviments(char *action, t_stack *stack_a, t_stack *stack_b);

#endif