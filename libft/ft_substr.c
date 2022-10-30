/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:34:35 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/18 21:21:17 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;

	if (start >= ft_strlen(s))
	{
		ptr = malloc(sizeof(char));
		ptr[0] = 0;
		return (ptr);
	}
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	ptr = (char *) malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (i < (int) len && s[start])
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = 0;
	return (ptr);
}
