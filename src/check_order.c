/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:42:27 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/05 12:49:21 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_stack	*stack)
{
	if (!stack)
		return (-1);
	while (stack && stack->next)
		if (stack->number < stack->next->number)
			stack = stack->next;
	if (stack->next)
		return (1);
	return (0);
}
