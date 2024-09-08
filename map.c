/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:59:29 by cnahle            #+#    #+#             */
/*   Updated: 2024/09/06 19:37:34 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

t_map	create_map(char *file_path)
{
	int		fd;
	char	*line;
	t_map	mapc;

	fd = open(file_path, O_RDONLY);
	/*if (fd < 0)
		perror("can't open file");*/
	mapc.longueur = 0;
	mapc.map = malloc(sizeof(char *) * 100); // Preallocate for 100 rows (adjust as needed)

	while ((line = get_next_line(fd)) != NULL)
	{
		mapc.map[mapc.longueur] = line; // Store the line in the map
		mapc.longueur++;
	}

	close(fd);

	if (mapc.longueur > 0)
		mapc.largeur = ft_strlen(mapc.map[0]); // Set map width based on first row
	return (mapc);
}
#include "solong.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	mapc;
	int		i;
	(void) argc;

	
	mapc = create_map(argv[1]);

	// Print map to verify
	i = 0;
	printf("Map Size: %d x %d\n", mapc.longueur, mapc.largeur);
	while (i < mapc.longueur)
	{
		printf("%s", mapc.map[i]); // Note: No newline needed since lines already have '\n'
		i++;
	}

	// Free allocated memory
	i = 0;
	while (i < mapc.longueur)
	{
		free(mapc.map[i]);
		i++;
	}
	free(mapc.map);

	return (0);
}
