/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:17:59 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/08/05 11:05:48 by jsousa-a         ###   ########.fr       */
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
t_stack *find_last(t_stack *head);
void	print_stacks(t_stack *stackA, t_stack *stackB);
//			load_list
void	load_list(int ac, char **av, t_stack **stack);
//			rotate_reverse
void	rrx(t_stack **stack, char letter);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	rx(t_stack **stack, char letter);
void	rr(t_stack **stack_a, t_stack **stack_b);
//			swap_push
void	px(t_stack **from_stack, t_stack **to_stack, char to_letter);
void	sx(t_stack **stack, char letter);
void	ss(t_stack **stackA, t_stack **stackB);
//			pswap_atoi
long long int	ps_atoi(const char *str);
//			free_utils
void	error_exit(void);
void	free_stack(t_stack *head);
#endif
