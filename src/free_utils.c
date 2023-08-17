/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:04:25 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/17 16:57:49 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *stack)
{
	if (stack)
		free_stack(stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_stack(t_stack *head)
{
	t_stack *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
