/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:18:15 by cnahle            #+#    #+#             */
/*   Updated: 2024/09/02 17:29:22 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void start_game(t_game *game) {
    render_map(game);
    mlx_key_hook(game->win, handle_input, game);
    mlx_loop(game->mlx);
}

void handle_input(int keycode, t_game *game) {
    if (keycode == 53) { // ESC key to exit
        mlx_destroy_window(game->mlx, game->win);
        free_game(game);
        exit(0);
    }
    // Movement keys (WASD) and logic will be implemented here
}
