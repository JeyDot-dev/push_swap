/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:22:15 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/08 03:36:17 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instructions	instructions_init(t_stack *a, t_stack *b)
{
	t_instructions	instructions;
	if (a)
		instructions.sizeA = count_elements(a);
	if (b)
		instructions.sizeB = count_elements(b);
	else
		instructions.sizeB = 0;
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
//			ft_printf("Find slot : ra:%i, rra:%i, rb:%i, rrb:%i\n", instructions.ra, instructions.rra, instructions.rb, instructions.rrb);
	return (instructions);
}
t_instructions	fill_instructions(int num, t_stack *b, t_instructions instructions)
{
//			ft_printf("---num = %i ---\nfill 1\n", num);
	if (num > b->number && num < b->last->number)
		return (best_total(instructions));
//			ft_printf("fill 2\n");
	instructions = find_slot(instructions, num, b);
	if (instructions.rrb || instructions.rb)
		return (best_total(instructions));
//			ft_printf("fill 3\n");
	instructions = biggest_smallest(instructions, num, b);
	if (instructions.rrb >= 0 || instructions.rb >= 0)
		return (best_total(instructions));
	//		ft_printf("fill 4\n");
	return (instructions_init(NULL, NULL));
}
t_instructions	best_instructions(t_stack *a, t_stack *b)
{
	t_instructions	instructions[2];
	int				best;
	int				ra;
	t_stack			*headA;

	best = 0;
	ra = -1;
	headA = a;
	instructions[0] = instructions_init(headA, b);
	instructions[1] = instructions_init(headA, b);
	while (a)
	{
		instructions[best] = instructions_init(headA, b);
		ra += 1;
		instructions[best].ra += ra;
		instructions[best] = fill_instructions(a->number, b, instructions[best]);
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
//	ft_printf("\n\ninstructions : %i\n\n", best);
	return (instructions[best]);
}
