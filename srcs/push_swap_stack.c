/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:31:11 by tnam              #+#    #+#             */
/*   Updated: 2023/02/17 17:19:26 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_push(t_stack *stack, int data)
{
	stack->top++;
	stack->array[stack->top] = data;
}

void	stack_print(t_stack *stack)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		ft_printf("[%d] : %d\n", i, stack->array[i]);
		i++;
	}
	ft_printf("Size = %d\n", stack->max_size);
}
