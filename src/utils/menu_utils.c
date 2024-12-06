/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:25:34 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/06 10:45:07 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	change_mouse_img(t_data *data)
{
	char	*str;
	char	*tmp;

	mlx_delete_image(data->window, data->menu[15]);
	tmp = ft_itoa(data->size->dpi);
	str = ft_strjoin("Mouse sensitivity: ", tmp);
	free(tmp);
	data->menu[15] = mlx_put_string(data->window, str, 10, 420);
	free(str);
}

void	change_projection_img(t_data *data)
{
	char	*str;

	mlx_delete_image(data->window, data->menu[16]);
	if (!data->size->projection)
		str = "Projection: Isometric";
	else
		str = "Projection: Parallel";
	data->menu[16] = mlx_put_string(data->window, str, 10, 445);
}

void	change_center_img(t_data *data)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	mlx_delete_image(data->window, data->menu[18]);
	tmp = ft_itoa(data->size->center.x);
	str = ft_strjoin("x = ", tmp);
	free(tmp);
	tmp = ft_strjoin(str, ", y = ");
	free(str);
	tmp2 = ft_itoa(data->size->center.y);
	str = ft_strjoin(tmp, tmp2);
	free(tmp2);
	free(tmp);
	data->menu[18] = mlx_put_string(data->window, str, 10, 495);
	free(str);
}
