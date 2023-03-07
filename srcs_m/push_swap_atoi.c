/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:16:00 by tnam              #+#    #+#             */
/*   Updated: 2023/03/07 18:23:21 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	make_int(char *s)
{
	t_atoi	atoi;

	init_atoi_variables(&atoi);
	while (s[atoi.i] == '\t' || s[atoi.i] == '\n' || s[atoi.i] == '\v'
		|| s[atoi.i] == '\f' || s[atoi.i] == '\r' || s[atoi.i] == ' ')
		atoi.i++;
	if (s[atoi.i] == '+' || s[atoi.i] == '-')
	{
		if (s[atoi.i] == '-')
			atoi.sign = -1;
		atoi.i++;
	}
	if (s[atoi.i] == '\0' || s[atoi.i] == '+' || s[atoi.i] == '-')
		error();
	while (s[atoi.i] != '\0')
	{
		if ('0' <= s[atoi.i] && s[atoi.i] <= '9')
			atoi.result = (atoi.result * 10) + (s[atoi.i++] - '0');
		else
			error();
		if (atoi.sign * atoi.result < INT32_MIN
			|| atoi.sign * atoi.result > INT32_MAX)
			error();
	}
	return (atoi.sign * atoi.result);
}

void	init_atoi_variables(t_atoi *atoi)
{
	atoi->i = 0;
	atoi->sign = 1;
	atoi->sign_count = 0;
	atoi->result = 0;
}
