/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:55:52 by cnahle            #+#    #+#             */
/*   Updated: 2024/09/06 19:39:02 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1020
# endif

# include<stdlib.h>
# include<stddef.h>
# include<unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "mlx/mlx.h"

typedef struct s_map
{
	int		longueur;
	int		largeur;
	char	**map;
}		t_map;

typedef struct s_game {
	void	*mlx;
	void	*win;
	t_map	map;
	int		player;
	int		collectibles;
	int		moves;
	void	*textures[5];
}	t_game;

int		ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_join(char *dest, char *s1, char *s2);
char	*ft_readed_line(char *start);
char	*ft_move_start(char	*start);
char	*get_next_line(int fd);
t_map	create_map(char *file_path);

#endif
