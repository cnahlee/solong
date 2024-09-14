#include "solong.h"



int	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.largeur)
	{
		x = 0;
		while (x < game->map.longueur)
		{
			ft_identify_sprite(game, y, x);
			x++;
		}
		y++;
	}
	ft_print_movements(game);
	return (0);
}

void	ft_identify_sprite(t_game *game, int y, int x)
{	
	char	parameter;

	parameter = game->map.map[y][x];
	if (parameter == WALL)
		ft_render_sprite (game, game->wall, y, x);
	else if (parameter == FLOOR)
		ft_render_sprite (game, game->floor, y, x);
	else if (parameter == COINS)
		ft_render_sprite (game, game->coins, y, x);
	else if (parameter == MAP_EXIT)
	{
		if (game->map.coins == 0)
			ft_render_sprite (game, game->open_exit, y, x);
		else
			ft_render_sprite (game, game->exit_closed, y, x);
	}
	else if (parameter == PLAYER)
		ft_render_player (game, y, x);
}

void	ft_render_player(t_game *game, int y, int x)
{
	
		ft_render_sprite (game, game->player_front, y, x);
	
}

void	ft_render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window (game->mlx, game->win, \
	sprite.xpm_ptr, column * sprite.x, line * sprite.y);
}

void	ft_print_movements(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->movements);
	phrase = ft_strjoin("Movements : ", movements);
	mlx_string_put(game->mlx, game->win, 40, 20, 99999, phrase);
	free(movements);
	free(phrase);
}