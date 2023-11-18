#include "../include/push_swap.h"

int	check_is_order(t_stack *s_stack)
{
	int	i_index;

	i_index = -1;
	while (++i_index <= s_stack->i_top)
		if (i_index != s_stack->iv_target_position_a[i_index])
			return (0);
	return (1);
}

void	move_middle_to_b(t_stack *s_stack_a, t_stack *s_stack_b)
{
	int	i_index;
	int	i_top_temp;
	int	i_middle_number;

	i_index = -1;
	i_top_temp = s_stack_a.i_top;
	i_middle_number = s_stack_a.iv_numbers[i_top_temp/2];
	while(++i_index <=  i_top_temp/ 2)
	{
		if(s_stack_a.iv_numbers[i_index] <= i_middle_number)
			handle_operators("pb", s_stack_a, s_stack_b);
		s_stack_b.iv_numbers[i_index] = s_stack_a.iv_numbers[i_index];

	}
}

int	handle_sort(t_stack *s_stack_a, t_stack *s_stack_b, int *iv_stack_sub)
{
	// int i_midlle_value;
	if(s_stack_b && iv_stack_sub)
		return (1);
	if(check_is_order(s_stack_a))
		return(1);
	return (0);

}
