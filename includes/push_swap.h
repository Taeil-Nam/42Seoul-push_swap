/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:51:44 by tnam              #+#    #+#             */
/*   Updated: 2023/02/13 15:41:09 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define NULLPTR 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack_a
{
	int	*nums_v;
}		t_s_a;

typedef struct s_stack_b
{
	int	*nums_v;
}		t_s_b;

typedef struct s_var
{
	int			argc;
	char		**argv;
	size_t		total_num_count;
	long		num_l;
}				t_var;

void		ft_error(void);
long		ft_argv_to_int(t_var *var, size_t j);
size_t		ft_check_sign(t_var *var, size_t j, size_t i, int *sign);
void		ft_check_dup_nums(t_var *var, t_s_a *s_a);

#endif