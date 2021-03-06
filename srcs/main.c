/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:38:43 by msebbane          #+#    #+#             */
/*   Updated: 2022/02/01 10:44:57 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_conf	conf;

	if (argc > 2)
		error_msg("Error\nToo many arguments");
	else if (argc < 2)
		error_msg("Error\nMissing a file");
	else if (ft_strncmp(".ber", argv[1] + ft_strlen(argv[1]) - 4, 4))
		error_msg("Error\nMissing a file (.ber)");
	read_x_y(argv, &conf);
	ft_read_map(argv, &conf);
	ft_check_map(&conf);
	count_collectible(&conf);
	game_init(&conf);
	conf.player.counter = 0;
	player_coord(&conf);
	mlx_hook(conf.win, 2, 1L << 0, key_hook, &conf);
	mlx_hook(conf.win, 17, 1L << 0, win_closed, &conf);
	mlx_loop(conf.mlx);
}
