/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:44:41 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/13 19:20:14 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s;

	if (!size)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	s = i;
	while (i < size - 1 && src[i - s])
	{
		dst[i] = src[i - s];
		i++;
	}
	if (size > 0)
		dst[i] = 0;
	if (size > s)
		return (s + ft_strlen(src));
	return (size + ft_strlen(src));
}
