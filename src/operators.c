#include "../include/push_swap.h"

int	verify_r(t_stack *stack_a, t_stack *stack_b, char *action)
{
	if (!ft_strncmp("ra", action, 2))
	{
		if (exec_rotate(stack_a) && ft_printf("\nra"))
			return (1);
	}
	else if (!ft_strncmp("rb", action, 2))
	{
		if (exec_rotate(stack_b) && ft_printf("\nrb"))
			return (1);
	}
	else if (!ft_strncmp("rr", action, 2))
	{
		if (exec_rotate(stack_a) && exec_rotate(stack_b) && ft_printf("\nrr"))
			return (1);
	}
	return (0);
}

int	verify_rr(t_stack *stack_a, t_stack *stack_b, char *action)
{
	if (!ft_strncmp("rra", action, 3))
	{
		if (exec_rotate_reverse(stack_a) && ft_printf("\nrra"))
			return (1);
	}
	else if (!ft_strncmp("rrb", action, 3))
	{
		if (exec_rotate_reverse(stack_a) && ft_printf("\nrrb"))
			return (1);
	}
	else if (!ft_strncmp("rrr", action, 3))
	{
		if (exec_rotate_reverse(stack_a) && exec_rotate_reverse(stack_b)
			&& ft_printf("\nrrr"))
			return (1);
	}
	return (0);
}

int	verify_s(t_stack *stack_a, t_stack *stack_b, char *action)
{
	if (!ft_strncmp("sa", action, 2))
	{
		if (exec_swap(stack_a) && ft_printf("\nsa"))
			return (1);
	}
	else if (!ft_strncmp("sb", action, 2))
	{
		if (exec_swap(stack_b) && ft_printf("\nsb"))
			return (1);
	}
	else if (!ft_strncmp("ss", action, 2))
	{
		if (exec_swap(stack_a) && exec_swap(stack_b) && ft_printf("\nss"))
			return (1);
	}
	return (0);
}

int	verify_p(t_stack *stack_a, t_stack *stack_b, char *action)
{
	if (!ft_strncmp("pa", action, 2))
	{
		if (exec_push(stack_b, stack_a) && ft_printf("\npa"))
			return (1);
	}
	else if (!ft_strncmp("pb", action, 2))
	{
		if (exec_push(stack_a, stack_b) && ft_printf("\npb"))
			return (1);
	}
	return (0);
}

int	handle_moviments(char *action, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp("sa", action, 2) || !ft_strncmp("sb", action, 2)
		|| !ft_strncmp("ss", action, 2))
	{
		if (verify_s(stack_a, stack_b, action))
			return (1);
	}
	else if (!ft_strncmp("pa", action, 2) || !ft_strncmp("pb", action, 2))
	{
		if (verify_p(stack_a, stack_b, action))
			return (1);
	}
	else if (!ft_strncmp("ra", action, 2) || !ft_strncmp("rb", action, 2)
			|| !ft_strncmp("rr", action, 2))
	{
		if (verify_r(stack_a, stack_b, action))
			return (1);
	}
	else if (!ft_strncmp("rra", action, 3) || !ft_strncmp("rrb", action, 3)
			|| !ft_strncmp("rrr", action, 3))
	{
		if (verify_rr(stack_a, stack_b, action))
			return (1);
	}
	return (0);
}
