/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:39:35 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/20 20:24:03 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	power(long int a, int exp)
{
	if (exp <= 0)
		return (1);
	return (a * power(a, exp - 1));
}

static int	ft_intlen(long int n)
{
	int	len;

	len = 1;
	while (n / power(10, len))
		len++;
	return (len);
}

static void	minmax(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	if (n == 2147483647)
		write(fd, "2147483647", 10);
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
}

void	ft_putnbr_fd(long int n, int fd)
{
	char	s;
	int		len;

	if (n == 0 || n == 2147483647 || n == -2147483648)
	{
		minmax(n, fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	len = ft_intlen(n);
	while (len--)
	{
		s = (n / power(10, len)) + 48;
		n -= (s - 48) * power(10, len);
		write(fd, &s, 1);
	}
}
