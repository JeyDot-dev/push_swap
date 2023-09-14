/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:24:44 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/09/14 18:22:19 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_top(t_stack *new_item, t_stack **head)
{
	if (!head || !new_item)
		return ;
	new_item->next = *head;
	if (*head)
		new_item->last = find_last(*head);
	*head = new_item;
}

t_stack	*new_item(int number)
{
	t_stack	*new_item;

	new_item = malloc(sizeof(*new_item));
	if (!new_item)
		return (NULL);
	new_item->number = number;
	return (new_item);
}

t_stack	*find_penultimate(t_stack *head)
{
	if (head && head->next && head->next->next)
	{
		while (head->next->next)
			head = head->next;
	}
	else
		return (NULL);
	return (head);
}
t_stack *find_last(t_stack *head)
{
	if (!head)
		return (NULL);
	if (head->next)
	{
		while (head->next)
			head = head->next;
	}
	return (head);
}
void	print_stacks(t_stack *stackA, t_stack *stackB)
{
	ft_printf("----stack A----\t----stack B----\n");
	while (stackA || stackB)
	{
		if (stackA)
		{
			ft_printf("%i", stackA->number);
			stackA = stackA->next;
		}
		if (stackB)
		{
			ft_printf("\t\t%i", stackB->number);
			stackB = stackB->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}
