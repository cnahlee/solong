/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:02:21 by cnahle            #+#    #+#             */
/*   Updated: 2024/09/15 16:12:02 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_check_map(t_game *game);
void	ft_check_rows(t_game *game);
void	ft_check_columns(t_game *game);
void	ft_count_map_parameters(t_game *game);
void	ft_verify_map_parameters(t_game *game);

void	ft_check_map(t_game *game)
{
	ft_check_rows(game);
	ft_check_columns(game);
	ft_count_map_parameters(game);
	ft_verify_map_parameters(game);
}

void	ft_check_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.largeur)
	{
		if (game->map.map[i][0] != WALL)
			ft_error_msg("Invalid Map. \
There's a Wall missing from the first row.\n\
The Map must be surrounded by walls!.", game);
		else if (game->map.map[i][game->map.longueur] != WALL)
			ft_error_msg("Invalid Map. \
There's a Wall missing from the last row.\n\
The Map must be surrounded by walls!.", game);
		i++;
	}
}


void	ft_check_columns(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.longueur)
	{
		if (game->map.map[0][i] != WALL)
			ft_error_msg("Invalid Map. \
There's a Wall missing from the first column.\n\
The Map must be surrounded by walls!.", game);
		else if (game->map.map[game->map.largeur - 1][i] != WALL)
			ft_error_msg("Invalid Map. \
There's a Wall missing from the last column.\n\
The Map must be surrounded by walls!.", game);
		i++;
	}
}

void	ft_count_map_parameters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.largeur)
	{
		x = 0;
		while (x < game->map.longueur)
		{
			if (!ft_strchr("CEP01", game->map.map[y][x]))
				ft_error_msg("Invalid Map. Not expected map parameter.", game);
			else if (game->map.map[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.map[y][x] == COINS)
				game->map.coins++;
			else if (game->map.map[y][x] == MAP_EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

void	ft_verify_map_parameters(t_game *game)
{
	if (game->map.coins == 0)
		ft_error_msg("Invalid Map. There are no Coins!", game);
	else if (game->map.exit == 0)
		ft_error_msg("Invalid Map. There is no Exit.", game);
	else if (game->map.players != 1)
		ft_error_msg("Invalid Map. Invalid Player quantity. \
It's a single player game.", game);
}
