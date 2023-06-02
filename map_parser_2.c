/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:49:46 by gloms             #+#    #+#             */
/*   Updated: 2023/06/02 07:10:54 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int return_error(int returned)
{
	if (returned == -1)
	{
		write(2, "ERROR\nfirst or/and last map lines are wrong", 44);
		return (-1);
	}
	if (returned == -2)
	{
		write(2, "ERROR\none or several of the middle lines has a wrong character or map isn't square", 83);
	}
	if (returned == -3)
	{
		write(2, "ERROR\nplease add the missing Character, Collectible or Exit", 59);
	}
	if (returned == -4)
	{
		write(2, "ERROR\nwrong input file", 23);
	}
	if (returned == -5)
	{
		write(2, "ERROR\nmap isn't finishable", 26);
	}
	if (returned == -8)
		write(2, "ERROR\nin collusions", 20);
	exit(EXIT_FAILURE);
}
int	count_map(char *file)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (return_error(-4));
	if (read(fd, 0, 0) < 0)
		return (return_error(-4));
	line = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}
int where_is_p_x(t_map *s_map)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	while (s_map->map[++y])
	{
		while (s_map->map[y][++x])
		{
			if (s_map->map[y][x] == 'P')
			{
				s_map->px = x;
				return (x);
			}
		}
		x = -1;
	}
	return (-1);
}

int where_is_p_y(t_map *s_map)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	while (s_map->map[++y])
	{
		while (s_map->map[y][++x])
		{
			if (s_map->map[y][x] == 'P')
			{
				s_map->py = y;
				return (y);
			}
		}
		x = -1;
	}
	return (-1);
}
// int is_finishable(t_map *m, int x, int y)
// {

// }
