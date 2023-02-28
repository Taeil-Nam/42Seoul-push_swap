/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:33:07 by tnam              #+#    #+#             */
/*   Updated: 2023/02/28 15:10:41 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sequencing_nums_in_stack_a(t_stack *s_a)
{
	int	*sorted;
	int	sorted_size;
	int	i;
	int	j;

	sorted_size = s_a->max_size;
	sorted = (int *)malloc(sizeof(int) * sorted_size);
	i = 0;
	j = 0;
	while (i < sorted_size)
		sorted[i++] = s_a->array[j++];
	bubble_sort(sorted, sorted_size);
	change_nums_in_stack_to_sorted(s_a, sorted);
}

void	bubble_sort(int *sorted, int sorted_size)
{
	int	i;
	int	j;
	int	cycle;
	int	temp;

	i = 0;
	j = i + 1;
	cycle = 0;
	while (cycle < sorted_size - 1)
	{
		while (j < sorted_size - cycle)
		{
			if (sorted[i] > sorted[j])
			{
				temp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = temp;
			}
			i++;
			j++;
		}
		i = 0;
		j = i + 1;
		cycle++;
	}
}

void	change_nums_in_stack_to_sorted(t_stack *s_a, int *sorted)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (count < s_a->max_size)
	{
		while (TRUE)
		{
			if (s_a->array[i] == sorted[j])
			{
				s_a->array[i] = j;
				break ;
			}
			j++;
		}
		i++;
		j = 0;
		count++;
	}
	free(sorted);
}
