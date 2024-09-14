/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:13:26 by cnahle            #+#    #+#             */
/*   Updated: 2024/09/14 19:12:09 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1020
# endif

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
#include <X11/X.h>
#include <X11/keysym.h>

# include "mlx/mlx.h"


# include "libft.h"

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364

# define KEY_Q				113
# define KEY_ESC  			65307

# define FRONT				1
# define LEFT				2
# define RIGHT				3
# define BACK				4

typedef struct s_position
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	int		longueur;
	int		largeur;
	char	**map;
	int		coins;
	int		exit;
	int		players;
	t_pos	player;
}	t_map;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	int		movements;
	int		player_sprite;
	t_bool	map_alloc;
	int		moves;
	t_image	wall;
	t_image	floor;
	t_image	coins;
	t_image	open_exit;
	t_image	exit_closed;
	t_image	player_front;
}	t_game;

t_map	create_map(const char *file_path);
int		ft_error_msg(char *message, t_game *game);
void	ft_free_all_allocated_memory(t_game *game);
void	ft_destroy_images(t_game *game);
void	ft_free_map(t_game *game);
char	*ft_strappend(char **s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	**ft_split(const char *str, char charset);
void	ft_check_map(t_game *game);
void	ft_check_rows(t_game *game);
void	ft_check_columns(t_game *game);
void	ft_count_map_parameters(t_game *game);
void	ft_verify_map_parameters(t_game *game);
void	ft_check_command_line_arguments(int argc, char **argv, t_game *game);
void	ft_init_map(t_game *game,char *argv);
void	ft_check_for_empty_line(char *map, t_game *game);
char	*get_next_line(int fd);
void	ft_init_vars(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);
t_image	ft_new_sprite(void *mlx, char *path, t_game *game);
int		ft_render_map(t_game *game);
void	ft_identify_sprite(t_game *game, int x, int y);
void	ft_render_player(t_game *game, int x, int y);
void	ft_render_sprite(t_game *game, t_image sprite, int column, int line);
void	ft_print_movements(t_game *game);
int		ft_handle_input(int keysym, t_game *game);
void	ft_player_move(t_game *game, int x, int y, int player_sprite);
int	ft_victory(t_game *game);
int	ft_close_game(t_game *game);
int	ft_error_msg(char *message, t_game *game);

#endif