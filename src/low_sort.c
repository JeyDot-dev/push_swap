/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 01:40:56 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/09/16 14:30:20 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_low(t_stack *a)
{
	int	index;
	int	smallest;
	int	i;

	index = 0;
	i = 0;
	smallest = a->number;
	while (a)
	{
		if (a->number < smallest)
		{
			index = i;
			smallest = a->number;
		}
		i++;
		a = a->next;
	}
	return (index);
}

void	low_sort(t_stack **a, t_stack **b)
{
	t_instructions	instructions;
	int				elements;

	if (check_order(*a) == 0)
		return ;
	elements = count_elements(*a);
	while (elements > 3)
	{
		instructions = instructions_init(*a, *b);
		instructions.ra = find_low(*a);
		cmd_processor(a, b, best_total(instructions));
		px(a, b, 'b');
		elements--;
	}
	three_sort(a);
}
