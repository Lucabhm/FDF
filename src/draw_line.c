/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:26:44 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/11 20:40:48 by lucabohn         ###   ########.fr       */
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

void	draw_pixel(int x, int y, t_data data)
{
	int32_t	color;

	color = get_color(173, 216, 230, 255);
	mlx_put_pixel(data.img_map, x, y, color);
}

int32_t	get_color(int32_t r, int32_t g, int32_t b, int32_t a)
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