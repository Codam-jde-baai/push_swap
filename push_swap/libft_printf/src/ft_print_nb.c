/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_nb.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 17:33:20 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/11/11 12:40:25 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_nb(int nb)
{
	int		output;
	char	*str;

	str = ft_itoa(nb);
	output = ft_print_putstr(str);
	free(str);
	return (output);
}
