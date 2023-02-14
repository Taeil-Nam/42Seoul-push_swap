/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:51:22 by tnam              #+#    #+#             */
/*   Updated: 2023/02/14 12:56:50 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		ft_init_variables(int argc, char *argv[], t_var *var);
static void		ft_init_stack_a(t_var *var, t_s_a *s_a, t_s_b *s_b);

int	main(int argc, char *argv[])
{
	t_s_a	s_a;
	t_s_b	s_b;
	t_var	var;

	ft_init_variables(argc, argv, &var);
	ft_init_stack_a(&var, &s_a, &s_b);
	return (0);
}

static void	ft_init_variables(int argc, char *argv[], t_var *var)
{
	var->argc = argc;
	var->argv = argv;
	var->total_num_count = argc - 1;
	var->num_l = 0;
}

static void	ft_init_stack_a(t_var *var, t_s_a *s_a, t_s_b *s_b)
{
	size_t	i;

	s_a->nums_v = (int *)malloc(sizeof(int) * var->total_num_count);
	if (s_a == NULLPTR)
		exit(EXIT_FAILURE);
	s_b->nums_v = (int *)malloc(sizeof(int) * var->total_num_count);
	if (s_b == NULLPTR)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < var->total_num_count)
	{
		var->num_l = ft_argv_to_int(var->argv[i + 1]);
		if (var->num_l < INT_MIN || var->num_l > INT_MAX)
			ft_error();
		s_a->nums_v[i] = var->num_l;
		i++;
	}
	ft_check_dup_nums(var, s_a);
}
