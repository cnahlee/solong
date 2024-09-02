/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:41:04 by cnahle            #+#    #+#             */
/*   Updated: 2024/09/02 17:25:02 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void error_exit(char *message) {
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(message, 2);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    t_game game;

    if (argc != 2) {
        error_exit("Usage: ./so_long <map_file.ber>\n");
    }
    init_game(&game, argv[1]);
    start_game(&game);
    free_game(&game);
    return (0);
}
