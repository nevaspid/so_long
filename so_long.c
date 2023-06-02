/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:10:00 by gloms             #+#    #+#             */
/*   Updated: 2023/06/02 07:11:50 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_play(t_map *m)
{
	mlx_texture_t *texture;

    texture = mlx_load_png("assets/slimeright/sr0.png");
    m->player = mlx_texture_to_image(m->mlx, texture);
    mlx_image_to_window(m->mlx, m->player, m->px * 64, m->py * 64);
}

void 	key(mlx_key_data_t keydata, void *param)
{
	t_map *m;

	m = param;
	(void)keydata;
	if (mlx_is_key_down(m->mlx, MLX_KEY_W) && collusion(m, 'w') > 0)
	{
		m->py -= 1;
		m->player->instances[0].y -= 1 * 64;
	}
	if (mlx_is_key_down(m->mlx, MLX_KEY_S) && collusion(m, 's') > 0)
	{
		m->py += 1;
		m->player->instances[0].y += 1 * 64;
	}
	if (mlx_is_key_down(m->mlx, MLX_KEY_A) && collusion2(m, 'a') > 0)
	{
		m->px -=1;
		m->player->instances[0].x -= 1 * 64;
	}
	if (mlx_is_key_down(m->mlx, MLX_KEY_D) && collusion2(m, 'd') > 0)
	{
		m->px += 1;
		m->player->instances[0].x += 1 * 64;
	}
}

int	main(int ac, char **av)
{
	t_map	*s_map;

	if (ac != 2)
		return (write(2, "Error\n", 6));
	s_map = malloc(sizeof(t_map));
	map_parser(av[1], s_map);
	s_map->c_copy = s_map->c;
	where_is_p_y(s_map);
	where_is_p_x(s_map);
	//is_finishable(s_map, where_is_p_y(s_map), where_is_p_x(s_map));
	s_map->mlx = mlx_init((s_map->lenline + 1) * 64, (s_map->lastline + 1) * 64, "so_long", true);
	init_map(s_map);
	mlx_key_hook(s_map->mlx, &key, s_map);
	mlx_loop_hook(s_map->mlx, &portal_anim, s_map);
	mlx_loop(s_map->mlx);
	return (1);
}
