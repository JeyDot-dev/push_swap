/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:24:51 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/05 11:16:28 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	load_list(ac, av, &a);
	print_stacks(a, b);
	ft_printf("\n");
	rrx(&a, 'a');
	ft_printf("\n");
	print_stacks(a, b);
	ft_printf("\n");
	rx(&a, 'a');
	ft_printf("\n");
	print_stacks(a, b);
	ft_printf("\n");
	px(&a, &b, 'b');
	px(&a, &b, 'b');
	ft_printf("\n");
	print_stacks(a, b);
	ft_printf("\n");
	rr(&a, &b);
	rr(&a, &b);
	rr(&a, &b);
	ft_printf("\n");
	print_stacks(a, b);
	ft_printf("\n");
	rrr(&a, &b);
	ft_printf("\n");
	print_stacks(a, b);
	ft_printf("\n");
	sx(&a, 'a');
	sx(&b, 'b');
	ft_printf("\n");
	print_stacks(a, b);
	ft_printf("\n");
	ss(&a, &b);
	ft_printf("\n");
	print_stacks(a, b);
	ft_printf("\n");
	px(&b, &a, 'a');
	px(&b, &a, 'a');
	ft_printf("\n");
	print_stacks(a, b);
}
