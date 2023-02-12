/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:51:22 by tnam              #+#    #+#             */
/*   Updated: 2023/02/12 17:59:17 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		ft_init_variables(int argc, char *argv[], t_var *var);
static void		ft_init_stack_a(t_var *var, t_s_a *s_a, t_s_a *s_b);

int	main(int argc, char *argv[])
{
	t_s_a	s_a;
	t_s_b	s_b;
	t_var	var;

	ft_init_variables(argc, argv, &var);
	ft_push_nums_into_stack_a(&var, &s_a, &s_b);
	/*
	1. 인자로 숫자들을 받는다.
	2. argc - 1 만큼의 크기를 가지는 정수 배열 2개를 동적 할당 받는다.
	3. 각 동적 배열은 스택 a와 b가 숫자들을 저장하는 배열이다.
	4. argv[1] 부터 argv[argc - 1] 까지, 각 문자열을 숫자로 변경하여 스택 a에 차례대로 저장한다. (ft_atoi() 필요할듯?)
	5. argv[1] = stack[0], argv[2] = stack[1]의 형식으로 저장한다.
	6. 만약 정수가 아니거나, 정수가 int 범위가 아니거나, 중복된 숫자가 있을 경우 예외 처리를 수행한다.
	*/
	return (0);
}

static void	ft_init_variables(int argc, char *argv[], t_var *var)
{
	var->argc = argc;
	var->argv = argv;
	var->total_num_count = argc - 1;
	var->num_l = 0;
}

static void	ft_init_stack_a(t_var *var, t_s_a *s_a, t_s_a *s_b)
{
	size_t	i;
	size_t	j;

	s_a->nums_v = (int *)malloc(sizeof(int) * var->total_num_count);
	if (s_a == NULLPTR)
		exit(EXIT_FAILURE);
	s_b->nums_v = (int *)malloc(sizeof(int) * var->total_num_count);
	if (s_b == NULLPTR)
		exit(EXIT_FAILURE);
	i = 0;
	j = 1;
	while (i < var->total_num_count)
	{
		// 에러 처리를 어디서, 어떻게 해야할지?
		var->num_l = ft_atoi(var->argv[j]);
		if (var->num_l)
		i++;
		j++;
	}
}
