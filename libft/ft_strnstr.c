/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:29:58 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/15 17:55:52 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	l;

	if ((int) len < 0)
		len = (size_t) ft_strlen(big);
	if (!ft_strncmp(little, "", 1))
		return ((char *) big);
	l = ft_strlen(little);
	i = 0;
	while (big[i] && len - i >= (size_t) l && i < (int) len)
	{
		if (ft_strncmp(&big[i], little, l) == 0)
			return ((char *) &big[i]);
		i++;
	}
	return (0);
}
