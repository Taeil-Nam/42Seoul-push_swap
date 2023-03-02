/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction_p.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:39:43 by tnam              #+#    #+#             */
/*   Updated: 2023/02/19 17:53:28 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	instruction_pa(t_stack *s_a, t_stack *s_b)
{
	int	temp;

	if (stack_is_empty(s_b) == TRUE)
		return ;
	temp = s_b->array[s_b->top];
	stack_pop(s_b);
	stack_push(s_a, temp);
	write(1, "pa\n", 3);
}

void	instruction_pb(t_stack *s_a, t_stack *s_b)
{
	int	temp;

	if (stack_is_empty(s_a) == TRUE)
		return ;
	temp = s_a->array[s_a->top];
	stack_pop(s_a);
	stack_push(s_b, temp);
	write(1, "pb\n", 3);
}
