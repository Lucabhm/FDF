/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:57:44 by lbohm             #+#    #+#             */
/*   Updated: 2024/08/01 12:33:12 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = init_data();
	parsing(argc, argv, data);
	data->window = mlx_init(data->size.width, data->size.height, "fdf", true);
	data->img_map = mlx_new_image(data->window, 1300, 900);
	data->img_menu = mlx_new_image(data->window, 300, 900);
	memset(data->img_menu->pixels, 128, data->img_menu->width \
	* data->img_menu->height * sizeof(int));
	mlx_image_to_window(data->window, data->img_map, 300, 0);
	mlx_image_to_window(data->window, data->img_menu, 0, 0);
}
