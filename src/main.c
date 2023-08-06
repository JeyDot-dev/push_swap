/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:24:51 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/06 11:26:08 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_instructions	instructions;

	a = NULL;
	b = NULL;
	load_list(ac, av, &a);
	instructions = best_instructions(a, b);
	print_stacks(a, b);
	ft_printf("ra:%i, rra:%i, rb:%i, rrb:%i, pa:%i, total:%i\n", instructions.ra, instructions.rra,
				instructions.rb, instructions.rrb, instructions.pa, instructions.total);

}
