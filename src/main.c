/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:24:51 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/08 04:36:19 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_processor(t_stack **a, t_stack **b, t_instructions instructions)
{
	while (instructions.rb-- > 0)
		rx(b, 'b');
	while (instructions.ra-- > 0)
		rx(a, 'a');
	while (instructions.rrb-- > 0)
		rrx(b, 'b');
	while (instructions.rra-- > 0)
		rrx(a, 'a');
	while (instructions.rr-- > 0)
		rr(a, b);
	while (instructions.rrr-- > 0)
		rrr(a, b);
}
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_instructions	instructions;

	a = NULL;
	b = NULL;
	load_list(ac, av, &a);
	if (count_elements(a) > 10)
	{
		px(&a, &b, 'b');
		px(&a, &b, 'b');
	//	print_stacks(a, b);
		while (a)
		{
		instructions = best_instructions(a, b);
		cmd_processor(&a, &b, instructions);
		px(&a, &b, 'b');
	//	print_stacks(a, b);
		}
	}
	else
		low_sort(&a, &b);
	while (b)
		px(&b, &a, 'a');
//	print_stacks(a, b);
	fix_order(&a);
//	print_stacks(a, b);
//	ft_printf("ra:%i, rra:%i, rb:%i, rrb:%i, rr:%i, rrr:%i, pa:%i, total:%i\n", instructions.ra, instructions.rra,
//				instructions.rb, instructions.rrb, instructions.rr, instructions.rrr, instructions.pa, instructions.total);
}
