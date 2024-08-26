/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:26:44 by lbohm             #+#    #+#             */
/*   Updated: 2024/08/26 17:30:52 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	drawLoop(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size.dots)
	{
		drawDot(&data->map[i], data);
		i++;
	}
}

void	drawDot(t_map *dot, t_data *data)
{
	if (dot->up && !dot->draw_up && !dot->up->draw_down)
	{
		drawLine(*dot, *dot->up, data);
		dot->draw_up = true;
		dot->up->draw_down = true;
	}
	if (dot->down && !dot->draw_down && !dot->down->draw_up)
	{
		drawLine(*dot, *dot->down, data);
		dot->draw_down = true;
		dot->down->draw_up = true;
	}
	if (dot->left && !dot->draw_left && !dot->left->draw_right)
	{
		drawLine(*dot, *dot->left, data);
		dot->draw_left = true;
		dot->left->draw_right = true;
	}
	if (dot->right && !dot->draw_right && !dot->right->draw_left)
	{
		drawLine(*dot, *dot->right, data);
		dot->draw_right = true;
		dot->right->draw_left = true;
	}
}

void	drawPixel(int x, int y, t_pos info, t_data *data)
{
	int		r;
	int		g;
	int		b;
	float	fraction;

	if (x > 0 && x < 1300 && y > 0 && y < 900)
	{
		if (info.dx)
			fraction = ((float)x - (float)info.startx) / (float)info.dx;
		else
			fraction = (float)x - (float)info.startx;
		r = info.c1.red + (info.c2.red - info.c1.red) * fraction;
		g = info.c1.green + (info.c2.green - info.c1.green) * fraction;
		b = info.c1.blue + (info.c2.blue - info.c1.blue) * fraction;
		mlx_put_pixel(data->img_map, x, y, getColor(r, g, b, 255));
	}
}

int32_t	getColor(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	htoi(char	*hexa)
{
	int		nbr;
	char	*base;
	int		i;
	int		j;
	int		size;

	base = "0123456789ABCDEF";
	nbr = 0;
	size = ft_strlen(hexa) - 1;
	i = size;
	while (hexa[i] != '#' && i >= 0)
	{
		j = 0;
		while (base[j] != hexa[i])
			j++;
		if (j == 17)
			error(ERROR_6, NULL);
		nbr += j * pow(16, size - i);
		i--;
	}
	free(hexa);
	return (nbr);
}

void	resetCheck(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size.dots)
	{
		data->map[i] = data->default_map[i];
		i++;
	}
}
