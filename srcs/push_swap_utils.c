/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:52:10 by tnam              #+#    #+#             */
/*   Updated: 2023/02/14 13:03:16 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

long	ft_argv_to_int(char *s)
{
	t_atoi	atoi;

	ft_init_atoi_variables(&atoi);
	while (s[atoi.i] == '\t' || s[atoi.i] == '\n' || s[atoi.i] == '\v'
		|| s[atoi.i] == '\f' || s[atoi.i] == '\r' || s[atoi.i] == ' ')
		atoi.i++;
	while (s[atoi.i] == '+' || s[atoi.i] == '-')
	{
		if (s[atoi.i++] == '-')
			atoi.sign = -1;
		atoi.sign_count++;
		if (atoi.sign_count == 2)
			ft_error();
	}
	while (s[atoi.i] != '\0')
	{
		if ('0' <= s[atoi.i] && s[atoi.i] <= '9')
			atoi.result = (atoi.result * 10) + (s[atoi.i++] - '0');
		else
			ft_error();
	}
	return (atoi.sign * atoi.result);
}

void	ft_init_atoi_variables(t_atoi *atoi)
{
	atoi->i = 0;
	atoi->sign = 1;
	atoi->sign_count = 0;
	atoi->result = 0;
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
