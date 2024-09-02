/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:18:53 by cnahle            #+#    #+#             */
/*   Updated: 2024/09/02 17:24:59 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void render_map(t_game *game) {
    int x, y;

    for (y = 0; y < game->map_height; y++) {
        for (x = 0; x < game->map_width; x++) {
            if (game->map[y][x] == '1')
                ; // Draw wall
            else if (game->map[y][x] == '0')
                ; // Draw empty space
            else if (game->map[y][x] == 'C')
                ; // Draw collectible
            else if (game->map[y][x] == 'E')
                ; // Draw exit
            else if (game->map[y][x] == 'P') {
                game->player_x = x;
                game->player_y = y;
                ; // Draw player
            }
        }
    }
}
