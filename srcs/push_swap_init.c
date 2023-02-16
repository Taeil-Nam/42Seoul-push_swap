/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:52:10 by tnam              #+#    #+#             */
/*   Updated: 2023/02/16 21:10:32 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_variables(int argc, char *argv[], t_var *var)
{
	var->argc = argc;
	var->argv = argv;
}

void	init_stack(t_var *var, t_stack *s_a, t_stack *s_b)
{
	s_a->max_size = init_get_stack_size(var);
	s_b->max_size = s_a->max_size;
	s_a->top = -1;
	s_b->top = -1;
	s_a->bottom = 0;
	s_b->bottom = 0;
	s_a->array = (int *)malloc(sizeof(int) * s_a->max_size);
	if (s_a == NULL)
		exit(EXIT_FAILURE);
	s_b->array = (int *)malloc(sizeof(int) * s_b->max_size);
	if (s_b == NULL)
		exit(EXIT_FAILURE);
}

int	init_get_stack_size(t_var *var)
{
	int		argv_idx;
	int		num_idx;
	int		size;
	char	**nums;

	size = 0;
	argv_idx = 1;
	while (argv_idx < var->argc)
	{
		nums = ft_split(var->argv[argv_idx], ' ');
		num_idx = 0;
		while (nums[num_idx])
		{
			size++;
			num_idx++;
		}
		argv_idx++;
	}
	return (size);
}

void	make_stack_a(t_var *var, t_stack *s_a)
{
	int		argv_idx;
	int		num_idx;
	int		v_idx;
	char	**nums;
	long	num_l;

	argv_idx = 1;
	v_idx = 0;
	while (argv_idx < var->argc)
	{
		nums = ft_split(var->argv[argv_idx], ' ');
		num_idx = 0;
		while (nums[num_idx])
		{
			num_l = make_int(nums[num_idx]);
			if (num_l < INT32_MIN || num_l > INT32_MAX)
				error();
			// To do:
			// - stack_push() 함수 한 줄로 변경.
			// - 겹치는 변수들 var 구조체에 넣어서 사용하기.
			s_a->array[v_idx] = num_l;
			s_a->max_size++;
			s_a->top++;
			v_idx++;
			num_idx++;
		}
		argv_idx++;
	}
	check_dup_nums(var, s_a);
}

void	check_dup_nums(t_var *var, t_stack *s_a)
{
	int		i;
	int		j;

	j = 0;
	i = j + 1;
	while (j < var->argc - 2)
	{
		while (i < var->argc - 1)
		{
			if (s_a->array[j] == s_a->array[i])
				error();
			i++;
		}
		j++;
		i = j + 1;
	}
}
