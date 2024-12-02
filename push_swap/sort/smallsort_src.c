/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smallsort_src.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 18:00:41 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/04/23 19:47:32 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ps_smallest_to_b(t_stack **a_stack, t_stack **b_stack,
				int max_index);
int			ps_find(t_stack *a, int max_index);

void	ps_sort_3(t_stack **stack_a)
{
	t_stack	*node;
	int		first;
	int		second;
	int		third;

	node = *stack_a;
	first = node -> sortedindex;
	second = node -> next -> sortedindex;
	third = node -> next -> next -> sortedindex;
	if (first < second && first < third)
	{
		ps_reverse_rotate(stack_a, "rra");
		ps_swap(stack_a, "sa");
	}
	else if (first > second && first < third)
		ps_swap(stack_a, "sa");
	else if (third < first && second > first)
		ps_reverse_rotate(stack_a, "rra");
	else if (second < third && third < first)
		ps_rotate(stack_a, "ra");
	else if (third < second && first > second)
	{
		ps_swap(stack_a, "sa");
		ps_reverse_rotate(stack_a, "rra");
	}
}

void	ps_sort_4(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*b_node;

	ps_smallest_to_b(a_stack, b_stack, 3);
	b_node = *b_stack;
	if (!ps_sorted(*a_stack))
		ps_sort_3(a_stack);
	ps_pa(b_stack, a_stack);
}

void	ps_sort_5(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*b_node;

	ps_smallest_to_b(a_stack, b_stack, 4);
	ps_smallest_to_b(a_stack, b_stack, 4);
	b_node = *b_stack;
	if (b_node -> sortedindex == 0)
		ps_swap(b_stack, "sb");
	if (!ps_sorted(*a_stack))
		ps_sort_3(a_stack);
	ps_pa(b_stack, a_stack);
	ps_pa(b_stack, a_stack);
}

void	ps_smallest_to_b(t_stack **a_stack, t_stack **b_stack,
			int max_index)
{
	int	position;

	position = ps_find(*a_stack, max_index);
	if (position == 0)
		ps_pb(a_stack, b_stack);
	else if (position == 1)
	{
		ps_rotate(a_stack, "ra");
		ps_pb(a_stack, b_stack);
	}
	else if (position == 3 || position == 4)
	{
		ps_reverse_rotate(a_stack, "rra");
		ps_pb(a_stack, b_stack);
	}
	else if (position == 2)
	{
		ps_rotate(a_stack, "ra");
		ps_rotate(a_stack, "ra");
		ps_pb(a_stack, b_stack);
	}
}

int	ps_find(t_stack *a, int max_index)
{
	if (max_index == 4)
	{
		if (a -> sortedindex == 0 || a -> sortedindex == 1)
			return (0);
		a = a -> next;
		if (a -> sortedindex == 0 || a -> sortedindex == 1)
			return (1);
		while (a -> next != NULL)
			a = a -> next;
		if (a -> sortedindex == 0 || a -> sortedindex == 1)
			return (a -> inputindex);
	}
	else if (max_index == 3)
	{
		if (a -> sortedindex == 0)
			return (0);
		a = a -> next;
		if (a -> sortedindex == 0)
			return (1);
		while (a -> next != NULL)
			a = a -> next;
		if (a -> sortedindex == 0)
			return (a -> inputindex);
	}	
	return (2);
}
