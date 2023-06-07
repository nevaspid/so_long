/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:39:18 by gloms             #+#    #+#             */
/*   Updated: 2023/06/03 01:25:09 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_parser(char *file, t_map *m)
{
	int	i;

	i = 0;
	if (check_ber(file) < 0)
		return (return_error(-4, m));
	struct_initiator(m, file);
	while (i <= m->lastline)
	{
		if (i == 0 || i == m->lastline)
		{
			if (check_first_and_last(m->map[i]) < 0)
				return (return_error(-1, m));
		}
		else if (i > 0 && i < m->lastline)
		{
			if (check_middle_lines(m->map[i], m) < 0)
				return (return_error(-2, m));
		}
		i++;
	}
	if (m->p != 1 || m->e != 1 || m->c < 1)
	{
		return (return_error(-3, m));
	}
	return (0);
}

int	check_first_and_last(char *line)
{
	int	i;

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

int	check_middle_lines(char *ml, t_map *s_map)
{
	int	i;
	int	lenlastline;

	lenlastline = (ft_strlen(s_map->map[s_map->lastline - 1]));
	s_map->lenline = (ft_strlen(ml));
	i = 0;
	while (ml[i])
	{
		if ((ml[i] != 'P' && ml[i] != 'E' && ml[i] != 'Z'
				&& ml[i] != 'C' && ml[i] != '1' && ml[i] != '0'
				&& ml[i] != '\n') || ml[0] != '1'
			|| s_map->lenline != lenlastline
			|| ml[s_map->lenline - 2] != '1')
			return (-5);
		if (ml[i] == 'P')
			s_map->p += 1;
		if (ml[i] == 'E')
			s_map->e += 1;
		if (ml[i] == 'Z')
			s_map->z += 1;
		if (ml[i] == 'C')
			s_map->c += 1;
		i++;
	}
	return (1);
}

int	struct_initiator(t_map *m, char *file)
{
	int	i;
	int	fd;
	int	map_malloc;

	map_malloc = count_map(file);
	fd = open(file, O_RDONLY);
	i = 0;
	m->y = 0;
	m->x = 0;
	m->p = 0;
	m->e = 0;
	m->z = 0;
	m->c = 0;
	m->map = malloc(sizeof(char *) * (map_malloc + 1));
	m->duplicata_map = malloc(sizeof(char *) * (map_malloc + 1));
	m->map[i] = get_next_line(fd);
	m->duplicata_map[i] = ft_strdup(m->map[i]);
	while (++i < map_malloc)
	{
		m->map[i] = get_next_line(fd);
		m->duplicata_map[i] = ft_strdup(m->map[i]);
	}
	m->lastline = i - 1;
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
