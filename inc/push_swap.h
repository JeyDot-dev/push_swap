/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:17:59 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/04 16:28:01 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_stack
{
  int             number;
  struct s_stack  *next;
  struct s_stack  *last;
}        t_stack;

//			list_utils
void	put_top(t_stack *newItem, t_stack **head);
t_stack	*new_item(int number);
t_stack *find_penultimate(t_stack *head);
void	print_stack(t_stack *head, char letter);
//			load_list
void	load_list(int ac, char **av, t_stack **stack);
//			rotate_reverse
void	rr(t_stack **stack, char letter);
//			pswap_atoi
long long int	ps_atoi(const char *str);
//			free_utils
void	error_exit(void);
void	free_stack(t_stack *head);
#endif
