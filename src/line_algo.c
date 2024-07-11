/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:24:13 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/11 22:07:12 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_line(t_map dot1, t_map dot2, t_data data)
{
	t_pos	info;

	info.dx = dot2.x - dot1.x;
	info.dy = dot2.y - dot1.y;
	info.dot1_color = dot1.color;
	info.dot2_color = dot2.color;
	if (abs(info.dy) < abs(info.dx))
		slope_s(dot1, dot2, info, data);
	else
		slope_b(dot1, dot2, info, data);
}

void	slope_s(t_map dot1, t_map dot2, t_pos info, t_data data)
{
	int	wp;

	wp = 2 * abs(info.dy) - abs(info.dx);
	while (dot1.x != dot2.x)
	{
		draw_pixel(dot1.x, dot1.y, data);
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
	draw_pixel(dot1.x, dot1.y, data);
}

void	slope_b(t_map dot1, t_map dot2, t_pos info, t_data data)
{
	int	wp;

	wp = 2 * abs(info.dx) - abs(info.dy);
	while (dot1.y != dot2.y)
	{
		draw_pixel(dot1.x, dot1.y, data);
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
	draw_pixel(dot1.x, dot1.y, data);
}
