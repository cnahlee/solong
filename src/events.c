/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:19:17 by cnahle            #+#    #+#             */
/*   Updated: 2024/09/02 17:28:51 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void free_game(t_game *game) {
    int i = 0;

    while (game->map[i]) {
        free(game->map[i]);
        i++;
    }
    free(game->map);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
}
