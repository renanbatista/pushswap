/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:24:24 by r-afonso          #+#    #+#             */
/*   Updated: 2023/11/07 22:23:58 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	exec_swap(int *stack)
{
}

int	exec_swap(int *stack)
{
}

int exec_push(t_stack *stack_one, t_stack *stack_two)
{
	
}

int exec_rotate(t_stack *stack_one, t_stack *stack_two)
{
	
}

int	continuous_r_cases(char *action, t_stack stack_a, t_stack stack_b,
		int max_stack_size)
{
	if (ft_strncmp("sa", action, 2))
		exec_swap(stack_a.vector);
	else if (ft_strncmp("sb", action, 2))
		exec_swap(stack_a.vector);
}

int	handle_moviments(char *action, t_stack stack_a, t_stack stack_b,
		int max_stack_size)
{
	if (ft_strncmp("sa", action, 2))
		exec_swap(stack_a.vector);
	else if (ft_strncmp("sb", action, 2))
		exec_swap(stack_a.vector);
	else if (ft_strncmp("ss", action, 2))
	{
		exec_swap(stack_a.vector);
		exec_swap(stack_b.vector);
	}
	else if (ft_strncmp("pa", action, 2))
		exec_push(stack_a, stack_b);
	else if (ft_strncmp("pb", action, 2))
		exec_push(stack_b, stack_a);
	else if (ft_strncmp("ra", action, 2))
		exec_rotate(stack_b, stack_a);
	else if (ft_strncmp("rb", action, 2))
		exec_rotate(stack_a, stack_b);
	else if (ft_strncmp("rr", action, 2) || ft_strncmp("rra", action, 3)
			|| ft_strncmp("rrb", action, 2) || ft_strncmp("rrr", action, 2))
		continuous_r_cases(action, stack_a, stack_b, max_stack_size);
}
