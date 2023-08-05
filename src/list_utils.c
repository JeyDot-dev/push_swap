/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:24:44 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/05 10:49:09 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_top(t_stack *newItem, t_stack **head)
{
	if (!head || !newItem)
		return ;
	newItem->next = *head;
	if(*head)
		newItem->last = find_last(*head);
	*head = newItem;
}

t_stack	*new_item(int number)
{
	t_stack	*newItem;

	newItem = malloc(sizeof(*newItem));
	if (!newItem)
		return (NULL);
	newItem->number = number;
	return (newItem);
}

t_stack *find_penultimate(t_stack *head)
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
}
