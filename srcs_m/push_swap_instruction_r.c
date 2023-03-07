/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction_r.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:39:43 by tnam              #+#    #+#             */
/*   Updated: 2023/03/07 18:23:21 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instruction_ra(t_stack *s_a)
{
	int	temp;
	int	i;

	temp = s_a->array[s_a->top];
	i = s_a->top;
	while (i > s_a->bottom)
	{
		s_a->array[i] = s_a->array[i - 1];
		i--;
	}
	s_a->array[s_a->bottom] = temp;
	write(1, "ra\n", 3);
}

void	instruction_rb(t_stack *s_b)
{
	int	temp;
	int	i;

	temp = s_b->array[s_b->top];
	i = s_b->top;
	while (i > s_b->bottom)
	{
		s_b->array[i] = s_b->array[i - 1];
		i--;
	}
	s_b->array[s_b->bottom] = temp;
	write(1, "rb\n", 3);
}

void	instruction_rr(t_stack *s_a, t_stack *s_b)
{
	int	temp;
	int	i;

	temp = s_a->array[s_a->top];
	i = s_a->top;
	while (i > s_a->bottom)
	{
		s_a->array[i] = s_a->array[i - 1];
		i--;
	}
	s_a->array[s_a->bottom] = temp;
	temp = s_b->array[s_b->top];
	i = s_b->top;
	while (i > s_b->bottom)
	{
		s_b->array[i] = s_b->array[i - 1];
		i--;
	}
	s_b->array[s_b->bottom] = temp;
	write(1, "rr\n", 3);
}
