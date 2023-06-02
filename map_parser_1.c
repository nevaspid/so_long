/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:39:18 by gloms             #+#    #+#             */
/*   Updated: 2023/06/02 06:41:21 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_parser(char *file, t_map *s_map)
{
	int	i;

	i = 0;
	if (check_ber(file) < 0)
		return (return_error(-4));
	struct_initiator(s_map, file);
	while (s_map->map[i])
	{
		if (i == 0 || i == s_map->lastline)
		{
			if (check_first_and_last(s_map->map[i]) < 0)
				return (return_error(-1));
		}
		if (i > 0)
		{
			if (check_middle_lines(s_map->map[i], s_map) < 0)
				return (return_error(-2));
		}
		i++;
	}
	if (s_map->p != 1 || s_map->e != 1 || s_map->c < 1) 
	{
		return (return_error(-3));
	}
	return (0);
}

int	check_first_and_last(char *line)
{
	int	i;
	int	lenline;

	lenline = (ft_strlen(line) - 2);
	i = 0;
	while (line[i] == '1')
	{
		i++;
		if (line[i] == '\n')
			break ;
		if (line[i] != '1')
			return (-1);
	}
	return (0);
}

int	check_middle_lines(char *map_line, t_map *s_map)
{
	int	i;
	int	lenlastline;

	lenlastline = (ft_strlen(s_map->map[s_map->lastline]) - 2);
	s_map->lenline = (ft_strlen(map_line) - 2);
	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != 'P' && map_line[i] != 'E' && map_line[i] != 'Z'
			&& map_line[i] != 'C' && map_line[i] != '1' && map_line[i] != '0'
			&& map_line[i] != '\n' || map_line[0] != '1'
			|| s_map->lenline != lenlastline || map_line[s_map->lenline] != '1')
			return (-5);
		if (map_line[i] == 'P')
			s_map->p += 1;
		if (map_line[i] == 'E')
			s_map->e += 1;
		if (map_line[i] == 'Z')
			s_map->z += 1;
		if (map_line[i] == 'C')
			s_map->c += 1;
		i++;
	}
	return (1);
}

int	struct_initiator(t_map *s_map, char *file)
{
	int	i;
	int	fd;
	int	map_malloc;

	map_malloc = count_map(file);
	fd = open(file, O_RDONLY);
	i = 0;
	s_map->y = 0;
	s_map->x = 0;
	s_map->p = 0;
	s_map->e = 0;
	s_map->z = 0;
	s_map->c = 0;
	s_map->moves = 0;
	s_map->map = malloc(sizeof(char *) * map_malloc + 1);
	s_map->duplicata_map = malloc(sizeof(char *) * map_malloc + 1);
	s_map->map[i] = get_next_line(fd);
	while (s_map->map[i])
	{
		s_map->map[++i] = get_next_line(fd);
		s_map->duplicata_map[i] = s_map->map[i];
	}
	s_map->lastline = i - 1;
	close(fd);
	return (0);
}

int	check_ber(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 4] == '.' && file[i - 3] == 'b'
		&& file[i - 2] == 'e' && file[i - 1] == 'r')
		return (0);
	return (-6);
}