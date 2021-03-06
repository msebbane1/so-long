/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:38:41 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/27 14:22:46 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	key_player_lose(int keycode, t_conf *conf)
{
	int	pos_x;
	int	pos_y;

	pos_x = conf->player.pos_x;
	pos_y = conf->player.pos_y;
	if (keycode == D && conf->map.ptr[pos_y][pos_x + 1] == 'S')
		return (1);
	if (keycode == W && conf->map.ptr[pos_y - 1][pos_x] == 'S')
		return (1);
	if (keycode == A && conf->map.ptr[pos_y][pos_x - 1] == 'S')
		return (1);
	if (keycode == S && conf->map.ptr[pos_y + 1][pos_x] == 'S')
		return (1);
	return (0);
}

int	key_player_win(int keycode, t_conf *conf)
{
	int	pos_x;
	int	pos_y;

	pos_x = conf->player.pos_x;
	pos_y = conf->player.pos_y;
	if (keycode == D && conf->map.ptr[pos_y][pos_x + 1] == 'E')
		return (1);
	if (keycode == W && conf->map.ptr[pos_y - 1][pos_x] == 'E')
		return (1);
	if (keycode == A && conf->map.ptr[pos_y][pos_x - 1] == 'E')
		return (1);
	if (keycode == S && conf->map.ptr[pos_y + 1][pos_x] == 'E')
		return (1);
	return (0);
}

int	key_move_player(int keycode, t_conf *conf)
{
	int	pos_x;
	int	pos_y;

	pos_x = conf->player.pos_x;
	pos_y = conf->player.pos_y;
	if (keycode == ESCAPE)
		win_closed(conf);
	if (key_player_lose(keycode, conf))
		game_over(conf);
	else if (key_player_win(keycode, conf))
		end_game(conf);
	else if (keycode == D && (conf->map.ptr[pos_y][pos_x + 1] != '1')
		&& (conf->map.ptr[pos_y][pos_x + 1] != 'E'))
		key_right(conf);
	else if (keycode == W && conf->map.ptr[pos_y - 1][pos_x] != '1'
		&& conf->map.ptr[pos_y - 1][pos_x] != 'E')
		key_up(conf);
	else if (keycode == A && conf->map.ptr[pos_y][pos_x - 1] != '1'
		&& conf->map.ptr[pos_y][pos_x - 1] != 'E')
		key_left(conf);
	else if (keycode == S && conf->map.ptr[pos_y + 1][pos_x] != '1'
		&& conf->map.ptr[pos_y + 1][pos_x] != 'E')
		key_down(conf);
	return (0);
}
