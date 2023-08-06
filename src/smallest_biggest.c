/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_biggest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:26:23 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/06 11:23:55 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instructions	calc_rotations(int slot, t_stack *b, t_instructions instructions)
{
	int	mid_point;

	mid_point = count_elements(b) / 2;
	if (slot > mid_point)
	{
		instructions.rrb = slot - slot % mid_point;
		instructions.rb = -1;
		if (mid_point % 2)
			instructions.rrb += 1;
	}
	else
	{
		instructions.rb = slot;
		instructions.rrb = -1;
	}
	return (instructions);
}
t_instructions	biggest(int num, t_stack *b, t_instructions instructions)
{
	int	biggest;
	int	biggest_slot;
	int	try;
	biggest = b->number;
	try = 0;
	while (b && num > b->number)
	{
		if (b->number > biggest)
		{
			biggest_slot = try;
			biggest = b->number;
		}
		b = b->next;
	}
	if (!b)
		calc_rotations(biggest_slot, b, instructions);
	else
	{
		instructions.rb = -1;
		instructions.rrb = -1;
	}
		return(instructions);
}
t_instructions	smallest(int num, t_stack *b, t_instructions instructions)
{
	int	smallest;
	int	smallest_slot;
	int	try;
	smallest = b->number;
	try = 0;
	while (b && num < b->number)
	{
		if (b->number < smallest)
		{
			smallest_slot = try;
			smallest = b->number;
		}
		b = b->next;
	}
	if (!b)
		calc_rotations(smallest_slot, b, instructions);
	else
	{
		instructions.rb = -1;
		instructions.rrb = -1;
	}
		return(instructions);
}
t_instructions	biggest_smallest(t_instructions instructions, int num, t_stack *b)
{
	if (num < b->number)
		instructions = smallest(num, b, instructions);
	else
		instructions = biggest(num, b, instructions);
	if (instructions.rrb >= 0 || instructions.rb >= 0)
	{
		if (instructions.rb == -1)
			instructions.rb = 0;
		else
			instructions.rrb = 0;
	}
	return (instructions);
}
