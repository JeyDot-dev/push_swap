/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:41:15 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/05 10:55:56 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx(t_stack **stack, char letter)
{
	t_stack *temp;

	if (*stack && (*stack)->next)
	{
		temp = find_penultimate(*stack);
		if (temp)
		{
			temp->next = NULL;
			temp->last = NULL;
			put_top((*stack)->last, stack);
		}
		else
		{
			temp = (*stack)->next;
			(*stack)->next = NULL;
			(*stack)->last = NULL;
			put_top(temp, stack);
		}
	}
	if (letter == 'a' || letter == 'b')
		ft_printf("rr%c\n", letter);
}
void	rx(t_stack **stack, char letter)
{
	t_stack *temp;
	t_stack *temp_last;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		temp_last = find_last(*stack);
		(*stack)->next->last = temp;
		*stack = (*stack)->next;
		temp->next = NULL;
		temp->last = NULL;
		temp_last->next = temp;
		temp_last->last = NULL;
	}
	if (letter == 'a' || letter == 'b')
		ft_printf("r%c\n", letter);
}
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrx(stack_a, 'x');
	rrx(stack_b, 'x');
	ft_printf("rrr\n");
}
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rx(stack_a, 'x');
	rx(stack_b, 'x');
	ft_printf("rr\n");
}
