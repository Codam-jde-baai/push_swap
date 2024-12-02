/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 16:36:00 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/04/23 21:15:05 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// void	leakstest(void)
// {
// 	system("leaks -q push_swap");
// }

int	main(int argc, char **argv)
{
	t_push_swap	*box;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	ps_validate_input(argc, argv);
	box = ps_assign_input(argc, argv);
	ps_sort_input(box);
	if (box -> maxindex <= 4)
		ps_small_sort(box);
	else
	{
		ps_convert_binary(box);
		ps_radix_sort(box);
	}
	exit(EXIT_SUCCESS);
}
