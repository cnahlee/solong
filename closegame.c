#include "solong.h"



int	ft_victory(t_game *game)
{
    ft_free_all_allocated_memory(game);
	write(1,"you winnn",9);
	exit (EXIT_FAILURE);
}

int	ft_close_game(t_game *game)
{
	
	ft_free_all_allocated_memory(game);

	exit (EXIT_FAILURE);
}
