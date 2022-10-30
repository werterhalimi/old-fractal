/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:03:04 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/30 03:11:39 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	map_color(int t, int i, int n, double zoom)
{
	if (!t)
		return (create_trgb(1, 0, 0, 100 + i * 155 / n));
	if (t == 1)
		return (create_trgb(1, 50 / sqrt(zoom),
				10, 100 + i * 155 / n));
	if (t == 2)
		return (create_trgb(1, 0, 100 + i * 155 / n, 0));
	if (t == 3)
		return (create_trgb(1, 50, 25 + i * 100 / n, 50));
	return (create_trgb(1, 100 + i * 155 / n, 0, 0));
}
