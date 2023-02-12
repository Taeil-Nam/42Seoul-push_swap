/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:51:44 by tnam              #+#    #+#             */
/*   Updated: 2023/02/12 17:56:51 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define NULLPTR 0

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
	int		argc;
	char	**argv;
	size_t	total_num_count;
	long	num_l;
}			t_var;

void	ft_error(void);

#endif