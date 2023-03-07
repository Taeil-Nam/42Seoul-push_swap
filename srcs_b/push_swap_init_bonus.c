/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:52:10 by tnam              #+#    #+#             */
/*   Updated: 2023/03/07 17:00:10 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	init_variables(int argc, char *argv[], t_var *var)
{
	var->argc = argc;
	var->argv = argv;
	var->argv_idx = 1;
	var->num_idx = 0;
	var->nums = NULL;
}

void	init_stack(t_var *var, t_stack *s_a, t_stack *s_b)
{
	s_a->max_size = init_get_stack_size(var);
	s_b->max_size = s_a->max_size;
	s_a->top = s_a->max_size - 1;
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
	int		size;

	size = 0;
	var->argv_idx = 1;
	while (var->argv_idx < var->argc)
	{
		var->nums = ft_split(var->argv[var->argv_idx], ' ');
		var->num_idx = 0;
		while (var->nums[var->num_idx])
		{
			size++;
			free(var->nums[var->num_idx]);
			var->num_idx++;
		}
		free(var->nums);
		var->argv_idx++;
	}
	return (size);
}

void	make_stack_a(t_var *var, t_stack *s_a)
{
	long	num_l;
	int		i;

	i = 1;
	var->argv_idx = 1;
	while (var->argv_idx < var->argc)
	{
		var->nums = ft_split(var->argv[var->argv_idx], ' ');
		var->num_idx = 0;
		while (var->nums[var->num_idx])
		{
			num_l = make_int(var->nums[var->num_idx]);
			s_a->array[s_a->max_size - i] = num_l;
			free(var->nums[var->num_idx]);
			var->num_idx++;
			i++;
		}
		free(var->nums);
		var->argv_idx++;
	}
}

int	check_dup_nums_and_is_sorted(t_stack *s_a)
{
	int		i;
	int		j;
	int		sorted_flag;

	i = 0;
	j = i + 1;
	sorted_flag = 1;
	while (i < s_a->max_size - 1)
	{
		while (j < s_a->max_size)
		{
			if (s_a->array[i] == s_a->array[j])
				error();
			if (s_a->array[i] < s_a->array[j])
				sorted_flag = 0;
			j++;
		}
		i++;
		j = i + 1;
	}
	return (sorted_flag);
}
