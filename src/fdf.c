/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:08:07 by lucabohn          #+#    #+#             */
/*   Updated: 2024/06/16 00:22:57 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int main(int argc, char **argv)
{
	t_data	data;

	parsing(argc, argv, &data);
	return (0);
}

void	parsing(int argc, char **argv, t_data *data)
{
	int		fd;
	char	*line;
	char	**split;

	fd = 0;
	if (argc == 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			error(ERROR_1, NULL);
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			split = ft_split(line, ' ');
		}
	}
	else
		error(ERROR_0, NULL);
}

void	error(char *msg, t_data *data)
{
	if (data)
		free(data);
	ft_putstr_fd(msg, 2);
	exit(1);
}