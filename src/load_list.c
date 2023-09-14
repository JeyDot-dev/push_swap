/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:23:33 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/09/14 18:50:29 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	check_strings_len(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac -1)
	{
		while ((av[i][j] && av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == 32)
			j++;
		if (ft_strlen(&av[i][j]) > 11 || ft_strlen(&av[i][j]) <= 0)
			error_exit(NULL);
		j = 0;
		i++;
	}
}
void	check_dup(t_stack *a)
{
	t_stack	*current;
	t_stack *tmp;
	int		target;
	int		ct;

	current = a;

	while (current)
	{
		target = current->number;
		ct = 0;
		tmp = a;
		while (tmp)
		{
			if (tmp->number == target)
				ct++;
			if (ct > 1)
				error_exit(a);
			tmp = tmp->next;
		}
		current = current->next;
	}
}
void	load_list(int ac, char **av, t_stack **stack)
{
	int	i;
	long long int check;

	i = ac - 1;
	check_strings_len(ac, av);
	while (i > 0)
	{
		check = ps_atoi(av[i]);
		if (check > 2147483647)
			error_exit(*stack);
		put_top(new_item((int) check), stack);
		i--;
	}
	check_dup(*stack);
}
