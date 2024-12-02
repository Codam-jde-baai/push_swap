/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_ptr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 17:47:28 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/11/21 16:58:35 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_ptr_write(unsigned long ptrn);
static int	ft_ptr_cnt(unsigned long ptrn);

int	ft_print_ptr(unsigned long ptr)
{
	int	output;

	output = ft_print_putstr("0x");
	if (ptr == 0)
		output = output + ft_print_putchar('0');
	else
	{
		ft_ptr_write(ptr);
		output = output + ft_ptr_cnt(ptr);
	}
	return (output);
}

static void	ft_ptr_write(unsigned long ptrn)
{
	if (ptrn >= 16)
	{
		ft_ptr_write(ptrn / 16);
		ft_ptr_write(ptrn % 16);
	}
	else
	{
		if (ptrn < 10)
			ft_print_putchar(ptrn + '0');
		else
			ft_print_putchar((ptrn - 10 + 'a'));
	}
}

static int	ft_ptr_cnt(unsigned long ptrn)
{
	int	output;

	output = 0;
	while (ptrn != 0)
	{
		output++;
		ptrn = ptrn / 16;
	}
	return (output);
}
