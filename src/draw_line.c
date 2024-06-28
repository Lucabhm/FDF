/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:26:44 by lbohm             #+#    #+#             */
/*   Updated: 2024/06/28 17:30:37 by lbohm            ###   ########.fr       */
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
	isometric(&value.x_2, &value.y_2);
	printf("x = %i y = %i x_2 = %i y_2 = %i\n", value.x, value.y, value.x_2, value.y_2);
	if (value.x_2 > x)
		value.delta_x = value.x_2 - x;
	else
		value.delta_x = x - value.x_2;
	if (value.y_2 > y)
		value.delta_y = value.y_2 - y;
	else
		value.delta_y = y - value.y_2;
	printf("dx = %f dy = %f\n", value.delta_x, value.delta_y);
	value.slope = value.delta_y / value.delta_x;
	printf("slope = %f\n", value.slope);
	if (value.slope > 1)
	{
		printf("bigger\n");
		slope_bigger(value, data);
	}
	else if (value.slope < 1)
	{
		printf("smaller\n");
		slope_smaller(value, data);
	}
}

void	slope_bigger(t_pos value, t_data data)
{
	float	which_y;
	float	which_x;
	float	x;
	float	y;

	x = value.x;
	y = value.y;
	printf("deltax = %f deltay = %f\n", value.delta_x, value.delta_y);
	if (value.delta_x > value.delta_y)
	{
		which_y = value.delta_y / value.delta_x;
		which_x = value.delta_x / value.delta_x;
	}
	else
	{
		which_y = value.delta_y / value.delta_y;
		which_x = value.delta_x / value.delta_y;
	}
	printf("which_x = %f which_y = %f\n", which_x, which_y);
	while (y <= value.y_2)
	{
		printf("x = %f y = %f\n", x, y);
		draw_pixel(x, y, data);
		x += which_x;
		y += which_y;
	}
}

void	slope_smaller(t_pos value, t_data data)
{
	float	which_y;
	float	which_x;
	float	x;
	float	y;

	x = value.x;
	y = value.y;
	printf("deltax = %f deltay = %f\n", value.delta_x, value.delta_y);
	if (value.delta_x > value.delta_y)
	{
		which_y = value.delta_y / value.delta_x;
		which_x = value.delta_x / value.delta_x;
	}
	else
	{
		which_y = value.delta_y / value.delta_y;
		which_x = value.delta_x / value.delta_y;
	}
	printf("which_x = %f which_y = %f\n", which_x, which_y);
	while (x <= value.x_2)
	{
		printf("x = %f y = %f\n", x, y);
		draw_pixel(x, y, data);
		x += which_x;
		y += which_y;
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

void	isometric(int *x, int *y)
{
	// int	tmp_x;
	// int	tmp_y;

	// tmp_x = *x;
	// tmp_y = *y;
	// *x = tmp_x * cos(45) - tmp_y * sin(45);
	// *y = tmp_x * sin(45) + tmp_y * cos(45);
	int tmp;

	tmp = *x;
	*x = (tmp - *y) * cos(0.523599);
	*y = (tmp + *y) * sin(0.523599);
}
