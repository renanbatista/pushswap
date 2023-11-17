#include "../include/push_swap.h"

int	check_is_order(t_stack *stack, int *stack_sub)
{
	int	index;

	index = -1;
	while (++index <= stack->top)
		if (stack->vec[index] != stack_sub[index])
			return (0);
	return (1);
}

int	handle_sort(t_stack *stack_a, t_stack *stack_b, int *stack_sub)
{
	int midlle_value;

	if(check_is_order(stack_a, stack_sub))
		return(1);
	
	
	return (0);
}
