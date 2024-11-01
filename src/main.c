/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:57:19 by pierre            #+#    #+#             */
/*   Updated: 2024/11/01 19:08:08 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (printf(INPUT_ERROR), 1);
	data = ft_init_data();
	ft_parser(argc, argv, data->file, data);
	ft_player_init(data);
	ft_mlx_init(data);
	ft_textures_init(data);
	mlx_loop_hook(data->mlx, ft_render_map, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, ft_key_press, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, ft_key_release, data);
	mlx_hook(data->mlx_win, MotionNotify, PointerMotionMask, ft_mouse, data);
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, ft_close, data);
	mlx_loop(data->mlx);
	return (0);
}
