/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 17:28:27 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/10/31 12:10:34 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*ptr;
	unsigned char	*start;
	unsigned char	d;

	d = (unsigned char)c;
	ptr = (unsigned char *)s;
	start = ptr;
	while (*ptr)
		ptr++;
	while (*ptr != d && ptr != start)
		ptr--;
	if (*ptr == d)
		return ((char *)ptr);
	else
		return (NULL);
}
