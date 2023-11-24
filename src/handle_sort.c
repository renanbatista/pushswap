#include "../include/push_swap.h"

int	check_is_order(t_stack *stack_a, t_stack *stack_b)
{
	int	index;

	index = -1;
	if (stack_b->top_position != -1)
		return (0);
	while (++index <= stack_a->top_position)
		if (index != stack_a->target_position_a[index])
			return (0);
	return (1);
}

void	first_move_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	max_index;

	index = 0;
	max_index = (stack_a->top_position + 1) / 2;
	while (index <= max_index && stack_a->top_position > 2)
	{
		if (stack_a->target_position_a[0] <= max_index)
		{
			handle_operators("pb", stack_a, stack_b);
			index++;
		}
		else
			handle_operators("ra", stack_a, stack_b);
	}
	index = -1;
	while (stack_a->top_position > 2)
		handle_operators("pb", stack_a, stack_b);
}
void	handle_move(int index, t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->cost_move_b[index] > 0)
		while (stack_b->cost_move_b[index] > 0 && --stack_b->cost_move_b[index])
			handle_operators("rb", stack_a, stack_b);
	else
		while (stack_b->cost_move_b[index] < 0 && ++stack_b->cost_move_b[index] != 0)
			handle_operators("rrb", stack_a, stack_b);
	if (stack_b->cost_move_a[index] > 0)
		while (stack_b->cost_move_a[index] > 0 && --stack_b->cost_move_a[index])
			handle_operators("ra", stack_a, stack_b);
	else
		while (stack_b->cost_move_a[index] < 0 && ++stack_b->cost_move_a[index] != 0)
			handle_operators("rra", stack_a, stack_b);
	handle_operators("pa", stack_a, stack_b);
	
}

int	handle_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	index_move;

	if (check_is_order(stack_a, stack_b))
		return (1);
	first_move_to_b(stack_a, stack_b);
	handle_order_three_values(stack_a, stack_b);
	index = -1;
	while (stack_b->top_position != -1)
	{
		index_move = check_index_move(stack_a, stack_b);
		handle_move(index, stack_a, stack_b);
	}
	return (1);
}
// TODO: ao final preciso checar se nao preciso dar rotate ou inverse rotate para colocar o index 0 no começo
