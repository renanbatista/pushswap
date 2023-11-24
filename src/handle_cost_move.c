#include "../include/push_swap.h"

int	check_cost_move_b(int index_move, t_stack *stack_b)
{
	int	midlle_index;

	midlle_index = stack_b->top_position / 2;
	if (index_move > midlle_index)
		return ((stack_b->top_position - index_move + 1) * -1);
	else
		return (index_move);
}

int	check_cost_move_a(int index_move, t_stack *stack_a, t_stack *stack_b)
{
	int	midlle_index;
	int	index;
	int	top_a_b;

	index = 0;
	top_a_b = stack_a->top_position + stack_b->top_position + 1;
	midlle_index = stack_a->top_position / 2;
	while (index <= stack_a->top_position)
	{
		if (stack_a->target_position_a[index] > stack_b->target_position_a[index_move]
			|| top_a_b == stack_b->target_position_a[index_move])
			break ;
		index++;
	}
	if (index <= midlle_index)
		return (index);
	else
		return ((stack_a->top_position - (index + 1)) * -1);
}

int	check_best_for_move(t_stack *stack_b)
{
	int	index;
	int	index_to_move;
	int	cost_move_minor;
	int	swap_cost_move_minor;

	index = 0;
	cost_move_minor = __INT_MAX__;
	while (++index <= stack_b->top_position)
	{
		swap_cost_move_minor = 0;
		if (stack_b->cost_move_a[index] < 0)
			swap_cost_move_minor += stack_b->cost_move_a[index] * -1;
		else
			swap_cost_move_minor += stack_b->cost_move_a[index];
		if (stack_b->cost_move_b[index] < 0)
			swap_cost_move_minor += stack_b->cost_move_b[index] * -1;
		else
			swap_cost_move_minor += stack_b->cost_move_b[index];
		if (cost_move_minor > swap_cost_move_minor)
		{
			cost_move_minor = swap_cost_move_minor;
			index_to_move = index;
		}
	}
	return (index_to_move);
}

int	check_index_move(t_stack *stack_a, t_stack *stack_b)
{
	int	index;

	index = -1;
	while (++index <= stack_b->top_position)
	{
		stack_b->cost_move_b[index] = check_cost_move_b(index, stack_b);
		stack_b->cost_move_a[index] = check_cost_move_a(index, stack_a,
				stack_b);
	}
	return (check_best_for_move(stack_b));
}
