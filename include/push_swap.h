/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:49:34 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/17 23:08:08 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/ft_printf.h"
#include <math.h>
#include <stdio.h>

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct s_stack
{
	int	*iv_numbers;
	int	i_top;
	int	*iv_target_position_a;
	int	i_cost;
}		t_stack;

t_stack	*start_stack(int argc, int top);
void	make_free(t_stack *stack_a, t_stack *stack_b, int *stack_ordened);
int	check_number_of_values(t_stack *stack_a, t_stack *stack_b);
int		handle_validation(int argc, char **argv, t_stack *stack_a,
			int *stack_ordened);
void	sort_stack(t_stack *a, t_stack *b);
int		exec_rotate_reverse(t_stack *stack);
int		exec_rotate(t_stack *stack);
int		exec_push(t_stack *stack_one, t_stack *stack_two);
int		exec_swap(t_stack *stack);
int		operators_handle(char *action, t_stack *stack_a, t_stack *stack_b);
void	sort_stack_sub(int *stack_sub, int size);
int		handle_sort(t_stack *stack_a, t_stack *stack_b, int *stack_sub);
int		handle_operators(char *action, t_stack *stack_a, t_stack *stack_b);
void	search_target_pos(t_stack *stack_a, int *stack_sub);

#endif