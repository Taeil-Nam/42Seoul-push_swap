/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:51:22 by tnam              #+#    #+#             */
/*   Updated: 2023/02/16 19:23:19 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h> //
int	main(int argc, char *argv[])
{
	t_stack	s_a;
	t_stack	s_b;
	t_var	var;

	init_variables(argc, argv, &var);
	init_stack(&var, &s_a, &s_b);
	make_stack_a(&var, &s_a);
	for (int i = 0; i < s_a.size; i++)
	{
		printf("%d\n", s_a.vector[i]);
	}
	return (0);
}

void	error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
