/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:59:30 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/18 12:19:58 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charinset(char c, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		min;
	int		max;
	char	*str;
	int		i;

	i = 0;
	max = ft_strlen(s1);
	min = i;
	while (s1[i])
	{
		if (ft_charinset(s1[i], set) && i - min <= 1)
			min++;
		else
			break ;
		i++;
	}
	i = ft_strlen(s1);
	while (min < i)
	{
		if (ft_charinset(s1[i], set) && max - i <= 1)
			max--;
		i--;
	}
	str = ft_substr(s1, min, max - (min));
	return (str);
}
