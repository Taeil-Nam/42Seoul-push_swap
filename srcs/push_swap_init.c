/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:52:10 by tnam              #+#    #+#             */
/*   Updated: 2023/02/16 19:33:01 by tnam             ###   ########.fr       */
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
	s_a->vector = (int *)malloc(sizeof(int) * var->argc - 1);
	if (s_a == NULL)
		exit(EXIT_FAILURE);
	s_b->vector = (int *)malloc(sizeof(int) * var->argc - 1);
	if (s_b == NULL)
		exit(EXIT_FAILURE);
	s_a->size = 0;
	s_b->size = 0;
	s_a->top = -1;
	s_b->top = -1;
	s_a->bottom = 0;
	s_b->bottom = 0;
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
			s_a->vector[v_idx] = num_l;
			s_a->size++;
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
			if (s_a->vector[j] == s_a->vector[i])
				error();
			i++;
		}
		j++;
		i = j + 1;
	}
}
