/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:38:43 by cnahle            #+#    #+#             */
/*   Updated: 2024/09/14 19:38:44 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "solong.h"

void	ft_init_vars(t_game *game)
{
	game->map.coins = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->movements = 0;
	game->map.longueur = ft_strlen(game->map.map[0]) - 1;
	game->player_sprite = RIGHT;
}

void	ft_init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		free(game->mlx);
		ft_error_msg("Couldn't find mlx pointer. Try it using a VNC.", game);
	}
	game->win = mlx_new_window(game->mlx, \
	game->map.longueur * IMG_WIDTH, game->map.largeur * IMG_HEIGHT, "so_long");
	if (game->win == NULL)
	{
		free(game->mlx);
		ft_error_msg("Couldn't create the Window.", game);
	}
}

void	ft_init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx;
	game->wall = ft_new_sprite(mlx, "wall.xpm", game);
	game->floor = ft_new_sprite(mlx, "floor.xpm", game);
	game->coins = ft_new_sprite(mlx,"coin.xpm", game);
	game->player_front = ft_new_sprite(mlx, "mariofront.xpm", game);
	/*game->player_left = ft_new_sprite(mlx, PLAYER_LEFT_XPM, game);
	game->player_right = ft_new_sprite(mlx, PLAYER_RIGHT_XPM, game);
	game->player_back = ft_new_sprite(mlx, PLAYER_BACK_XPM, game);*/
	game->open_exit = ft_new_sprite(mlx, "opendoor.xpm", game);
	game->exit_closed = ft_new_sprite(mlx, "closeddoor.xpm", game);
}

t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		ft_error_msg("Couldn't find a sprite. Does it exist?", game);
	return (sprite);
}