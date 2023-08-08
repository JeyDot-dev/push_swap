/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_biggest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:26:23 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/07 23:25:16 by jsousa-a         ###   ########.fr       */
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
		return(instructions);
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
//ft_printf("biggest_smallest : ra:%i, rra:%i, rb:%i, rrb:%i\n", instructions.ra, instructions.rra, instructions.rb,
//										instructions.rrb);
	return (instructions);
}
