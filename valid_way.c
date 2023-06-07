/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:41:18 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/03 01:31:09 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freeall(t_map *m)
{
	int	i;

	i = -1;
	if (m->duplicata_map && m->lastline)
	{
		while (++i <= m->lastline)
			free(m->duplicata_map[i]);
		free(m->duplicata_map);
	}
	i = -1;
	if (m->map && m->lastline)
	{
		while (++i <= m->lastline)
			free(m->map[i]);
		free(m->map);
	}
}

int	valid_way(t_map *m, int x, int y)
{
	if (m->duplicata_map[y][x] == 'P')
		m->duplicata_map[y][x] = '0';
	if (m->duplicata_map[y][x] == 'C')
	{
		m->c_copy--;
		m->duplicata_map[y][x] = '0';
	}
	if (m->duplicata_map[y][x] == 'E' && m->c_copy == 0)
		return (1);
	if (m->duplicata_map[y][x] == '0')
	{
		m->duplicata_map[y][x] = '1';
		if (valid_way(m, (x - 1), y) || valid_way(m, (x + 1), y)
			|| valid_way(m, x, (y - 1)) || valid_way(m, x, (y + 1)))
			return (1);
		return (0);
	}
	return (0);
}
