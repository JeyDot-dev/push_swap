/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:52:37 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/06 12:16:24 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	count_elements(t_stack *stack)
{
	int	ct;

	ct = 0;
	while (stack)
	{
		ct++;
		stack = stack->next;
	}
	return (ct);
}
