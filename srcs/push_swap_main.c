/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:51:22 by tnam              #+#    #+#             */
/*   Updated: 2023/02/18 18:27:46 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	s_a;
	t_stack	s_b;
	t_var	var;

	init_variables(argc, argv, &var);
	init_stack(&var, &s_a, &s_b);
	make_stack_a(&var, &s_a);
	instruction_pb(&s_a, &s_b);
	instruction_pb(&s_a, &s_b);
	instruction_pb(&s_a, &s_b);
	instruction_rra(&s_a);
	instruction_rrb(&s_b);
	instruction_rrr(&s_a, &s_b);
	stack_print(&s_a);
	ft_printf("-----\n");
	stack_print(&s_b);
	return (0);
}

void	error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
