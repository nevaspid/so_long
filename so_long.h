/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:01:19 by gloms             #+#    #+#             */
/*   Updated: 2023/05/20 14:11:35 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_map
{
	int		c; // collectible
	int		p; // personnage
	int		e; // exit
	int		z; // zennemi
	char	**map;
	int		lastline;
	int		x;
	int		y;
}			t_map;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);
int		struct_initiator(t_map *s_map, char *file);
int		ft_strlen(char *str);
int		ft_strlen_gnl(char *str, char c);
int		map_parser(char *file, t_map *s_map);
int		check_first_and_last(char *line);
int		check_middle_lines(char *line, t_map *s_map);
int		check_ber(char *file);
int		return_error(int returned);
int		count_map(char *file);

#endif