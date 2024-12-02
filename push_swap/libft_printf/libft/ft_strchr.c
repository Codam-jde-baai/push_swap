/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 17:21:43 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/10/31 12:09:53 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*ptr;
	unsigned char	d;

	d = (unsigned char)c;
	ptr = (char *)s;
	while (*ptr != d && *ptr != '\0')
		ptr++;
	if (*ptr == d)
		return (ptr);
	else
		return (NULL);
}
