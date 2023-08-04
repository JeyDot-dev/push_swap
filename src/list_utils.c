/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:24:44 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/04 16:34:18 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_top(t_stack *newItem, t_stack **head)
{
	if (!head || !newItem)
		return ;
	newItem->next = *head;
	if(*head != NULL)
		newItem->last = (*head)->last;
	else
		newItem->last = newItem;
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
	if (!head)
		return (NULL);
	if (head->next)
	{
		while (head->next->next)
			head = head->next;
	}
	return (head);
}
void	print_stack(t_stack *head, char letter)
{
	ft_printf("----stack %c----\n", letter);
	while (head)
	{
		ft_printf("%i\n", head->number);
		head = head->next;
	}
}
