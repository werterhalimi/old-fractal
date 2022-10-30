/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:24:09 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/18 21:08:03 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	len = ft_strlen(s);
	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (0);
	while (i < len)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
