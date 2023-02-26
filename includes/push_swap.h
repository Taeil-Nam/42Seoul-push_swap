/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:51:44 by tnam              #+#    #+#             */
/*   Updated: 2023/02/26 18:06:29 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	int		*array;
	int		max_size;
	int		top;
	int		bottom;
}			t_stack;

typedef struct s_var
{
	int		argc;
	char	**argv;
	int		argv_idx;
	int		num_idx;
	char	**nums;
}			t_var;

typedef struct s_atoi
{
	int		i;
	int		sign;
	int		sign_count;
	long	result;
}			t_atoi;

void	init_variables(int argc, char *argv[], t_var *var);
void	init_stack(t_var *var, t_stack *s_a, t_stack *s_b);
int		init_get_stack_size(t_var *var);
void	make_stack_a(t_var *var, t_stack *s_a);
void	algorithm(t_stack *s_a, t_stack *s_b);
void	sequencing_nums_in_stack(t_stack *s_a);
void	bubble_sort(int *sorted, int sorted_size);

void	error(void);

long	make_int(char *s);
void	init_atoi_variables(t_atoi *atoi);
void	check_dup_nums(t_stack *s_a);

void	stack_push(t_stack *stack, int data);
void	stack_pop(t_stack *stack);
void	stack_print(t_stack *stack);
bool	stack_is_empty(t_stack *stack);
bool	stack_is_full(t_stack *stack);

void	instruction_pa(t_stack *s_a, t_stack *s_b);
void	instruction_pb(t_stack *s_a, t_stack *s_b);

void	instruction_sa(t_stack *s_a);
void	instruction_sb(t_stack *s_b);
void	instruction_ss(t_stack *s_a, t_stack *s_b);

void	instruction_ra(t_stack *s_a);
void	instruction_rb(t_stack *s_b);
void	instruction_rr(t_stack *s_a, t_stack *s_b);

void	instruction_rra(t_stack *s_a);
void	instruction_rrb(t_stack *s_b);
void	instruction_rrr(t_stack *s_a, t_stack *s_b);

#endif