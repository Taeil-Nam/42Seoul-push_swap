/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:51:22 by tnam              #+#    #+#             */
/*   Updated: 2023/03/01 23:08:04 by tnam             ###   ########.fr       */
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
	if (check_dup_nums_and_is_sorted(&s_a) == TRUE)
		exit(EXIT_SUCCESS);
	sequencing_nums_in_stack_a(&s_a);
	if (s_a.max_size == 3)
		sort_3_nums(&s_a);
	else if (s_a.max_size == 5)
		sort_5_nums(&s_a, &s_b);
	else
		execute_algorithm(&s_a, &s_b);
	free(s_a.array);
	free(s_b.array);
	return (0);
}

void	sort_3_nums(t_stack *s_a)
{
	if (s_a->array[2] < s_a->array[1] && s_a->array[1] < s_a->array[0])
		return ;
	else if (s_a->array[2] < s_a->array[1] && s_a->array[2] < s_a->array[0])
	{
		instruction_sa(s_a);
		instruction_ra(s_a);
	}
	else if (s_a->array[2] < s_a->array[1] && s_a->array[2] > s_a->array[0])
		instruction_rra(s_a);
	else if (s_a->array[2] > s_a->array[1] && s_a->array[2] < s_a->array[0])
		instruction_sa(s_a);
	else if (s_a->array[2] > s_a->array[1] && s_a->array[1] < s_a->array[0])
		instruction_ra(s_a);
	else if (s_a->array[2] > s_a->array[1] && s_a->array[1] > s_a->array[0])
	{
		instruction_sa(s_a);
		instruction_rra(s_a);
	}
}

void	sort_5_nums(t_stack *s_a, t_stack *s_b)
{
	int	num_index;
	int	i;

	i = 0;
	while (i < 2)
	{
		move_min_nums_to_top(s_a);
		instruction_pb(s_a, s_b);
		i++;
	}
	sort_3_nums(s_a);
	while (stack_is_empty(s_b) == FALSE)
	{
		num_index = get_max_num_index(s_b);
		if (num_index == s_b->top)
			instruction_pa(s_a, s_b);
		else
		{
			instruction_rb(s_b);
			instruction_pa(s_a, s_b);
		}
	}
}

void	move_min_nums_to_top(t_stack *stack)
{
	int	min_num_index;
	int	count;

	count = 0;
	min_num_index = get_min_num_index(stack);
	if (min_num_index >= stack->top / 2)
		while (count++ < stack->top - min_num_index)
			instruction_ra(stack);
	else
		while (count++ <= min_num_index)
			instruction_rra(stack);
}

void	error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
