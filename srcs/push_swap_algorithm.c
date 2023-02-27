/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:33:07 by tnam              #+#    #+#             */
/*   Updated: 2023/02/27 22:11:19 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm(t_stack *s_a, t_stack *s_b)
{
	sequencing_nums_in_stack(s_a);
	execute_algorithm(s_a, s_b);
}

void	sequencing_nums_in_stack(t_stack *s_a)
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

void	execute_algorithm(t_stack *s_a, t_stack *s_b)
{
	int	pb_range;

	pb_range = s_a->max_size / s_a->chunk;
	while (stack_is_empty(s_a) == FALSE)
	{
		if (s_a->array[s_a->top] <= pb_range)
		{
			instruction_pb(s_a, s_b);
			if (s_b->array[s_b->top] < s_b->array[s_b->top - 1])
				instruction_rb(s_b);
			pb_range++;
			continue ;
		}
		instruction_ra(s_a);
	}
}

/*
	# 사용 알고리즘 = 모래시계
	## 모래시계 알고리즘 구현 단계
	1. 저장된 숫자들을 순서매긴 값으로 변경한다. (sequencing)
	2. 저장된 숫자들을 범위에 따라 나눈다.
		- 100개가 들어온 경우, 하위 20개, 그다음 20개x4.
	3. 스택 a를 ra하면서 top이 하위 20개 중에 하나인지 확인한다.
		- 하위 20개에 속할 경우 pb.
		2-1. pb 수행시 스택 b의 위에 저장할지 아래에 저장할지 정해서 저장한다.
			- 저장 조건 판별 필요.
		2-2. pb 수행 후, 범위를 1 추가하여 검사한다.
	4. 스택 b에 숫자가 전부 저장되었다면 모래 시계 모양이 되었을 것이다.
	5. 스택 b에서 가장 큰 숫자를 찾아 스택 a로 넘긴다.
	6. 정렬 완료.
*/