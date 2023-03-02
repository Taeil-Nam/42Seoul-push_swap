/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:31:11 by tnam              #+#    #+#             */
/*   Updated: 2023/02/18 18:06:20 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_push(t_stack *stack, int data)
{
	if (stack_is_full(stack) == TRUE)
		return ;
	stack->top++;
	stack->array[stack->top] = data;
}

void	stack_pop(t_stack *stack)
{
	if (stack_is_empty(stack) == TRUE)
		return ;
	stack->top--;
}

void	stack_print(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->top - i >= 0)
	{
		ft_printf("[%d] : %d\n", stack->top - i, stack->array[stack->top - i]);
		i++;
	}
	ft_printf("\nTop : %d\n", stack->top);
}

bool	stack_is_empty(t_stack *stack)
{
	if (stack->top == -1)
		return (TRUE);
	else
		return (FALSE);
}

bool	stack_is_full(t_stack *stack)
{
	if (stack->top == stack->max_size - 1)
		return (TRUE);
	else
		return (FALSE);
}
