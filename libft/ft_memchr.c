/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 00:25:16 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/18 21:14:56 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char		*s;
	size_t				i;

	s = (unsigned char *) ptr;
	i = 0;
	while (i < n)
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			return ((void *)&s[i]);
		i++;
	}
	return (0);
}
