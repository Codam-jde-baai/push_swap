/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_assign_input.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 14:38:31 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/04/26 20:13:02 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*ps_assign_two(char **var);
static int		read_two(char **var);
static t_stack	*ps_assign_multiple(int count, char **var);
static int		read_multi(char *var);

/* assigns the input to push_swap to t_stack a */
t_push_swap	*ps_assign_input(int count, char **var)
{
	t_push_swap	*box;
	t_stack		*a;

	if (count == 2)
		a = ps_assign_two(var);
	else
		a = ps_assign_multiple(count, var);
	if (!a)
		exit(EXIT_FAILURE);
	ps_check_doubles(a);
	box = ps_new_box(a);
	if (!box)
		exit(EXIT_FAILURE);
	return (box);
}

static t_stack	*ps_assign_two(char **var)
{
	int		i;
	t_stack	*first;
	t_stack	*current;
	t_stack	*following;

	current = ps_new_stack(read_two(&var[1]), 0);
	if (!current)
		exit(EXIT_FAILURE);
	first = current;
	if (*var[1] == ' ')
		(var[1])++;
	i = 2;
	while (*var[1] != '\0')
	{
		following = ps_new_stack(read_two(&var[1]), i - 1);
		if (!following)
			exit(EXIT_FAILURE);
		current -> next = following;
		current = following;
		i++;
		if (*var[1] == ' ')
			(var[1])++;
	}
	return (first);
}

static int	read_two(char **var)
{
	long	output;
	int		neg;

	output = 0;
	neg = 1;
	if (**var == '-')
	{
		(*var)++;
		neg = -1;
	}
	while (**var >= '0' && **var <= '9')
	{
		output = output * 10 + (**var - '0');
		(*var)++;
		if ((output > INT_MAX && neg == 1)
			|| ((output * neg) < INT_MIN && neg == -1))
			ps_exit();
	}
	if (neg < 0)
		output = output * -1;
	return (output);
}

static t_stack	*ps_assign_multiple(int count, char **var)
{
	int		i;
	t_stack	*first;
	t_stack	*current;
	t_stack	*following;

	current = ps_new_stack(read_multi(var[1]), 0);
	if (!current)
		exit(EXIT_FAILURE);
	first = current;
	i = 2;
	while (i < count)
	{
		following = ps_new_stack(read_multi(var[i]), i - 1);
		if (!following)
			exit(EXIT_FAILURE);
		current -> next = following;
		current = following;
		i++;
	}
	return (first);
}

static int	read_multi(char *var)
{
	int		i;
	long	output;
	int		neg;

	output = 0;
	neg = 1;
	i = 0;
	if (var[i] == '-')
	{
		i++;
		neg = -1;
	}
	while (var[i] >= '0' && var[i] <= '9')
	{
		output = output * 10 + (var[i] - '0');
		i++;
		if ((output > INT_MAX && neg == 1)
			|| ((output * neg) < INT_MIN && neg == -1))
			ps_exit();
	}
	if (neg == -1)
		output = output * -1;
	return (output);
}
