/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:39:22 by cnahle            #+#    #+#             */
/*   Updated: 2024/09/02 17:32:57 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include "mlx/mlx.h"
# include "libft.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

typedef struct s_game {
    void    *mlx;
    void    *win;
    char    **map;
    int     map_width;
    int     map_height;
    int     player_x;
    int     player_y;
    int     collectibles;
    int     moves;
} t_game;

// Function prototypes
void    error_exit(char *message);
char    **read_map(char *filename, t_game *game);
void    init_game(t_game *game, char *map_file);
void    start_game(t_game *game);
void    render_map(t_game *game);
void    handle_input(int keycode, t_game *game);
void    free_game(t_game *game);

#endif
