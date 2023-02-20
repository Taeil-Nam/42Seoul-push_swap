/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:33:07 by tnam              #+#    #+#             */
/*   Updated: 2023/02/20 20:16:37 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm(t_stack *s_a, t_stack *s_b)
{
	int	i;
	int	min_num;

	// 4. stack a가 빌 때까지 1, 2, 3 과정 수행.
	while (stack_is_empty(s_a) == FALSE)
	{
		// 1. stack a에서 가장 작은 수 찾기.
		i = s_a->bottom + 1;
		min_num = s_a->array[s_a->bottom];
		while (i <= s_a->top)
		{
			if (s_a->array[i] < min_num)
				min_num = s_a->array[i];
			i++;
		}

		// 2. stack a의 가장 작은 수가 top으로 오도록 ra 수행.
		while (s_a->array[s_a->top] != min_num)
			instruction_ra(s_a);

		// 3. pb 수행.
		instruction_pb(s_a, s_b);
	}

	// 5. stack b가 빌 때가지 pa 수행.
	while (stack_is_empty(s_b) == FALSE)
		instruction_pa(s_a, s_b);
}
