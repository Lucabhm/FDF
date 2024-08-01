/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:06:45 by lbohm             #+#    #+#             */
/*   Updated: 2024/08/01 21:35:56 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_data	*initData(void)
{
	t_data	*data;

	data = (t_data *)malloc (sizeof(t_data));
	if (!data)
		error(ERROR_4, NULL);
	data->map = NULL;
	data->default_map = NULL;
	data->size.dots = 0;
	data->size.x_max = 0;
	data->size.y_max = 0;
	data->size.width = 1600;
	data->size.height = 900;
	data->window = NULL;
	data->img_map = NULL;
	data->img_menu = NULL;
	data->zoom = 31;
	data->angle_z = 45;
	data->angle_y = 45;
	data->angle_x = 0;
	data->dpi = 40;
	return (data);
}

void	fillDot(t_map	*dot, char *z, t_size size, int i)
{
	int	y;

	y = 1;
	while (i > size.x_max)
	{
		i -= size.x_max;
		y++;
	}
	dot->x = i;
	dot->y = y;
	dot->z = ft_atoi(z);
	if (dot->z == 0)
		dot->color = "F18F08";
	else
		dot->color = "00FFFF";
	dot->draw_up = false;
	dot->draw_down = false;
	dot->draw_left = false;
	dot->draw_right = false;
	dot->up = NULL;
	dot->down = NULL;
	dot->left = NULL;
	dot->right = NULL;
}

void	addToMap(t_map *dot, t_map **map, t_size size)
{
	t_map	*start;
	t_map	*tmp;

	start = *map;
	if (!start)
		*map = dot;
	else
	{
		if (dot->y == 1)
		{
			while (start->right)
				start = start->right;
			dot->left = start;
			start->right = dot;
		}
		else if (dot->y <= size.y_max)
		{
			if (dot->x == 1)
			{
				while (start->down)
					start = start->down;
				dot->up = start;
				start->down = dot;
			}
			else
			{
				while (start->down)
				{
					if (!start->down->down)
						tmp = start;
					start = start->down;
				}
				while (start->right)
				{
					start = start->right;
					tmp = tmp->right;
				}
				tmp = tmp->right;
				dot->left = start;
				dot->up = tmp;
				tmp->down = dot;
				start->right = dot;
			}
		}
	}
}
