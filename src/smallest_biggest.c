/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_biggest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:26:23 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/09/14 18:30:36 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instructions	biggest(int num, t_stack *b, t_instructions instructions)
{
	int	biggest;
	int	try;

	biggest = b->number;
	try = 0;
	instructions.rb = 0;
	while (b && num > b->number)
	{
		if (b->number > biggest)
		{
			instructions.rb = try;
			biggest = b->number;
		}
		b = b->next;
		try++;
	}
	if (b)
	{
		instructions.rb = -1;
		instructions.rrb = -1;
	}
	return (instructions);
}

t_instructions	smallest(int num, t_stack *b, t_instructions instructions)
{
	int	smallest;
	int	try;

	smallest = b->number;
	try = 1;
	instructions.rb = 1;
	while (b && num < b->number)
	{
		if (b->number < smallest)
		{
			instructions.rb = try;
			smallest = b->number;
		}
		b = b->next;
		try++;
	}
	if (b)
	{
		instructions.rb = -1;
		instructions.rrb = -1;
	}
	return (instructions);
}

t_instructions	biggest_smallest(t_instructions lel,
				int num, t_stack *b)
{
	if (num < b->number)
		lel = smallest(num, b, lel);
	else
		lel = biggest(num, b, lel);
	if (lel.rrb >= 0 || lel.rb >= 0)
	{
		if (lel.rb == -1)
			lel.rb = 0;
		else if (lel.rrb == -1)
			lel.rrb = 0;
	}
	return (lel);
}
