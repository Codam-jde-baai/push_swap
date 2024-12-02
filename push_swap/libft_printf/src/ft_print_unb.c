/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_unb.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 17:43:11 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/11/28 11:17:28 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*ft_unsigned_itoa(unsigned int n);
static int		nb_len(unsigned int nb);
static void		ft_rec(unsigned int nb, char *ptr);

int	ft_print_unb(unsigned int nb)
{
	int		output;
	char	*str;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		str = ft_unsigned_itoa(nb);
		output = ft_print_putstr(str);
		free(str);
	}
	return (output);
}

static char	*ft_unsigned_itoa(unsigned int n)
{
	unsigned int	nb;
	unsigned int	len;
	char			*ptr;

	nb = n;
	len = nb_len(nb);
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	ft_rec(nb, &ptr[len - 1]);
	return (ptr);
}

static void	ft_rec(unsigned int nb, char *ptr)
{
	if (nb >= 10)
		ft_rec((nb / 10), &ptr[-1]);
	*ptr = nb % 10 + '0';
}

static int	nb_len(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
	{
		len = 1;
		return (len);
	}
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
