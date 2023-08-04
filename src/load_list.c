/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:23:33 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/04 16:33:35 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	load_list(int ac, char **av, t_stack **stack)
{
	int	i;
	long long int check;

	i = ac - 1;
	while (i > 0)
	{
		check = ps_atoi(av[i]);
		if (check > 2147483647)
		{
			free_stack(*stack);
			error_exit();
		}
		put_top(new_item((int) check), stack);
		i--;
	}
}
