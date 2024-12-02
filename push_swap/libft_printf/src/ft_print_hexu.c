/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hexu.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 18:04:38 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/11/21 16:57:36 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_hexu_write(unsigned int nb);
static int	ft_hex_cnt(unsigned int ptrn);

int	ft_print_hexu(unsigned int nb)
{
	int	output;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		ft_hexu_write(nb);
		output = ft_hex_cnt(nb);
		return (output);
	}
}

static void	ft_hexu_write(unsigned int nb)
{
	if (nb >= 16)
	{
		ft_hexu_write(nb / 16);
		ft_hexu_write(nb % 16);
	}
	else
	{
		if (nb < 10)
			ft_print_putchar(nb + '0');
		else
			ft_print_putchar((nb - 10 + 'A'));
	}
}

static int	ft_hex_cnt(unsigned int nb)
{
	int	output;

	output = 0;
	while (nb != 0)
	{
		output++;
		nb = nb / 16;
	}
	return (output);
}
