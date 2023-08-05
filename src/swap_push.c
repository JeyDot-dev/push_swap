/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:41:17 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/05 11:16:14 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(t_stack **from_stack, t_stack **to_stack, char to_letter)
{
	t_stack	*tmp;
	t_stack	*tmp_last;
	if (*from_stack)
	{
	//	if ((*from_stack)->next);
	//	{
			tmp = (*from_stack)->next;
			tmp_last = (*from_stack)->last;
	//	}
	//	else
	//	{
	//		tmp = NULL;
	//		tmp_last = NULL;
	//	}
		put_top(*from_stack, to_stack);
		if (tmp)
			tmp->last = tmp_last;
		*from_stack = tmp;
	}
	ft_printf("p%c\n", to_letter);
}
void	sx(t_stack **stack, char letter)
{
	t_stack *tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		put_top(tmp, stack);
	}
	if (letter == 'a' || letter == 'b')
		ft_printf("s%c\n", letter);
}
void	ss(t_stack **stackA, t_stack **stackB)
{
	sx(stackA, 'x');
	sx(stackB, 'x');
	ft_printf("ss\n");
}
