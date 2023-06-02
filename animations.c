/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:29:39 by gloms             #+#    #+#             */
/*   Updated: 2023/06/02 08:16:31 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int where_e_y(t_map *s_map)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	while (s_map->map[++y])
	{
		while (s_map->map[y][++x])
		{
			if (s_map->map[y][x] == 'E')
			{
				return (y);
			}
		}
		x = -1;
	}
	return (-1);
}
static int where_e_x(t_map *s_map)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	while (s_map->map[++y])
	{
		while (s_map->map[y][++x])
		{
			if (s_map->map[y][x] == 'E')
			{
				return (x);
			}
		}
		x = -1;
	}
	return (-1);
}
static mlx_texture_t *return_portal(int i)
{
	mlx_texture_t *texture;

	if (i == 0)
		texture = mlx_load_png("assets/portal.png/p0.png");
	else if (i == 1)
		texture = mlx_load_png("assets/portal.png/p1.png");
	else if (i == 2)
		texture = mlx_load_png("assets/portal.png/p2.png");
	else if (i == 3)
		texture = mlx_load_png("assets/portal.png/p3.png");
	else if (i == 4)
		texture = mlx_load_png("assets/portal.png/p4.png");
	else if (i == 5)
		texture = mlx_load_png("assets/portal.png/p5.png");
	else if (i == 6)
		texture = mlx_load_png("assets/portal.png/p6.png");
	else if (i == 7)
		texture = mlx_load_png("assets/portal.png/p7.png");
	else if (i == 8)
		texture = mlx_load_png("assets/portal.png/p8.png");
	return (texture);
}


void spawn_portal(t_map *m)
{
	static int anim = 0;
	static int frames = 0;
	mlx_texture_t *texture;
	while (++frames < 8)
		return ;
	mlx_delete_image(m->mlx, m->portal);
	texture = return_portal(anim);
	anim++;
	if (anim == 9)
		anim = 0;
	frames = 0;
	m->portal = mlx_texture_to_image(m->mlx, texture);
	mlx_resize_image(m->portal, 64, 64);
	mlx_image_to_window(m->mlx, m->portal, where_e_x(m) * 64, where_e_y(m) * 64);
}

void portal_anim(void *param)
{
	t_map *m;

	m = param;
	if(m->c == 0)
	{
		spawn_portal(m);
	}
}
