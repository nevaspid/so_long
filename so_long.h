/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:01:19 by gloms             #+#    #+#             */
/*   Updated: 2023/06/03 01:08:19 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_map
{
	int			c;
	int			c_copy;
	int			p;
	int			e;
	int			z;
	char		**map;
	char		**duplicata_map;
	int			lastline;
	int			lenline;
	int			x;
	int			y;
	int			py;
	int			px;
	int			moves;
	int			xmax;
	int			ymax;
	mlx_image_t	*player;
	mlx_image_t	*portal;
	mlx_t		*mlx;

}				t_map;

void			key(mlx_key_data_t keydata, void *param);
char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strdup(char *s);
int				struct_initiator(t_map *s_map, char *file);
int				ft_strlen(char *str);
int				ft_strlen_gnl(char *str, char c);
int				map_parser(char *file, t_map *s_map);
int				check_first_and_last(char *line);
int				check_middle_lines(char *line, t_map *s_map);
int				check_ber(char *file);
int				return_error(int returned, t_map *m);
int				count_map(char *file);
int				where_is_p_y(t_map *s_map);
int				where_is_p_x(t_map *s_map);
void			render_tx(t_map *map, char *path, int y, int x);
void			init_map(t_map *m);
mlx_texture_t	*slimedown(int i);
mlx_texture_t	*slime_top(int i);
mlx_texture_t	*slimeleft(int i);
mlx_texture_t	*slimeright(int i);
int				c(t_map *m, char a);
int				c2(t_map *m, char a);
void			game_over(t_map *m);
void			rm_collectible(t_map *m, char a);
void			rm_collectible2(t_map *m, char a);
void			you_win(t_map *m);
void			init_play(t_map *m);
void			spawn_portal(t_map *map);
void			portal_anim(void *param);
void			freeall(t_map *m);
int				valid_way(t_map *m, int x, int y);
int				ft_putnbr_pf(long long nb);
int				pm(t_map *m, char a);

#endif