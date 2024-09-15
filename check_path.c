/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:20:08 by cnahle            #+#    #+#             */
/*   Updated: 2024/09/15 18:31:08 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

#define VISITED 'V'  // Mark visited cells

// Recursive flood fill function to check the path from player to exit
int	ft_flood_fill(char **map, int x, int y, int rows, int cols)
{
	if (x < 0 || x >= cols || y < 0 || y >= rows || map[y][x] == WALL || map[y][x] == VISITED)
		return (0);

	// If we find the exit, return 1 (path found)
	if (map[y][x] == MAP_EXIT)
		return (1);

	// Mark the current cell as visited
	map[y][x] = VISITED;

	// Check all four possible directions (right, left, down, up)
	if (ft_flood_fill(map, x + 1, y, rows, cols) ||
		ft_flood_fill(map, x - 1, y, rows, cols) ||
		ft_flood_fill(map, x, y + 1, rows, cols) ||
		ft_flood_fill(map, x, y - 1, rows, cols))
		return (1);  // If any direction finds the exit

	return (0);  // No path found
}

// Function to check if a path exists from the player to the exit
void	ft_check_path_to_exit(t_game *game)
{
	char	**map_copy;
	int		i;
	int		path_exists;

	// Allocate memory for a copy of the map (we don't want to modify the original)
	map_copy = malloc(sizeof(char *) * (game->map.largeur + 1));
	if (!map_copy)
		ft_error_msg("Memory allocation failed for map copy", game);

	// Copy the map so we can modify it during flood fill
	i = 0;
	while (i < game->map.largeur)
	{
		map_copy[i] = ft_strdup(game->map.map[i]);
		i++;
	}
	map_copy[i] = NULL;  // Null-terminate the array

	// Perform flood fill from the player's position
	path_exists = ft_flood_fill(map_copy, game->map.player.x, game->map.player.y, game->map.largeur, game->map.longueur);

	// Free the copied map
	i = 0;
	while (i < game->map.largeur)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);

	// If no path exists, trigger an error message and exit
	if (!path_exists)
		ft_error_msg("No valid path from player to exit!", game);
}
