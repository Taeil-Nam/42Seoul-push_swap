/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:52:10 by tnam              #+#    #+#             */
/*   Updated: 2023/02/13 15:37:13 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

long	ft_argv_to_int(t_var *var, size_t j)
{
	size_t	i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (var->argv[j][i] == '\t' || var->argv[j][i] == '\n'
		|| var->argv[j][i] == '\v' || var->argv[j][i] == '\f'
		|| var->argv[j][i] == '\r' || var->argv[j][i] == ' ')
		i++;
	i = ft_check_sign(var, j, i, &sign);
	while (var->argv[j][i] != '\0')
	{
		if ('0' <= var->argv[j][i] && var->argv[j][i] <= '9')
			result = (result * 10) + (var->argv[j][i++] - '0');
		else
			ft_error();
	}
	return (sign * result);
}

size_t	ft_check_sign(t_var *var, size_t j, size_t i, int *sign)
{
	int		sign_count;

	sign_count = 0;
	while (var->argv[j][i] == '+' || var->argv[j][i] == '-')
	{
		if (var->argv[j][i++] == '-')
			*sign = -1;
		sign_count++;
		if (sign_count == 2)
			ft_error();
	}
	return (i);
}

void	ft_check_dup_nums(t_var *var, t_s_a *s_a)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = j + 1;
	while (j < var->total_num_count - 1)
	{
		while (i < var->total_num_count)
		{
			if (s_a->nums_v[j] == s_a->nums_v[i])
				ft_error();
			i++;
		}
		j++;
		i = j + 1;
	}
}
