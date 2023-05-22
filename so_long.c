/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:10:00 by gloms             #+#    #+#             */
/*   Updated: 2023/05/16 16:42:25 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//int so_long(t_map map, int fd)


int	main(int ac, char **av)
{
	t_map	*s_map;

	if (ac != 2)
		return (write(2, "Error\n", 6));
	s_map = malloc(sizeof(t_map));
	if (map_parser(av[1], s_map) < 0)
		return (write(2, "Error\n", 6));
	else 
		return (write(1, "ok", 2));
	return (1);
}

// int main(int ac, char **av)
// {
// 	int fd;
// 	char *line;

// 	line = NULL;
// 	fd = open(av[1], O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break;
// 		printf("%s", line);
// 		printf("%d\n%c\n", ft_strlen(line), line[11]);
// 		free(line);
// 	}
// 	return (0);
// }