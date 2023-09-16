/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_total.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:54:17 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/09/16 14:48:20 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instructions	simplify_total(t_instructions instructions)
{
	while (instructions.ra > 0 && instructions.rb > 0)
	{
		instructions.ra -= 1;
		instructions.rb -= 1;
		instructions.rr += 1;
	}
	while (instructions.rra > 0 && instructions.rrb > 0)
	{
		instructions.rra -= 1;
		instructions.rrb -= 1;
		instructions.rrr += 1;
	}
	while (instructions.sa > 0 && instructions.sb > 0)
	{
		instructions.sa -= 1;
		instructions.sb -= 1;
		instructions.ss += 1;
	}
	return (instructions);
}

t_instructions	instructions_variant(t_instructions lel, int mode)
{
	if (mode == 1)
	{
		lel.ra = 0;
		lel.rb = 0;
	}
	else if (mode == 2)
	{
		lel.rra = 0;
		lel.rrb = 0;
	}
	else if (mode == 3)
	{
		lel.ra = 0;
		lel.rrb = 0;
	}
	else if (mode == 4)
	{
		lel.rra = 0;
		lel.rb = 0;
	}
	return (lel);
}

t_instructions	calc_total(t_instructions lel)
{
	lel.total = 0;
	lel = simplify_total(lel);
	lel.total += lel.ra;
	lel.total += lel.rb;
	lel.total += lel.rr;
	lel.total += lel.rra;
	lel.total += lel.rrb;
	lel.total += lel.rrr;
	lel.total += lel.sa;
	lel.total += lel.sb;
	lel.total += lel.ss;
	lel.total += lel.pa;
	lel.total += lel.pb;
	return (lel);
}

t_instructions	best_total(t_instructions lel)
{
	int				i;
	int				index;
	int				tmp;
	t_instructions	incts[4];

	i = -1;
	lel.rra = lel.size_a - lel.ra;
	lel.rrb = lel.size_b - lel.rb;
	while (++i < 4)
		incts[i] = calc_total(instructions_variant(lel, i + 1));
	i = 0;
	index = 0;
	tmp = incts[i].total;
	while (++i < 4)
	{
		if (incts[i].total < tmp)
			index = i;
	}
	return (incts[index]);
}
