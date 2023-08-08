/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 01:58:20 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/08 03:43:23 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	three_sort(t_stack **a)
{
	int	num[3];
	while(check_order(*a))
	{
		num[0] = (*a)->number;
		num[1] = (*a)->next->number;
		num[2] = (*a)->last->number;

		if (num[0] > num[1])
		{
			if (num[0] < num[2])
				sx(a,'a');
			else if (num[1] > num[2])
				sx(a, 'a');
			else
				rx(a, 'a');
		}
		else if (num[0] < num[1])
		{
			if (num[0] < num[2])
				sx(a, 'a');
			else
				rrx(a, 'a');
		}
//		print_stacks(*a, NULL);
	}
}
