/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:24:13 by lbohm             #+#    #+#             */
/*   Updated: 2024/08/22 19:54:04 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	drawLine(t_map dot1, t_map dot2, t_data *data)
{
	t_pos	info;

	info.startx = dot1.x;
	info.starty = dot1.y;
	info.dx = dot2.x - dot1.x;
	info.dy = dot2.y - dot1.y;
	info.c1 = dot1.color;
	info.c2 = dot2.color;
	if (abs(info.dy) < abs(info.dx))
		slopeS(dot1, dot2, info, data);
	else
		slopeB(dot1, dot2, info, data);
}

void	slopeS(t_map dot1, t_map dot2, t_pos info, t_data *data)
{
	int	wp;

	wp = 2 * abs(info.dy) - abs(info.dx);
	while (dot1.x != dot2.x)
	{
		drawPixel(dot1.x, dot1.y, info, data);
		if (info.dx > 0)
			dot1.x++;
		else
			dot1.x--;
		if (wp < 0)
			wp = wp + 2 * abs(info.dy);
		else
		{
			wp = wp + 2 * abs(info.dy) - 2 * abs(info.dx);
			if (info.dy > 0)
				dot1.y++;
			else
				dot1.y--;
		}
	}
	drawPixel(dot1.x, dot1.y, info, data);
}

void	slopeB(t_map dot1, t_map dot2, t_pos info, t_data *data)
{
	int	wp;

	wp = 2 * abs(info.dx) - abs(info.dy);
	while (dot1.y != dot2.y)
	{
		drawPixel(dot1.x, dot1.y, info, data);
		if (info.dy > 0)
			dot1.y++;
		else
			dot1.y--;
		if (wp < 0)
			wp = wp + 2 * abs(info.dx);
		else
		{
			wp = wp + 2 * abs(info.dx) - 2 * abs(info.dy);
			if (info.dx > 0)
				dot1.x++;
			else
				dot1.x--;
		}
	}
	drawPixel(dot1.x, dot1.y, info, data);
}
