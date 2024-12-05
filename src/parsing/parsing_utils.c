/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:06:45 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/05 14:50:03 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc (sizeof(t_data));
	if (!data)
		error(ERROR_4, NULL);
	data->window = NULL;
	data->img_map = NULL;
	data->default_map = NULL;
	data->map = NULL;
	data->menu[0] = NULL;
	init_size(data);
	return (data);
}

void	init_size(t_data *data)
{
	data->size = (t_size *)malloc (sizeof(t_size));
	if (!data->size)
		error(ERROR_4, data);
	data->size->dots = 0;
	data->size->x_max = 0;
	data->size->y_max = 0;
	data->size->angle_z = 45;
	data->size->angle_y = 0;
	data->size->angle_x = atan(sqrt(0.5));
	data->size->dpi = 50;
	data->size->moved = false;
	data->size->projection = false;
	data->size->z_zoom = 1.0;
	data->size->center.x = 0;
	data->size->center.y = 0;
	data->size->center.z = 0;
	data->size->ratio = 300;
}

void	fill_dot(t_map *dot, char *z, t_size *size, int i)
{
	int	y;

	y = 1;
	while (i > size->x_max)
	{
		i -= size->x_max;
		y++;
	}
	dot->coords.x = i;
	dot->coords.y = y;
	pars_color(dot, z);
	dot->draw_up = false;
	dot->draw_down = false;
	dot->draw_left = false;
	dot->draw_right = false;
	dot->up = NULL;
	dot->down = NULL;
	dot->left = NULL;
	dot->right = NULL;
}

void	pars_color(t_map *dot, char *z)
{
	int		len;
	char	*tmp;

	len = 0;
	if (ft_strnstr(z, ",", ft_strlen(z)))
	{
		len = ft_strlen(ft_strnstr(z, ",", ft_strlen(z)));
		tmp = ft_substr(z, 0, ft_strlen(z) - len);
		dot->coords.z = ft_atoi(tmp);
		free(tmp);
		tmp = ft_substr(z, ft_strlen(z) - len + 3, ft_strlen(z));
		pars_color_2(dot, tmp);
		free(tmp);
	}
	if (!len)
	{
		dot->coords.z = ft_atoi(z);
		if (dot->coords.z == 0)
			pars_color_2(dot, "08A2BD");
		else
			pars_color_2(dot, "F08811");
	}
}

void	pars_color_2(t_map *dot, char *color)
{
	char	*tmp;

	tmp = ft_substr(color, 0, 2);
	dot->color.x = ft_htoi(tmp);
	free(tmp);
	tmp = ft_substr(color, 2, 2);
	dot->color.y = ft_htoi(tmp);
	free(tmp);
	tmp = ft_substr(color, 4, 2);
	dot->color.z = ft_htoi(tmp);
	free(tmp);
}
