/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:51:22 by tnam              #+#    #+#             */
/*   Updated: 2023/03/02 16:53:49 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_stack	s_a;
	t_stack	s_b;
	t_var	var;

	if (argc == 1)
		return (0);
	init_variables(argc, argv, &var);
	init_stack(&var, &s_a, &s_b);
	make_stack_a(&var, &s_a);
	check_dup_nums_and_is_sorted(&s_a);
	read_instruction(&s_a, &s_b);
	check_is_sorted(&s_a, &s_b);
	free(s_a.array);
	free(s_b.array);
	return (0);
}

void	read_instruction(t_stack *s_a, t_stack *s_b)
{
	char	*line;

	while (TRUE)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		execute_instruction(s_a, s_b, line);
		free(line);
	}
}

void	execute_instruction(t_stack *s_a, t_stack *s_b, char *line)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		instruction_pa(s_a, s_b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		instruction_pb(s_a, s_b);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		instruction_sa(s_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		instruction_sb(s_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		instruction_ss(s_a, s_b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		instruction_ra(s_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		instruction_rb(s_b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		instruction_rr(s_a, s_b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		instruction_rra(s_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		instruction_rrb(s_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		instruction_rrr(s_a, s_b);
	else
		error();
}

void	check_is_sorted(t_stack *s_a, t_stack *s_b)
{
	int		i;
	int		j;
	int		sorted_flag;

	i = 0;
	j = i + 1;
	sorted_flag = 1;
	if (stack_is_empty(s_b) == FALSE)
		write(STDOUT_FILENO, "KO\n", 3);
	while (i < s_a->max_size - 1)
	{
		while (j < s_a->max_size)
		{
			if (s_a->array[i] < s_a->array[j])
				sorted_flag = 0;
			j++;
		}
		i++;
		j = i + 1;
	}
	if (sorted_flag == 1 && stack_is_empty(s_b) == TRUE)
		write(STDOUT_FILENO, "OK\n", 3);
	else if (sorted_flag == 0 && stack_is_empty(s_b) == TRUE)
		write(STDOUT_FILENO, "KO\n", 3);
}

void	error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
