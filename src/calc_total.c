/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_total.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:54:17 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/08 03:37:23 by jsousa-a         ###   ########.fr       */
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
t_instructions	instructions_variant(t_instructions instructions, int mode)
{
	if (mode == 1)
	{
		instructions.ra = 0;
		instructions.rb = 0;
	}
	else if(mode == 2)
	{
		instructions.rra = 0;
		instructions.rrb = 0;
	}
	else if(mode == 3)
	{
		instructions.ra = 0;
		instructions.rrb = 0;
	}
	else if(mode == 4)
	{
		instructions.rra = 0;
		instructions.rb = 0;
	}
	return (instructions);
}
/*
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	score;
	int	total;
	*/
t_instructions	calc_total(t_instructions instructions)
{
	instructions.total = 0;
	instructions = simplify_total(instructions);
	instructions.total += instructions.ra;
	instructions.total += instructions.rb;
	instructions.total += instructions.rr;
	instructions.total += instructions.rra;
	instructions.total += instructions.rrb;
	instructions.total += instructions.rrr;
	instructions.total += instructions.sa;
	instructions.total += instructions.sb;
	instructions.total += instructions.ss;
	instructions.total += instructions.pa;
	instructions.total += instructions.pb;
	return (instructions);
}
t_instructions	best_total(t_instructions instructions)
{	
	int	i;
	int	index;
	int	tmp;
	t_instructions	incts[4];

	i = -1;
	instructions.rra = instructions.sizeA - instructions.ra;
	instructions.rrb = instructions.sizeB - instructions.rb;
//	ft_printf("--PREcalc : ra:%i, rra:%i, rb:%i, rrb:%i, rr:%i, rrr:%i, pa:%i, sizeA:%i, sizeB:%i total:%i\n", instructions.ra, instructions.rra,
//				instructions.rb, instructions.rrb, instructions.rr, instructions.rrr, instructions.pa,
//				instructions.sizeA, instructions.sizeB, instructions.total);
	while (++i < 4)
		incts[i] = calc_total(instructions_variant(instructions, i + 1));
	i = 0;
	index = 0;
	tmp = incts[i].total;
	while (++i < 4)
	{
		if (incts[i].total < tmp)
			index = i;
	}
//	ft_printf("calc : ra:%i, rra:%i, rb:%i, rrb:%i, rr:%i, rrr:%i, pa:%i, sizeA:%i, sizeB:%i total:%i\n", instructions.ra, instructions.rra,
//				instructions.rb, instructions.rrb, instructions.rr, instructions.rrr, instructions.pa,
//				instructions.sizeA, instructions.sizeB, instructions.total);
	return (incts[index]);
}
