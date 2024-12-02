/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_stack.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 16:09:10 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/04/23 19:12:26 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* creates a new t_stack */
t_stack	*ps_new_stack(int Inputnbr, int Index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node -> next = NULL;
	node -> nbr = Inputnbr;
	node -> inputindex = Index;
	node -> sortedindex = -1;
	return (node);
}

/* creates a new t_push_swap */
t_push_swap	*ps_new_box(t_stack *a_stack)
{
	t_push_swap	*box;
	int			num;
	int			bit;

	box = malloc(sizeof(t_push_swap));
	if (box == NULL)
		return (NULL);
	box -> a = a_stack;
	box -> b = NULL;
	while (a_stack -> next != NULL)
		a_stack = a_stack -> next;
	box -> maxindex = a_stack -> inputindex;
	num = box -> maxindex;
	bit = 0;
	while (num > 0)
	{
		bit++;
		num = num / 2;
	}
	box -> maxbits = bit;
	return (box);
}

/* the position of a node in a stack indexed from 0 */
int	ps_node_position(t_stack **stack, t_stack *node)
{
	int		position;
	t_stack	*move;

	if (node == NULL)
		return (-1);
	move = *stack;
	position = 0;
	while (move != node)
	{
		move = move -> next;
		position++;
	}
	if (move == node)
		return (position);
	else
		return (-1);
}

/* size of stack */
int	ps_stack_size(t_stack **stack)
{
	t_stack	*node;
	int		size;

	node = *stack;
	size = 0;
	while (node)
	{
		node = node -> next;
		size++;
	}
	return (size);
}
