/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction_rr.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:39:43 by tnam              #+#    #+#             */
/*   Updated: 2023/03/07 18:23:21 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instruction_rra(t_stack *s_a)
{
	int	temp;
	int	i;

	temp = s_a->array[s_a->bottom];
	i = s_a->bottom;
	while (i < s_a->top)
	{
		s_a->array[i] = s_a->array[i + 1];
		i++;
	}
	s_a->array[s_a->top] = temp;
	write(1, "rra\n", 4);
}

void	instruction_rrb(t_stack *s_b)
{
	int	temp;
	int	i;

	temp = s_b->array[s_b->bottom];
	i = s_b->bottom;
	while (i < s_b->top)
	{
		s_b->array[i] = s_b->array[i + 1];
		i++;
	}
	s_b->array[s_b->top] = temp;
	write(1, "rrb\n", 4);
}

void	instruction_rrr(t_stack *s_a, t_stack *s_b)
{
	int	temp;
	int	i;

	temp = s_a->array[s_a->bottom];
	i = s_a->bottom;
	while (i < s_a->top)
	{
		s_a->array[i] = s_a->array[i + 1];
		i++;
	}
	s_a->array[s_a->top] = temp;
	temp = s_b->array[s_b->bottom];
	i = s_b->bottom;
	while (i < s_b->top)
	{
		s_b->array[i] = s_b->array[i + 1];
		i++;
	}
	s_b->array[s_b->top] = temp;
	write(1, "rrr\n", 4);
}
