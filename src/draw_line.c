/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:26:44 by lbohm             #+#    #+#             */
/*   Updated: 2024/08/01 21:31:04 by lucabohn         ###   ########.fr       */
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
	t_color	c1;
	t_color	c2;
	int		r;
	int		g;
	int		b;

	if (x > 0 && x < 1300 && y > 0 && y < 900)
	{
		c1.red = htoi(ft_substr(info.color1, 0, 2));
		c1.green = htoi(ft_substr(info.color1, 2, 2));
		c1.blue = htoi(ft_substr(info.color1, 4, 2));
		c2.red = htoi(ft_substr(info.color2, 0, 2));
		c2.green = htoi(ft_substr(info.color2, 2, 2));
		c2.blue = htoi(ft_substr(info.color2, 4, 2));
		r = c1.red + (c2.red - c1.red) * info.fraction;
		g = c1.green + (c2.green - c1.green) * info.fraction;
		b = c1.blue + (c2.blue - c1.blue) * info.fraction;
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
