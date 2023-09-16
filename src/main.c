/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:24:51 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/09/16 16:23:20 by jsousa-a         ###   ########.fr       */
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

void	long_sort(t_stack **a, t_stack **b)
{
	t_instructions	instructions;

	px(a, b, 'b');
	px(a, b, 'b');
	while (*a)
	{
		instructions = best_instructions(*a, *b);
		cmd_processor(a, b, instructions);
		px(a, b, 'b');
	}
}

int	main(int ac, char **av)
{
	t_stack			*a;
	t_stack			*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		error_exit(NULL);
	load_list(ac, av, &a);
	if (!check_order(a))
	{
		free_stack(a);
		return (0);
	}
	if (count_elements(a) > 10)
		long_sort(&a, &b);
	else
		low_sort(&a, &b);
	while (b)
		px(&b, &a, 'a');
	fix_order(&a);
	free_stack(b);
	free_stack(a);
}
