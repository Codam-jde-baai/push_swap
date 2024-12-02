/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_algo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juliusdebaaij <juliusdebaaij@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/08 21:06:37 by juliusdebaa   #+#    #+#                 */
/*   Updated: 2023/04/23 19:48:48 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ps_move_zero(t_push_swap *box, int bit);
void		ps_pa_repeat(t_stack **stack_b, t_stack **stack_a);

void	ps_small_sort(t_push_swap *box)
{
	if (box -> maxindex == 1)
		ps_swap(&box->a, "sa");
	else if (box -> maxindex == 2)
		ps_sort_3(&box->a);
	else if (box -> maxindex == 3)
		ps_sort_4(&box->a, &box->b);
	else if (box -> maxindex == 4)
		ps_sort_5(&box->a, &box->b);
}

void	ps_radix_sort(t_push_swap *box)
{
	int	bit;

	bit = box -> maxbits - 1;
	while (bit >= 0)
	{
		ps_move_zero(box, bit);
		ps_pa_repeat(&box->b, &box->a);
		bit--;
	}
}

void	ps_move_zero(t_push_swap *box, int bit)
{
	t_stack	*a_node;
	int		i;

	i = box -> maxindex;
	a_node = box -> a;
	while (i >= 0)
	{
		if (a_node -> binary[bit] == '1')
		{
			ps_rotate(&box->a, "ra");
		}
		else
			ps_pb(&box->a, &box->b);
		a_node = box->a;
		i--;
	}
}

void	ps_pa_repeat(t_stack **stack_b, t_stack **stack_a)
{
	while (*stack_b)
	{
		ps_pa(stack_b, stack_a);
	}
}
