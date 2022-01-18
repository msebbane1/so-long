/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:54:31 by msebbane          #+#    #+#             */
/*   Updated: 2021/12/21 10:17:10 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
}				t_vars;

typedef struct s_coord {
	int	x;
	int	y;
}	t_coord;

typedef struct s_item {
	t_coord	item_pos;
}	t_item;

typedef struct s_keys {
	int	north;
	int	south;
	int	east;
	int	west;
}	t_keys;

typedef struct s_tex
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
	char		*path;
}	t_tex;

typedef struct s_conf {
	char	**map;
	int		move_count;
	t_coord	*player_pos;
	//t_list	*item_list;
	//t_list	*exit_list;
	t_coord	screen_res;
	int		cube_size;
	void	*mlx;
	void	*win;
	t_data	img;
	t_keys	keys;
	t_tex	wall;
	t_tex	door;
	t_tex	item;
	t_tex	avatar;
}	t_conf;

#endif