/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:22:15 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/05 20:17:07 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instructions	instructions_init(void)
{
	ra = -1;
	rb = 0;
	rr = 0;
	rra = 0;
	rrb = 0;
	rrr = 0;
	sa = 0;
	sb = 0;
	ss = 0;
	pa = 0;
	pb = 0;
	total = 2147483647;
}
t_instructions	biggest(int num, t_stack *b, t_instructions instructions)
{
	int	biggest;
	int	try;
	int	mid_point'

	mid_point = count_elements(b) / 2;
	biggest = b->number;
	try = 0;
	instructions.rrb = -1;
	while (b && biggest < num)
	{
		if (try <= mid_point)
			instructions.rb = try;
		else
		{
			instructions.rb = -1;
			instructions.rrb = try - try % mid_point;
		}
		try++;
		b = b->next;
	}
	if (b && biggest < num && try > mid_point && mid_point % 2 == 1)
		instructions.rrb += 1;
	if (!b || biggest > num)
	{
		instructions.rrb = -1;
		instructions.rb = -1;
	}
		return(instructions);
}
t_instructions	calc_rotations(int slot, t_stack *b, t_instructions instructions)
{
	int	mid_point;

	mid_point = count_elements(b) / 2;
	if (slot > mid_point)
	{
		instructions->rrb = slot - slot % mid_point;
		instructions->rb = -1;
		if (mid_point % 2)
			instructions->rbb += 1;
	}
	else
	{
		instructions->rb = slot;
		instructions->rrb = -1;
	}
	return (instructions);
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
		instructions->rb = -1;
		instructions->rrb = -1;
	}
		return(instructions);
}
t_instructions	biggest_smallest(int num, t_stack *b, t_instructions instructions)
{
	int snapshot;
	int	highest_lowest;
	t_stack	*tmp;
	int	try;

	try = 0;
	snapshot = num - b->number;
	tmp = b;
	if (snapshot < 0)
		mult = -1;
	if (mult < 0 && b->last->num)
		
	while (b)
	{
		snapshot = b->number * mult;
		if (num - snapshot < 0)
			break ;
	}
	else


}
t_instructions	find_slot(t_instructions instructions, int num, t_stack *b)
{
	int				tries;
	int				try;

	tries = count_elements(b) / 2;
	try = 0;

	while (b->next && !(num < b->number && num > b->next->number))
	{
		b = b->next;
		try++;
		if (try <= tries)
			instructions.rb = try;
		else
		{
			instructions.rb = 0;
			instructions.rrb = try - try % tries;
		}
	}
	if (b->next && try > tries && tries % 2 == 1)
		instructions.rrb += 1;
	if (!b->next)
		instructions.rrb = 0;
	return (instructions);
}
t_instructions	fill_instructions(int num, t_stack *b)
{
	t_instructions	instructions;
	t_stack			temp_b;
	if (num > b->number && num < b->last->number)
		return (calc_total(instructions));
	instructions = find_slot(instructions, num, b);
	if (instructions.rrb && instructions.rb)
		return (calc_total(instructions));
	instructions = biggest_smallest(instructions, num, b);
	if (instructions.rrb >= 0 || instructions.rb >= 0)
	{
		if (instructions.rb == -1)
			instructions.rb = 0;
		else
			instructions.rrb = 0;
		return (calc_total(instructions));
	}
	return (instructions);

}
t_instructions	best_instructions(t_stack *a, t_stack *b)
{
	t_instructions	instructions[2];
	int				best;

	best = 0;
	instructions[0] = instructions_init();
	instructions[1] = instructions_init();
	while (a)
	{
		instructions[i]->ra += 1;
		instructions[i] = fill_instructions(a->number, b);
		instructions[i]->total = calculate_total(instructions[i]);
		if (instructions[0]->total < instructions[1]->total
			|| insctrions[0]->total == instructions[1]->total)
			best = 1;
		else
			best = 0;
		a = a->next;
	}
	if (best > 0)
		best = 1;
	else
		best = 0;
	return (instructions[best]);
}
