/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:07:29 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/17 20:12:06 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	parsing(argc, argv, &data);
	cpy_map(&data);
	data.window = mlx_init(1600, 900, "fdf", true);
	data.img_map = mlx_new_image(data.window, 1300, 900);
	data.img_menu = mlx_new_image(data.window, 300, 900);
	memset(data.img_menu->pixels, 180, data.img_menu->width * data.img_menu->height * sizeof(int32_t));
	add_zoom(&data);
	rotate(&data);
	draw_loop(data);
	mlx_loop_hook(data.window, controll, &data);
	mlx_image_to_window(data.window, data.img_map, 300, 0);
	mlx_image_to_window(data.window, data.img_menu, 0, 0);
	mlx_loop(data.window);
	mlx_terminate(data.window);
	return (0);
}

void	parsing(int argc, char **argv, t_data *data)
{
	if (argc == 2)
	{
		printf("here\n");
		if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
			error(ERROR_5, NULL);
		fill_map(argv, data);
	}
	else
		error(ERROR_0, NULL);
}

void	error(char *msg, t_data *data)
{
	if (data)
		free(data);
	ft_putstr_fd(msg, 2);
	exit (1);
}

int	count_rows(char *file)
{
	int		fd;
	int		rows;

	rows = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(ERROR_1, NULL);
	while (get_next_line(fd))
		rows++;
	if (close(fd) == -1)
		error(ERROR_3, NULL);
	return (rows);
}

int	check_input(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j]) && split[i][j] != '\n')
			{
				free_dp(split);
				return (write(2, ERROR_2, ft_strlen(ERROR_2)), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	free_dp(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
