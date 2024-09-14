/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:30:57 by cnahle            #+#    #+#             */
/*   Updated: 2024/09/14 16:40:32 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"


void	ft_free_all_allocated_memory(t_game *game);
void	ft_destroy_images(t_game *game);
void	ft_free_map(t_game *game);

void	ft_free_all_allocated_memory(t_game *game)
{
	ft_destroy_images(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
}

void	ft_destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx, game->floor.xpm_ptr);
	mlx_destroy_image(game->mlx, game->coins.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_front.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_left.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_right.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_back.xpm_ptr);
	mlx_destroy_image(game->mlx, game->exit_closed.xpm_ptr);
	mlx_destroy_image(game->mlx, game->open_exit.xpm_ptr);
}

void	ft_free_map(t_game *game)
{
	int	string;

	string = 0;
	while (string < game->map.largeur)
		free(game->map.map[string++]);
	free(game->map.map);
}
