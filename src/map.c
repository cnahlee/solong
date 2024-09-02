/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:12:04 by cnahle            #+#    #+#             */
/*   Updated: 2024/09/02 17:25:07 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char **read_map(char *filename, t_game *game) {
    int     fd;
    char    *line;
    char    **map;
    int     i = 0;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error_exit("Failed to open map file\n");

    map = malloc(sizeof(char *) * (game->map_height + 1));
    if (!map)
        error_exit("Memory allocation failed\n");

    while ((line = get_next_line(fd))) {
        map[i++] = ft_strdup(line);
        free(line);
    }
    map[i] = NULL;
    close(fd);
    return (map);
}

void init_game(t_game *game, char *map_file) {
    game->mlx = mlx_init();
    if (!game->mlx)
        error_exit("Failed to initialize MLX\n");

    // Map dimensions and player position would be set after parsing the map
    game->map_height = 5; // Placeholder
    game->map_width = 13; // Placeholder
    game->collectibles = 0;
    game->moves = 0;

    game->map = read_map(map_file, game);
    if (!game->map)
        error_exit("Failed to load map\n");

    game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "So Long");
    if (!game->win)
        error_exit("Failed to create window\n");
}
