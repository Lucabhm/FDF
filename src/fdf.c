/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:07:29 by lbohm             #+#    #+#             */
/*   Updated: 2024/06/28 17:31:31 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_data		data;
	int			i;
	int			j;
	int			rows;

	i = 0;
	j = 0;
	rows = count_rows(argv[1]);
	parsing(argc, argv, &data);
	data.window = mlx_init(1600, 900, "fdf", true);
	data.img = mlx_new_image(data.window, 1600, 900);
	memset(data.img->pixels, 255, data.img->width * data.img->height * sizeof(int32_t));
	while (i <= rows)
	{
		j = 0;
		while (j < data.map[0][0])
		{
			first_step(j * 50 + 50, i * 50 + 50, j * 50 + 100, i * 50 + 50, data);
			j++;
		}
		i++;
	}
	j = 0;
	i = 0;
	printf("here\n");
	while (j <= data.map[0][0])
	{
		i = 0;
		while (i < rows)
		{
			first_step(j * 50 + 50, i * 50 + 50, j * 50 + 50, i * 50 + 100, data);
			i++;
		}
		j++;
	}
	// first_step(50, 50, 100, 50, data);
	mlx_image_to_window(data.window, data.img, 0, 0);
	mlx_loop(data.window);
	mlx_terminate(data.window);
}

void	parsing(int argc, char **argv, t_data *data)
{
	if (argc == 2)
	{
		if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
			error(ERROR_5, NULL);
		data->map = fill_map(argv);
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

int	**fill_map(char **argv)
{
	int		i;
	int		j;
	int		fd;
	int		rows;
	int		**map;
	char	*line;
	char	**split;

	i = 0;
	j = 0;
	fd = 0;
	line = NULL;
	split = NULL;
	rows = count_rows(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(ERROR_1, NULL);
	map = (int **)malloc (sizeof(int *) * rows);
	if (!map)
		error(ERROR_4, NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		if (check_input(split))
		{
			free(map);
			break ;
		}
		map[i] = fill_rows(split);
		if (!map[i])
		{
			free(map);
			break ;
		}
		free_dp(split);
		i++;
	}
	if (close(fd) == -1)
	{
		free(map);
		error(ERROR_3, NULL);
	}
	return (map);
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

int	*fill_rows(char **split)
{
	int		*row;
	int		nbr;
	int		i;
	int		len;

	nbr = 0;
	i = 0;
	len = 0;
	while (split[i])
	{
		nbr++;
		i++;
	}
	i = 0;
	row = (int *)malloc (sizeof(int) * (nbr + 1));
	if (!row)
	{
		free_dp(split);
		return (write(2, ERROR_4, ft_strlen(ERROR_4)), NULL);
	}
	row[i] = nbr;
	while (split[i])
	{
		if (!ft_strnstr(split[i], ",", ft_strlen(split[i])))
			row[i + 1] = ft_atoi(split[i]);
		else
		{
			len = ft_strlen(split[i]) - ft_strlen(ft_strnstr(split[i], ",", ft_strlen(split[i])));
			split[i][len] = 0;
			row[i + 1] = ft_atoi(split[i]);
		}
		i++;
	}
	return (row);
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
