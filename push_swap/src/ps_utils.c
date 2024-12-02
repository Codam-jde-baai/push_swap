/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 13:07:53 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/04/23 19:41:08 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_exit(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	ps_sort_input(t_push_swap *box)
{
	t_stack	*lowest;
	t_stack	*move;
	int		i;

	if (ps_sorted(box -> a))
		exit(EXIT_SUCCESS);
	i = 0;
	while (i <= box -> maxindex)
	{
		move = box -> a;
		while (move -> sortedindex != -1 && move != NULL)
			move = move -> next;
		lowest = move;
		move = box -> a;
		while (move != NULL)
		{
			if (lowest -> nbr > move -> nbr && move -> sortedindex == -1)
				lowest = move;
			move = move -> next;
		}
		lowest -> sortedindex = i;
		i++;
	}	
}

bool	ps_sorted(t_stack *node)
{
	while (node && node -> next)
	{
		if (node -> nbr > node -> next -> nbr)
			return (false);
		node = node -> next;
	}
	return (true);
}

void	ps_convert_binary(t_push_swap *box)
{
	t_stack	*a_node;
	int		bits;
	int		i;
	int		num;

	a_node = box -> a;
	num = box -> maxindex;
	bits = box -> maxbits;
	while (a_node)
	{
		num = a_node -> sortedindex;
		i = bits;
		while (i-- > 0)
		{
			if ((num & 1) == 1)
				a_node -> binary[i] = '1';
			else
				a_node -> binary[i] = '0';
			num >>= 1;
		}
		i = bits;
		while (i <= 31)
			a_node -> binary[i++] = 0;
		a_node = a_node -> next;
	}
}
