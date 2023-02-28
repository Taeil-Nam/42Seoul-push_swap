/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:56:24 by tnam              #+#    #+#             */
/*   Updated: 2023/02/28 15:48:07 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	execute_algorithm(t_stack *s_a, t_stack *s_b)
{
	stack_a_to_b(s_a, s_b);
	stack_b_to_a(s_a, s_b);
}

void	stack_a_to_b(t_stack *s_a, t_stack *s_b)
{
	int	pb_range;
	int	rb_range;

	pb_range = s_a->max_size / s_a->div;
	rb_range = pb_range / s_a->div;
	while (stack_is_empty(s_a) == FALSE)
	{
		if (s_a->array[s_a->top] <= pb_range)
		{
			instruction_pb(s_a, s_b);
			if (rb_range < s_b->array[s_b->top])
				instruction_rb(s_b);
			pb_range++;
			rb_range++;
			continue ;
		}
		instruction_ra(s_a);
	}
}

void	stack_b_to_a(t_stack *s_a, t_stack *s_b)
{
	int	max_num_index;
	int	count;

	while (stack_is_empty(s_b) == FALSE)
	{
		count = 0;
		max_num_index = get_max_num_index(s_b);
		if (max_num_index > s_b->top / 2)
			while (count++ < s_b->top - max_num_index)
				instruction_rb(s_b);
		else
			while (count++ <= max_num_index)
				instruction_rrb(s_b);
		instruction_pa(s_a, s_b);
	}
}

int	get_max_num_index(t_stack *s_b)
{
	int	max_num;
	int	max_num_index;
	int	i;

	max_num = -1;
	max_num_index = 0;
	i = 0;
	while (i <= s_b->top)
	{
		if (s_b->array[i] > max_num)
		{
			max_num = s_b->array[i];
			max_num_index = i;
		}
		i++;
	}
	return (max_num_index);
}
