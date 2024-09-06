/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:42:28 by cnahle            #+#    #+#             */
/*   Updated: 2024/09/06 20:04:25 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <fcntl.h>
#include <stdio.h>

// Function to load all textures for each map element
void	load_textures(t_game *game)
{
	int	width;
	int	height;

	game->textures[0] = mlx_xpm_file_to_image(game->mlx, "path_to_empty_texture.xpm", &width, &height);
	game->textures[1] = mlx_xpm_file_to_image(game->mlx, "path_to_wall_texture.xpm", &width, &height);
	game->textures[2] = mlx_xpm_file_to_image(game->mlx, "path_to_collectible_texture.xpm", &width, &height);
	game->textures[3] = mlx_xpm_file_to_image(game->mlx, "path_to_exit_texture.xpm", &width, &height);
	game->textures[4] = mlx_xpm_file_to_image(game->mlx, "path_to_player_texture.xpm", &width, &height);
}

// Function to render the map to the window based on `mapc`
void	render_map(t_game *game)
{
	int	x;
	int	y;

	for (y = 0; y < game->map.longueur; y++)
	{
		for (x = 0; x < game->map.largeur; x++)
		{
			if (game->map.map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->textures[0], x * 64, y * 64); // Empty space
			else if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->textures[1], x * 64, y * 64); // Wall
			else if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->textures[2], x * 64, y * 64); // Collectible
			else if (game->map.map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->textures[3], x * 64, y * 64); // Exit
			else if (game->map.map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->textures[4], x * 64, y * 64); // Player
		}
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	// Check if map file is passed as argument
	if (argc != 2)
	{
		printf("Usage: ./so_long <map_file.ber>\n");
		return (1);
	}

	// Load the map from the .ber file
	game.map = create_map(argv[1]);
	if (game.map.longueur == 0 || game.map.largeur == 0)
	{
		printf("Error: Failed to load map\n");
		return (1);
	}

	// Initialize MLX and create window
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.largeur * 64, game.map.longueur * 64, "so_long");

	// Load textures (make sure the paths to the XPM files are correct)
	load_textures(&game);

	// Render the map
	render_map(&game);

	// Start the game loop
	mlx_loop(game.mlx);

	return (0);
}
