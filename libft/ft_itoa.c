/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:11:23 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/18 21:13:41 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	power(int a, int exp)
{
	if (exp <= 0)
		return (1);
	return (a * power (a, exp - 1));
}

static char	*minmax(int n)
{
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (ft_strdup("0"));
}

static int	ft_intlen(int n)
{
	int	len;

	len = 1;
	while (n / power(10, len))
		len++;
	return (len);
}

static char	*ft_itoalloc(int n)
{
	char	*ret;
	int		len;

	len = ft_intlen(n);
	if (n < 0)
	{
		len += 1;
		ret = malloc(sizeof(char) * len + 1);
		if (!ret)
			return (0);
		ret[0] = '-';
		ret[len] = 0;
		return (ret);
	}
	ret = malloc (sizeof(char) * len + 1);
	if (!ret)
		return (0);
	ret[len] = 0;
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		b;
	int		len;

	if (n == 2147483647 || n == -2147483648 || n == 0)
		return (minmax(n));
	ret = ft_itoalloc(n);
	if (!ret)
		return (0);
	len = ft_intlen(n);
	b = 1;
	if (n < 0)
	{
		b = 0;
		n *= -1;
	}
	while (len)
	{
		ret[len - b] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (ret);
}
