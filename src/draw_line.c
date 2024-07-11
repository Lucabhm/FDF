/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:26:44 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/11 15:50:11 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_loop(t_data data)
{
	int	i;

	i = 0;
	while (i < data.size.dots)
	{
		draw_dot(&data.dots[i], data);
		i++;
	}
}

void	draw_dot(t_map *dot, t_data data)
{
	if (dot->up && !dot->draw_up && !dot->up->draw_down)
	{
		draw_line(*dot, *dot->up, data);
		dot->draw_up = true;
		dot->up->draw_down = true;
	}
	if (dot->down && !dot->draw_down && !dot->down->draw_up)
	{
		draw_line(*dot, *dot->down, data);
		dot->draw_down = true;
		dot->down->draw_up = true;
	}
	if (dot->left && !dot->draw_left && !dot->left->draw_right)
	{
		draw_line(*dot, *dot->left, data);
		dot->draw_left = true;
		dot->left->draw_right = true;
	}
	if (dot->right && !dot->draw_right && !dot->right->draw_left)
	{
		draw_line(*dot, *dot->right, data);
		dot->draw_right = true;
		dot->right->draw_left = true;
	}
}

// void	first_step(int x, int y, int x_2, int y_2, t_data data)
// {
// 	t_pos	value;

// 	value.x = x;
// 	value.y = y;
// 	value.x_2 = x_2;
// 	value.y_2 = y_2;
// 	printf("x = %i y = %i x_2 = %i y_2 = %i\n", value.x, value.y, value.x_2, value.y_2);
// 	value.delta_x = value.x_2 - x;
// 	value.delta_y = value.y_2 - y;
// 	printf("dx = %f dy = %f\n", value.delta_x, value.delta_y);
// 	value.slope = value.delta_y / value.delta_x;
// 	printf("slope = %f\n", value.slope);
// 	if (value.slope > 1)
// 	{
// 		printf("bigger\n");
// 		slope_bigger(value, data);
// 	}
// 	else if (value.slope < 1)
// 	{
// 		printf("smaller\n");
// 		slope_smaller(value, data);
// 	}
// }

// void	slope_bigger(t_pos value, t_data data)
// {
// 	float	which_y;
// 	float	which_x;
// 	float	x;
// 	float	y;

// 	x = value.x;
// 	y = value.y;
// 	// printf("deltax = %f deltay = %f\n", value.delta_x, value.delta_y);
// 	if (value.delta_x > value.delta_y)
// 	{
// 		which_y = value.delta_y / value.delta_x;
// 		which_x = value.delta_x / value.delta_x;
// 	}
// 	else
// 	{
// 		which_y = value.delta_y / value.delta_y;
// 		which_x = value.delta_x / value.delta_y;
// 	}
// 	// printf("which_x = %f which_y = %f\n", which_x, which_y);
// 	while (y <= value.y_2)
// 	{
// 		printf("x = %f y = %f\n", x, y);
// 		draw_pixel(x, y, data);
// 		x += which_x;
// 		y += which_y;
// 	}
// }

// void	slope_smaller(t_pos value, t_data data)
// {
// 	float	which_y;
// 	float	which_x;
// 	float	x;
// 	float	y;

// 	x = value.x;
// 	y = value.y;
// 	// printf("deltax = %f deltay = %f\n", value.delta_x, value.delta_y);
// 	if (value.delta_x > value.delta_y)
// 	{
// 		which_y = value.delta_y / value.delta_x;
// 		which_x = value.delta_x / value.delta_x;
// 	}
// 	else
// 	{
// 		which_y = value.delta_y / value.delta_y;
// 		which_x = value.delta_x / value.delta_y;
// 	}
// 	// printf("which_x = %f which_y = %f\n", which_x, which_y);
// 	while (x <= value.x_2)
// 	{
// 		// printf("x = %f y = %f\n", x, y);
// 		draw_pixel(x, y, data);
// 		x += which_x;
// 		y += which_y;
// 	}
// }

void	draw_pixel(int x, int y, t_data data)
{
	int32_t	color;

	color = get_color(255, 0, 255, 255);
	mlx_put_pixel(data.img_map, x, y, color);
}

int32_t	get_color(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
