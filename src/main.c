/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:24:51 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/04 16:37:59 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	(void) b;
	load_list(ac, av, &a);
	print_stack(a, 'A');
	ft_printf("\n");
	rr(&a, 'a');
	ft_printf("\n");
	print_stack(a, 'A');
}
