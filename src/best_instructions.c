/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:22:15 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/06 11:22:30 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instructions	instructions_init(void)
{
	t_instructions	instructions;
	instructions.ra = -1;
	instructions.rb = 0;
	instructions.rr = 0;
	instructions.rra = 0;
	instructions.rrb = 0;
	instructions.rrr = 0;
	instructions.sa = 0;
	instructions.sb = 0;
	instructions.ss = 0;
	instructions.pa = 0;
	instructions.pb = 0;
	instructions.total = 2147483647;
	return (instructions);
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
	if (num > b->number && num < b->last->number)
		return (calc_total(instructions));
	instructions = find_slot(instructions, num, b);
	if (instructions.rrb && instructions.rb)
		return (calc_total(instructions));
	instructions = biggest_smallest(instructions, num, b);
	if (instructions.rrb >= 0 || instructions.rb >= 0)
		return (calc_total(instructions));
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
		instructions[best] = instructions_init();
		instructions[best].ra += 1;
		instructions[best] = fill_instructions(a->number, b);
		if (instructions[0].total < instructions[1].total
			|| instructions[0].total == instructions[1].total)
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
