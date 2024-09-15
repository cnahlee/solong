/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:23:49 by cnahle            #+#    #+#             */
/*   Updated: 2024/09/15 18:32:51 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"solong.h"


void	ft_putstr(char*s)


{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
int	ft_error_msg(char *message, t_game *game)
{
	if (game->map_alloc == true)
		ft_free_map(game);
	free(game);
	ft_putstr(message);
	exit (EXIT_FAILURE);
}

void ft_check_command_line_arguments(int argc, char **argv, t_game *game)
{
    int map_parameter_len;

    game->map_alloc = false;
    if (argc != 2)
        ft_error_msg("Usage: ./so_long <map_file>. (It should be only one argument.)", game);

    map_parameter_len = ft_strlen(argv[1]);
    if (map_parameter_len < 4 || !ft_strnstr(&argv[1][map_parameter_len - 4], ".ber", 4))
        ft_error_msg("Map file extension is wrong (It should be .ber).", game);
}

void	ft_init_map(t_game *game, char *argv)
{
	char	*map_temp;
	char	*line_temp;
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		ft_error_msg("The Map couldn't be opened. Does the Map exist?", game);
	map_temp = ft_strdup("");
	game->map.largeur= 0;
	while (true)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		map_temp = ft_strappend(&map_temp, line_temp);
		free(line_temp);
		game->map.largeur++;
	}
	close(map_fd);
	ft_check_for_empty_line(map_temp, game);
	game->map.map = ft_split(map_temp, '\n');
	game->map_alloc = true;
	free(map_temp);
}


void	ft_check_for_empty_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		ft_error_msg("Invalid map.\
The map have an empty line right at the beginning.", game);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free (map);
		ft_error_msg("Invalid map. \
The map have an empty line at the end.", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_msg("Invalid map. \
The map have an empty line at the middle.", game);
		}
		i++;
	}
}





#include <stdlib.h>
#include <unistd.h>
#include<stdio.h>
#include <fcntl.h>
#include "solong.h"

void ft_put_map(t_game *game)
{
    int i;

    for (i = 0; i < game->map.largeur; i++)
    {
        printf("%s\n", game->map.map[i]);
    }
}

int main(int argc, char **argv)
{
   t_game *game= malloc(sizeof(t_game));
	ft_check_command_line_arguments(argc, argv, game);
	ft_init_map(game, argv[1]);
	ft_init_vars(game);
	ft_check_map(game);;
    ft_check_path_to_exit(game);   
	ft_init_mlx(game);
	ft_init_sprites(game);
	ft_render_map(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, ft_handle_input, game);
	mlx_hook(game->win, DestroyNotify, \
	ButtonPressMask, ft_close_game, game);
	mlx_hook(game->win, Expose, ExposureMask, ft_render_map, game);
	mlx_loop(game->mlx);
	ft_free_all_allocated_memory(game);
    

    return EXIT_SUCCESS;
}
