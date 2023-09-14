/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:22:15 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/09/14 18:32:32 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instructions	instructions_init(t_stack *a, t_stack *b)
{
	t_instructions	instructions;

	if (a)
		instructions.size_a = count_elements(a);
	if (b)
		instructions.size_b = count_elements(b);
	else
		instructions.size_b = 0;
	instructions.ra = 0;
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
	instructions.total = 2146483647;
	return (instructions);
}

t_instructions	find_slot(t_instructions instructions, int num, t_stack *b)
{
	instructions.rb = 1;
	while (b->next && !(num < b->number && num > b->next->number))
	{
		b = b->next;
		instructions.rb += 1;
	}
	if (!b->next)
	{
		instructions.rrb = 0;
		instructions.rb = 0;
	}
	return (instructions);
}

t_instructions	fill_instructions(int num, t_stack *b, t_instructions lel)
{
	if (num > b->number && num < b->last->number)
		return (best_total(lel));
	lel = find_slot(lel, num, b);
	if (lel.rrb || lel.rb)
		return (best_total(lel));
	lel = biggest_smallest(lel, num, b);
	if (lel.rrb >= 0 || lel.rb >= 0)
		return (best_total(lel));
	return (instructions_init(NULL, NULL));
}

t_instructions	best_instructions(t_stack *a, t_stack *b)
{
	t_instructions	instructions[2];
	int				best;
	int				ra;
	t_stack			*head_a;

	best = 0;
	ra = -1;
	head_a = a;
	instructions[0] = instructions_init(head_a, b);
	instructions[1] = instructions_init(head_a, b);
	while (a)
	{
		instructions[best] = instructions_init(head_a, b);
		ra += 1;
		instructions[best].ra += ra;
		instructions[best] = fill_instructions(a->number, b,
				instructions[best]);
		if (instructions[0].total < instructions[1].total
			|| instructions[0].total == instructions[1].total)
			best = 1;
		else
			best = 0;
		a = a->next;
	}
	if (best > 0)
		best = 0;
	else
		best = 1;
	return (instructions[best]);
}
