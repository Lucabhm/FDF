/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:26:44 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/04 19:37:14 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	draw_loop(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size->dots)
	{
		draw_dot(&data->map[i], data);
		i++;
	}
}

void	draw_dot(t_map *dot, t_data *data)
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

void	draw_pixel(int x, int y, t_pos info, t_data *data)
{
	int		r;
	int		g;
	int		b;
	float	fraction;

	if (x > 0 && x < (data->window->width - data->size->ratio)
		&& y > 0 && y < data->window->height)
	{
		if (abs(info.dy) < abs(info.dx))
			fraction = ((float)x - (float)info.startx) / (float)info.dx;
		else
			fraction = ((float)y - (float)info.starty) / (float)info.dy;
		r = info.c1.x + (info.c2.x - info.c1.x) * fraction;
		g = info.c1.y + (info.c2.y - info.c1.y) * fraction;
		b = info.c1.z + (info.c2.z - info.c1.z) * fraction;
		mlx_put_pixel(data->img_map, x, y, get_color(r, g, b, 255));
	}
}

int	get_color(int r, int g, int b, int a)
{
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	return (r << 24 | g << 16 | b << 8 | a);
}

int	ft_htoi(char *hexa)
{
	char	*base;
	int		result;
	int		i;
	int		pos;

	base = "0123456789ABCDEFabcdef";
	result = 0;
	i = ft_strlen(hexa) - 1;
	while (i >= 0)
	{
		pos = 0;
		while (base[pos] && base[pos] != hexa[i])
			pos++;
		if (pos > 15 && pos < 22)
			pos -= 6;
		if (pos == 22)
			return (printf("Hexa wrong input\n"), 0);
		result += pos * pow(16, (ft_strlen(hexa) - 1) - i);
		i--;
	}
	return (result);
}
