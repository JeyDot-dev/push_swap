/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:41:15 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/04 15:52:58 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **stack, char letter)
{
	t_stack *temp;

	temp = find_penultimate(*stack);
	temp->next = NULL;
	temp->last = temp;
	(*stack)->last->next = *stack;
	(*stack)->last->last = temp;
	put_top((*stack)->last, stack);
	ft_printf("rr%c\n", letter);
}
