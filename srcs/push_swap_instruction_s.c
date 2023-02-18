/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction_s.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:39:43 by tnam              #+#    #+#             */
/*   Updated: 2023/02/18 18:08:23 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	instruction_sa(t_stack *s_a)
{
	int	temp;

	if (s_a->top < 1)
		return ;
	temp = s_a->array[s_a->top];
	s_a->array[s_a->top] = s_a->array[s_a->top - 1];
	s_a->array[s_a->top - 1] = temp;
}

void	instruction_sb(t_stack *s_b)
{
	int	temp;

	if (s_b->top < 1)
		return ;
	temp = s_b->array[s_b->top];
	s_b->array[s_b->top] = s_b->array[s_b->top - 1];
	s_b->array[s_b->top - 1] = temp;
}

void	instruction_ss(t_stack *s_a, t_stack *s_b)
{
	instruction_sa(s_a);
	instruction_sb(s_b);
}
