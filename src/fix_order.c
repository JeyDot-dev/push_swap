/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 00:31:56 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/09/14 18:28:16 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_fix(int i, int ii, t_stack **a)
{
	while (i > 0 && ii > 0)
	{
		if (i < ii)
			rrx(a, 'a');
		else
			rx(a, 'a');
		i--;
		ii--;
	}
}

void	fix_order(t_stack **a)
{
	int		i;
	int		index;
	int		smallest;
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	smallest = tmp->number;
	index = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->number < smallest)
		{
			index = i;
			smallest = tmp->number;
		}
		i++;
		tmp = tmp->next;
	}
	i = count_elements(*a) - index;
	optimize_fix(i, index, a);
}
