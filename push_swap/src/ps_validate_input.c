/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_validate_input.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 10:23:57 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/04/26 20:10:47 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static bool	ps_validate_two(char *var);
static bool	ps_validate_multiple(int count, char **var);

/* validates the arguments passed to push_swap */
void	ps_validate_input(int count, char **var)
{
	if (count == 2)
	{
		if (!ps_validate_two(var[1]))
			ps_exit();
	}
	else if (count > 2)
	{
		if (!ps_validate_multiple(count, var))
			ps_exit();
	}
}

static bool	ps_validate_two(char *var)
{
	int	i;

	i = 0;
	while (var[i] != '\0')
	{
		if (!(var[i] >= '0' && var[i] <= '9') && (var[i] != '-'))
			return (false);
		if (var[i] == '-' && var[i] != '\0')
			i++;
		if (!(var[i] >= '0' && var[i] <= '9'))
			return (false);
		while ((var[i] >= '0' && var[i] <= '9') && var[i] != '\0')
			i++;
		if ((var[i] != ' ' && var[i] != '\0')
			|| (var[i] == ' ' && var[i + 1] == '\0'))
			return (false);
		if (var[i] == ' ' && var[i] != '\0')
			i++;
		if (var[i] == '\0')
			return (true);
	}
	return (false);
}

static bool	ps_validate_multiple(int count, char **var)
{
	int	i;
	int	k;

	i = 1;
	while (i < count)
	{
		k = 0;
		if (!(var[i][k] >= '0' && var[i][k] <= '9') && (var[i][k] != '-'))
			return (false);
		if (var[i][k] == '-' && var[i][k] != '\0')
			k++;
		if (!(var[i][k] >= '0' && var[i][k] <= '9'))
			return (false);
		while ((var[i][k] >= '0' && var[i][k] <= '9') && var[i][k] != '\0')
			k++;
		if (var[i][k] == '\0')
			i++;
		else
			return (false);
	}
	return (true);
}

/* checks a list for double values */
void	ps_check_doubles(t_stack *first)
{
	t_stack	*compare;
	t_stack	*node;

	compare = first -> next;
	while (compare)
	{
		node = first;
		while (node)
		{
			if (compare->nbr == node -> nbr && compare != node)
				ps_exit();
			node = node -> next;
		}
		compare = compare -> next;
	}
}
