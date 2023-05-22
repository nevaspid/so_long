/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:49:46 by gloms             #+#    #+#             */
/*   Updated: 2023/05/20 14:30:14 by gloms            ###   ########.fr       */
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