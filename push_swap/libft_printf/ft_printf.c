/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 11:03:46 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/11/28 11:15:51 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversion(va_list args, const char format);

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		output;
	va_list	ap;

	output = 0;
	i = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%' && fmt[i + 1] != '\0')
		{
			output = output + conversion(ap, fmt[i + 1]);
			i++;
		}
		else if (fmt[i] != '%')
		{
			write(1, &fmt[i], 1);
			output++;
		}
		if (fmt[i] != '\0')
			i++;
	}
	va_end(ap);
	return (output);
}

/* variable arguments (c,s,p,d,i,u,x,X,%) */
static int	conversion(va_list args, const char format)
{
	int	output;

	output = 0;
	if (format == 'c')
		output = ft_print_putchar(va_arg(args, int));
	else if (format == 's')
		output = ft_print_putstr(va_arg(args, char *));
	else if (format == 'p')
		output = ft_print_ptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		output = ft_print_nb(va_arg(args, int));
	else if (format == 'u')
		output = ft_print_unb(va_arg(args, unsigned int));
	else if (format == 'x')
		output = ft_print_hexl(va_arg(args, unsigned int));
	else if (format == 'X')
		output = ft_print_hexu(va_arg(args, unsigned int));
	else if (format == '%')
	{
		write(1, "%", 1);
		output = 1;
	}
	return (output);
}
