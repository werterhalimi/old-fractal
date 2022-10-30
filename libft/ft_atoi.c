/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:31:02 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/18 21:08:57 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	ret;
	int	i;

	ret = 0;
	i = 1;
	while ((*str >= 10 && *str <= 13) || *str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		ret = ret * 10 + (*str - 48);
		str++;
	}
	return (ret * i);
}
