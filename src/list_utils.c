/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:24:44 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/03 17:45:28 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_top(t_stack *new_item, t_stack **head)
{
	if (!head || !new_item)
		return ;
	new_item->next = *head;
	if(*head != NULL)
		new_item->last = *head->last;
	else
		new_item->last = new_item;
	*head = new_item;
}

t_stack	*new_item(int number)
{
	t_stack	*newItem;

	newItem = malloc(sizeof(newItem));
	if (!newItem)
		return (NULL);
	return (newItem);
}

t_stack *find_penultimate(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next->next)
	{
		head = head->next;
	}
}
