/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:33:07 by tnam              #+#    #+#             */
/*   Updated: 2023/02/22 21:45:02 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm(t_stack *s_a, t_stack *s_b)
{
	/*
	# 사용할 알고리즘 = 모래시계
	## 모래시계 알고리즘 동작 과정
	1. 스택 a에서 스택 b로 데이터들을 특정 조건에 맞게 옮긴다.
	2. 스택 b에 저장된 데이터들의 형태가 모래시계처럼 나타난다.
	3. 스택 b에서 가장 큰 데이터를 하나씩 찾아서 스택 a로 옮긴다.
	4. 스택 a에 데이터들이 정렬이 완료된다.

	## 모래시계 알고리즘 고려사항
	- 스택 a의 데이터들을 확인하면서 자신이 몇 번째로 큰 데이터인지 인덱스화 시킨다.
	Ex) 숫자 1, 2, 3, 5, 4가 저장된 경우 -> 0, 1, 2, 4, 3 으로 인덱스화 시킴.
	- 스택 a에서 스택 b로 데이터를 어떤 조건으로 옮겨야 스택 b에 모래시계처럼 쌓일지 찾는다.
	*/
}
