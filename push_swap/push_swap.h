/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 16:44:03 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/04/23 19:07:34 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_printf/ft_printf.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				nbr;
	int				inputindex;
	int				sortedindex;
	char			binary[32];
	struct s_stack	*next;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
	int		maxindex;
	int		maxbits;
}	t_push_swap;

/* validation and assigning of input */
void		ps_validate_input(int count, char **var);
void		ps_check_doubles(t_stack *current);
t_push_swap	*ps_assign_input(int count, char **var);

/* utils */
void		ps_exit(void);
void		ps_sort_input(t_push_swap *box);
bool		ps_sorted(t_stack *node);
void		ps_convert_binary(t_push_swap *box);

/* stack */
t_stack		*ps_new_stack(int Inputnbr, int Index);
t_push_swap	*ps_new_box(t_stack *a_stack);
int			ps_stack_size(t_stack **stack);
int			ps_node_position(t_stack **stack, t_stack *node);

/* sorting algorithms */
void		ps_radix_sort(t_push_swap *box);
void		ps_small_sort(t_push_swap *box);
void		ps_sort_3(t_stack **stack_a);
void		ps_sort_4(t_stack **a_stack, t_stack **b_stack);
void		ps_sort_5(t_stack **a_stack, t_stack **b_stack);

/* operations */
void		ps_rotate(t_stack **stack, char *operation);
void		ps_reverse_rotate(t_stack **stack, char *operation);
void		ps_swap(t_stack **stack, char *operation);
void		ps_pb(t_stack **stack_a, t_stack **stack_b);
void		ps_pa(t_stack **stack_b, t_stack **stack_a);

#endif /* PUSH_SWAP_H */