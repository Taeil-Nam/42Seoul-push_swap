/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction_s_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:39:43 by tnam              #+#    #+#             */
/*   Updated: 2023/03/02 14:57:28 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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
	int	temp;

	if (s_a->top >= 1 && s_b->top < 1)
	{
		temp = s_a->array[s_a->top];
		s_a->array[s_a->top] = s_a->array[s_a->top - 1];
		s_a->array[s_a->top - 1] = temp;
	}
	else if (s_b->top >= 1 && s_a->top < 1)
	{
		temp = s_b->array[s_b->top];
		s_b->array[s_b->top] = s_b->array[s_b->top - 1];
		s_b->array[s_b->top - 1] = temp;
	}
	else if (s_a->top >= 1 && s_b->top >= 1)
	{
		temp = s_b->array[s_b->top];
		s_b->array[s_b->top] = s_b->array[s_b->top - 1];
		s_b->array[s_b->top - 1] = temp;
		temp = s_a->array[s_a->top];
		s_a->array[s_a->top] = s_a->array[s_a->top - 1];
		s_a->array[s_a->top - 1] = temp;
	}
}
