/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:37:22 by gloms             #+#    #+#             */
/*   Updated: 2023/06/01 16:21:50 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render_tx(t_map *map, char *path, int y, int x)
{
	mlx_image_t *img;
	mlx_texture_t *tx;

	tx = mlx_load_png(path);
	img = mlx_texture_to_image(map->mlx, tx);
	mlx_image_to_window(map->mlx, img, x * 64, y * 64);
}

void init_map(t_map *m)
{
	int y;
	int x;

	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == '1')
				render_tx(m, "assets/grasst.png", y, x);
			if (m->map[y][x] == '0' || m->map[y][x] == 'P')
				render_tx(m, "assets/grass.png", y, x);
			if (m->map[y][x] == 'C')
				render_tx(m, "assets/grasschili.png", y, x);
			if (m->map[y][x] == 'Z')
				render_tx(m, "assets/grassbs.png", y, x);
			if (m->map[y][x] == 'E')
				render_tx(m, "assets/grass.png", y, x);
			x++;
		}
		y++;
	}
	init_play(m);
}
