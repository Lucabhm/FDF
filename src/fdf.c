/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:08:07 by lucabohn          #+#    #+#             */
/*   Updated: 2024/06/18 23:13:37 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_data		data;
	mlx_image_t	*img;
	uint32_t	color;
	int			i;
	int			y;

	i = 50;
	y = 50;
	// parsing(argc, argv, &data);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	// mlx_set_setting(MLX_DECORATED, true);
	data.window = mlx_init(500, 500, "fdf", true);
	img = mlx_new_image(data.window, 250, 250);
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	color = get_color(255, 0, 255, 255);
	while (i < 100)
	{
		mlx_put_pixel(img, i, y, color);
		i++;
	}
	while (y < 100)
	{
		mlx_put_pixel(img, i, y, color);
		y++;
	}
	while (i > 50)
	{
		mlx_put_pixel(img, i, y, color);
		i--;
	}
	while (y > 50)
	{
		mlx_put_pixel(img, i, y, color);
		y--;
	}
	mlx_image_to_window(data.window, img, 0, 0);
	mlx_loop(data.window);
	mlx_terminate(data.window);
	return (0);
}

int32_t	get_color(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	parsing(int argc, char **argv, t_data *data)
{
	int		fd;
	char	*line;
	char	**split;

	fd = 0;
	if (argc == 1)
	{
		count_rows(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			error(ERROR_1, NULL);
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			split = ft_split(line, ' ');
			check_input(split);
			
		}
	}
	else
		error(ERROR_0, NULL);
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
	return (rows);
}

void	check_input(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j]))
			{
				free_dp(split);
				error(ERROR_2, NULL);
			}
			j++;
		}
		i++;
	}
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

void	error(char *msg, t_data *data)
{
	if (data)
		free(data);
	ft_putstr_fd(msg, 2);
	exit(1);
}