/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:33:07 by tnam              #+#    #+#             */
/*   Updated: 2023/02/26 18:11:43 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	# 사용할 알고리즘 = 모래시계
	## 모래시계 알고리즘 구현 단계
	1. 저장된 숫자들을 순서매긴 값으로 변경한다. (sequencing)
	2. 저장된 숫자들을 범위에 따라 나눈다.
		- 100개가 들어온 경우, 하위 20개, 그다음 20개x4.
	3. 스택 a를 ra하면서 top이 하위 20개 중에 하나인지 확인한다.
		- 하위 20개에 속할 경우 pb.
		2-1. pb 수행시 스택 b의 위에 저장할지 아래에 저장할지 정해서 저장한다.
		2-2. pb 수행 후, 다음 구간의 숫자 중 하나를 추가하여 검사한다.
*/

void	algorithm(t_stack *s_a, t_stack *s_b)
{
	sequencing_nums_in_stack(s_a);
	s_b->bottom = 0; // dummy code
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

void	sequencing_nums_in_stack(t_stack *s_a)
{
	int	*sorted;
	int	sorted_size;
	int	count;
	int	i;
	int	j;

	sorted_size = s_a->max_size;
	sorted = (int *)malloc(sizeof(int) * sorted_size);
	i = 0;
	j = s_a->top;
	while (i < sorted_size)
		sorted[i++] = s_a->array[j--];
	bubble_sort(sorted, sorted_size);
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
