/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collusions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:10:46 by gloms             #+#    #+#             */
/*   Updated: 2023/06/02 07:26:41 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void game_over(t_map *m)
{
	write(1, "-------------\n", 15);
	write(1, "| ", 2);
	write(1, "\033[1;31mGame Over\033[00m", 21);
	write(1, " |\n", 4);
	write(1, "-------------\n", 15);
	mlx_terminate(m->mlx);
	free(m);
	exit(EXIT_SUCCESS);
}
int collusion(t_map *m, char a)
{
	if (a == 'w')
	{
		if (m->map[m->py - 1][m->px] == 'E' && m->c == 0)
			return(you_win(m), -1);
		if (m->map[m->py - 1][m->px] == 'C')
			return(rm_collectible(m, 'w'), -1);
		if (m->map[m->py - 1][m->px] == '1')
			return (-1);
		if (m->map[m->py - 1][m->px] == 'Z')
			return(game_over(m), 1);
	}
	if (a == 's')
	{
		if (m->map[m->py + 1][m->px] == 'E' && m->c == 0)
			return(you_win(m), -1);
		if (m->map[m->py + 1][m->px] == 'C')
			return(rm_collectible(m, 's'), -1);
		if (m->map[m->py + 1][m->px] == '1')
			return (-1);
		if (m->map[m->py + 1][m->px] == 'Z')
			return(game_over(m), 1);
	}
	return (1);
}
int collusion2(t_map *m, char a)
{
	if (a == 'a')
	{
		if (m->map[m->py][m->px - 1] == 'E' && m->c == 0)
			return(you_win(m), -1);
		if (m->map[m->py][m->px - 1] == 'C')
			return(rm_collectible2(m, 'a'), -1);
		if (m->map[m->py][m->px - 1] == '1')
			return (-1);
		if (m->map[m->py][m->px - 1] == 'Z')
			return(game_over(m), 1);
	}
	if (a == 'd')
	{
		if (m->map[m->py][m->px + 1] == 'E' && m->c == 0)
			return(you_win(m), -1);
		if (m->map[m->py][m->px + 1] == 'C')
			return(rm_collectible2(m, 'd'), -1);
		if (m->map[m->py][m->px + 1] == '1')
			return (-1);
		if (m->map[m->py][m->px + 1] == 'Z')
			return(game_over(m), 1);
	}
	return (1);
}

void rm_collectible(t_map *m, char a)
{
	if (m->c != 0)
	{
		if (a == 'w')
		{
			m->py -= 1;
			m->map[m->py][m->px] = '0';
			init_map(m);
		}
		if (a == 's')
		{
			m->py += 1;
			m->map[m->py][m->px] = '0';
			init_map(m);
		}
		m->c--;
	}
}
void rm_collectible2(t_map *m, char a)
{
	if (m->c != 0)
	{
		if (a == 'a')
		{
			m->px -= 1;
			m->map[m->py][m->px] = '0';
			init_map(m);
		}
		if (a == 'd')
		{
			m->px += 1;
			m->map[m->py][m->px] = '0';
			init_map(m);
		}
		m->c--;
	}
}

