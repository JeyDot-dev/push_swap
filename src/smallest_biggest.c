/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_biggest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:26:23 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/06 15:22:19 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instructions	calc_rotations(int slot, int mid_point, t_instructions instructions)
{
	if (slot > 1 && mid_point > 1 &&  slot > mid_point)
	{
//	ft_printf("slot = %i\n", slot);
		instructions.rrb = slot - slot % mid_point;
		instructions.rb = -1;
		if (mid_point % 2)
			instructions.rrb += 1;
	}
	else if (slot > 1 && mid_point == 1)
	{
		instructions.rrb = 1;
		instructions.rb = -1;
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
	biggest_slot = 0;
	while (b && num > b->number)
	{
		if (b->number > biggest)
		{
			biggest_slot = try;
			biggest = b->number;
		}
		b = b->next;
		try++;
	}
	if (!b)
		instructions = calc_rotations(biggest_slot, count_elements(b), instructions);
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
	smallest_slot = 1;
	while (b && num < b->number)
	{
		if (b->number < smallest)
		{
			smallest_slot = try + 1;
			smallest = b->number;
		}
		b = b->next;
		try++;
	}
	if (!b)
		instructions = calc_rotations(smallest_slot, count_elements(b), instructions);
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
		else if (instructions.rrb == -1)
			instructions.rrb = 0;
	}
	return (instructions);
}
