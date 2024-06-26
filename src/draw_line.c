/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:26:44 by lbohm             #+#    #+#             */
/*   Updated: 2024/06/26 17:23:40 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	first_step(int x, int y, int x_2, int y_2, t_data data)
{
	t_pos	value;

	value.x = x;
	value.y = y;
	value.x_2 = x_2;
	value.y_2 = y_2;
	value.delta_x = x_2 - x;
	value.delta_y = y_2 - y;
	value.slope = value.delta_y / value.delta_x;
	if (value.slope > 1)
	{
		printf("bigger\n");
		// slope_bigger(value, data);
	}
	else if (value.slope < 1)
		slope_smaller(value, data);
	else
	{
		printf("equal\n");
		// slope_equal(value, data);
	}
}

// void	slopw_equal(t_pos value, t_data data)
// {
// 	if (value.slope == 0)
// 	{
// 		while (value.x < value.x_2)
// 		{
// 			draw_pixel(value.x, value.y, data);
// 			value.x++;
// 		}
// 	}
// 	else
// 	{
		
// 	}
// }

void	slope_smaller(t_pos value, t_data data)
{
	int	which_p;

	which_p = 2 * value.delta_x - value.delta_y;
	while (value.x <= value.x_2)
	{
		printf("x = %i y = %i\n", value.x, value.y);
		draw_pixel(value.x, value.y, data);
		value.x++;
		if (which_p < 0)
			which_p += 2 * value.delta_y;
		else
		{
			which_p += 2 * value.delta_y - 2 * value.delta_x;
			value.y++;
		}
	}
}

void	draw_pixel(int x, int y, t_data data)
{
	int32_t	color;

	color = get_color(255, 0, 255, 255);
	mlx_put_pixel(data.img, x, y, color);
}

int32_t	get_color(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
