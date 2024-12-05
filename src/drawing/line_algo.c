/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:24:13 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/05 13:17:51 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	draw_line(t_map dot1, t_map dot2, t_data *data)
{
	t_pos	info;

	info.startx = dot1.coords.x;
	info.starty = dot1.coords.y;
	info.dx = dot2.coords.x - dot1.coords.x;
	info.dy = dot2.coords.y - dot1.coords.y;
	info.c1 = dot1.color;
	info.c2 = dot2.color;
	if (abs(info.dy) < abs(info.dx))
		slope_s(dot1, dot2, info, data);
	else
		slope_b(dot1, dot2, info, data);
}

void	slope_s(t_map dot1, t_map dot2, t_pos info, t_data *data)
{
	int	wp;

	wp = 2 * abs(info.dy) - abs(info.dx);
	while (dot1.coords.x != dot2.coords.x)
	{
		draw_pixel(dot1.coords.x, dot1.coords.y, info, data);
		if (info.dx > 0)
			dot1.coords.x++;
		else
			dot1.coords.x--;
		if (wp < 0)
			wp = wp + 2 * abs(info.dy);
		else
		{
			wp = wp + 2 * abs(info.dy) - 2 * abs(info.dx);
			if (info.dy > 0)
				dot1.coords.y++;
			else
				dot1.coords.y--;
		}
	}
	draw_pixel(dot1.coords.x, dot1.coords.y, info, data);
}

void	slope_b(t_map dot1, t_map dot2, t_pos info, t_data *data)
{
	int	wp;

	wp = 2 * abs(info.dx) - abs(info.dy);
	while (dot1.coords.y != dot2.coords.y)
	{
		draw_pixel(dot1.coords.x, dot1.coords.y, info, data);
		if (info.dy > 0)
			dot1.coords.y++;
		else
			dot1.coords.y--;
		if (wp < 0)
			wp = wp + 2 * abs(info.dx);
		else
		{
			wp = wp + 2 * abs(info.dx) - 2 * abs(info.dy);
			if (info.dx > 0)
				dot1.coords.x++;
			else
				dot1.coords.x--;
		}
	}
	draw_pixel(dot1.coords.x, dot1.coords.y, info, data);
}
