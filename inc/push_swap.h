/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:17:59 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/09/13 14:51:19 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*last;
}					t_stack;
typedef struct s_instructions
{
	int						ra;
	int						rb;
	int						rr;
	int						rra;
	int						rrb;
	int						rrr;
	int						sa;
	int						sb;
	int						ss;
	int						pa;
	int						pb;
	int						size_a;
	int						size_b;
	int						total;
	struct s_instructions	*next;
}				t_instructions;

//			main.c
void			cmd_processor(t_stack **a, t_stack **b, t_instructions lol);
//			list_utils
void			put_top(t_stack *newItem, t_stack **head);
t_stack			*new_item(int number);
t_stack			*find_penultimate(t_stack *head);
t_stack			*find_last(t_stack *head);
void			print_stacks(t_stack *stackA, t_stack *stackB);
//			list_utils_two
int				count_elements(t_stack *stack);
//			load_list
void			load_list(int ac, char **av, t_stack **stack);
//			rotate_reverse
void			rrx(t_stack **stack, char letter);
void			rrr(t_stack **stack_a, t_stack **stack_b);
void			rx(t_stack **stack, char letter);
void			rr(t_stack **stack_a, t_stack **stack_b);
//			swap_push
void			px(t_stack **from_stack, t_stack **to_stack, char to_letter);
void			sx(t_stack **stack, char letter);
void			ss(t_stack **stackA, t_stack **stackB);
//			pswap_atoi
long long int	ps_atoi(const char *str);
//			free_utils
void			error_exit(t_stack *stack);
void			free_stack(t_stack *head);
//			check_order
int				check_order(t_stack	*stack);
//			calc_total
t_instructions	best_total(t_instructions instructions);
//			smallest_biggest
t_instructions	calc_rotations(int slot, int elements, t_instructions lol);
t_instructions	biggest(int num, t_stack *b, t_instructions instructions);
t_instructions	smallest(int num, t_stack *b, t_instructions instructions);
t_instructions	biggest_smallest(t_instructions lol, int num, t_stack *b);
//			best_instructions
t_instructions	instructions_init(t_stack *a, t_stack *b);
t_instructions	best_instructions(t_stack *a, t_stack *b);
//			fix_order
void			fix_order(t_stack **a);
//			three_sort
void			three_sort(t_stack **a);
//			low_sort
void			low_sort(t_stack **a, t_stack **b);
#endif
