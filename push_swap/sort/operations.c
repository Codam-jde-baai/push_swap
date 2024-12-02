/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 17:22:38 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/04/23 19:45:53 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* ra / rb operation to shift up all elements by 1 */
void	ps_rotate(t_stack **stack, char *operation)
{
	t_stack	*first_node;
	t_stack	*last_node;

	first_node = *stack;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	*stack = first_node->next;
	last_node->next = first_node;
	first_node->next = NULL;
	ft_printf("%s\n", operation);
}

/* rra / rrb operation to shift down all elements 1 */
void	ps_reverse_rotate(t_stack **stack, char *operation)
{
	t_stack	*last_node;
	t_stack	*second_last_node;

	last_node = *stack;
	second_last_node = *stack;
	while (last_node->next)
	{
		second_last_node = last_node;
		last_node = last_node->next;
	}
	last_node->next = *stack;
	*stack = last_node;
	second_last_node->next = NULL;
	ft_printf("%s\n", operation);
}

/* sa / sb operation to swap the first position of a stack with the second */
void	ps_swap(t_stack **stack, char *operation)
{
	t_stack	*temp;

	temp = (*stack)-> next;
	(*stack)-> next = temp -> next;
	temp -> next = *stack;
	*stack = temp;
	ft_printf("%s\n", operation);
}

/* pb - operation to move the firts element of a and move it to b */
void	ps_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp -> next = *stack_b;
	*stack_b = temp;
	ft_printf("pb\n");
}

/* pa - operation to move the firts element of b and move it to a */
void	ps_pa(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp -> next = *stack_a;
	*stack_a = temp;
	ft_printf("pa\n");
}
