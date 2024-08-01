/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:11:12 by lbohm             #+#    #+#             */
/*   Updated: 2024/08/01 21:38:01 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	parsing(int argc, char **argv, t_data *data)
{
	if (argc == 2)
	{
		if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
			error(ERROR_5, data);
		fillMap(argv, data);
		data->window = mlx_init(data->size.width, data->size.height, "fdf", true);
		data->img_map = mlx_new_image(data->window, 1300, 900);
		data->img_menu = mlx_new_image(data->window, 300, 900);
		mlx_image_to_window(data->window, data->img_map, 300, 0);
		mlx_image_to_window(data->window, data->img_menu, 0, 0);
	}
	else
		error(ERROR_0, data);
}

void	fillMap(char **argv, t_data *data)
{
	int		i;
	int		fd;
	char	**split;
	t_map	*dots;

	dots = NULL;
	i = 0;
	countSize(argv[1], data);
	data->map = (t_map *)malloc (data->size.dots * sizeof(t_map));
	data->default_map = (t_map *)malloc (data->size.dots * sizeof(t_map));
	if (!data->map || !data->default_map)
		error(ERROR_4, data);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(ERROR_1, data);
	while (i < data->size.dots)
	{
		split = ft_split(get_next_line(fd), ' ');
		while (*split)
		{
			fillDot(&data->map[i], *split, data->size, i + 1);
			addToMap(&data->map[i], &dots, data->size);
			data->default_map[i] = data->map[i];
			split++;
			i++;
		}
	}
}

void	countSize(char *file, t_data *data)
{
	char	*line;
	char	**split;
	int		fd;
	int		dots;

	dots = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error(ERROR_1, data);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		free(line);
		dots += countElements(split, data);
		data->size.y_max++;
		if (data->size.y_max == 1)
			data->size.x_max = dots;
		freeDp(split);
	}
	data->size.dots = dots;
	if (close(fd) == -1)
		error(ERROR_3, data);
}

int	countElements(char **split, t_data *data)
{
	int	i;

	i = 0;
	while (split[i])
	{
		checkValue(split[i], data);
		i++;
	}
	return (i);
}

void	checkValue(char *value, t_data *data)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (ft_strnstr(value, ",", ft_strlen(value)))
		len = ft_strlen(ft_strnstr(value, ",", ft_strlen(value)));
	while (i < ft_strlen(value) - len && value[i] != '\n')
	{
		if (!ft_isdigit(value[i]) && value[0] != '-' && i == 0)
		{
			printf("value = %c\n", value[i]);
			error(ERROR_7, data);
		}
		i++;
	}
}
