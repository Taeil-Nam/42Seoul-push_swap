/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:51:44 by tnam              #+#    #+#             */
/*   Updated: 2023/02/16 19:11:56 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	int		*vector;
	int		size;
	int		top;
	int		bottom;
}			t_stack;

typedef struct s_var
{
	int			argc;
	char		**argv;
}				t_var;

typedef struct s_atoi
{
	int			i;
	int			sign;
	int			sign_count;
	long		result;
}				t_atoi;

void		init_variables(int argc, char *argv[], t_var *var);
void		init_stack(t_var *var, t_stack *s_a, t_stack *s_b);
void		make_stack_a(t_var *var, t_stack *s_a);

void		error(void);

long		make_int(char *s);
void		init_atoi_variables(t_atoi *atoi);
void		check_dup_nums(t_var *var, t_stack *s_a);

#endif