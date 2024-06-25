/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:08:07 by lucabohn          #+#    #+#             */
/*   Updated: 2024/06/25 12:10:20 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_test.h"

int	main(int argc, char **argv)
{
	t_data		data;
	int			i;
	int			j;
	mlx_image_t	*img;

	i = 0;
	j = 0;
	parsing(argc, argv, &data);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data.window = mlx_init(1600, 900, "fdf", true);
	img = mlx_new_image(data.window, 1600, 900);
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	while (data.map[i + 1])
	{
		j = 0;
		while (data.map[i][j + 1])
		{
			print_line('O', j * 32 + 32, i * 32 + 32, img);
			print_line('S', j * 32 + 32, i * 32 + 32, img);
			j++;
		}
		print_line('S', j * 32 + 32, i * 32 + 32, img);
		i++;
	}
	j = 0;
	while (data.map[i][j + 1])
	{
		print_line('O', j * 32 + 32, i * 32 + 32, img);
		j++;
	}
	mlx_image_to_window(data.window, img, 0, 0);
	mlx_loop(data.window);
	mlx_terminate(data.window);
	return (0);
}

void	print_line(char direction, int pos_x, int pos_y, mlx_image_t *img)
{
	int			i;
	uint32_t	color;

	i = 0;
	color = get_color(255, 100, 255, 255);
	if (direction == 'N')
	{
		while (i < 32)
		{
			mlx_put_pixel(img, pos_x, pos_y, color);
			i++;
			pos_y++;
		}
	}
	else if (direction == 'O')
	{
		while (i < 32)
		{
			mlx_put_pixel(img, pos_x, pos_y, color);
			i++;
			pos_x++;
		}
	}
	else if (direction == 'S')
	{
		while (i < 32)
		{
			mlx_put_pixel(img, pos_x, pos_y, color);
			i++;
			pos_y++;
		}
	}
	else if (direction == 'W')
	{
		while (i < 32)
		{
			mlx_put_pixel(img, pos_x, pos_y, color);
			i++;
			pos_x--;
		}
	}
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
	int		rows;
	int		i;

	fd = 0;
	rows = 0;
	i = 0;
	if (argc == 2)
	{
		rows = count_rows(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			error(ERROR_1, NULL);
		data->map = (char ***)malloc (sizeof(char **) * (rows + 1));
		if (!data->map)
			error(ERROR_4, NULL);
		data->map[rows] = NULL;
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			split = ft_split(line, ' ');
			check_input(split, data);
			data->map[i] = cpy_dp(split, data);
			free_dp(split);
			i++;
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
	if (close(fd) == -1)
		error(ERROR_3, NULL);
	return (rows);
}

void	check_input(char **split, t_data *data)
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
				error(ERROR_2, data);
			}
			j++;
		}
		i++;
	}
}

char	**cpy_dp(char **arr, t_data *data)
{
	int		i;
	char	**cpy;
	int		len;

	len = 0;
	i = 0;
	while (arr[i])
		i++;
	len = i;
	i = 0;
	cpy = (char **)malloc (sizeof(char *) * (len + 1));
	if (!cpy)
		error(ERROR_4, data);
	while (arr[i])
	{
		cpy[i] = ft_strdup(arr[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
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

void	free_tp(char ***arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free_dp(arr[i]);
		i++;
	}
	free(arr);
}

void	error(char *msg, t_data *data)
{
	if (data)
		free(data->map);
	ft_putstr_fd(msg, 2);
	exit(1);
}