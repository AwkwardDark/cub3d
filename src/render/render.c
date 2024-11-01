/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:55:53 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/31 16:54:08 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_render_map(t_data *data)
{	
	if (ft_sprite_in_map(data))
		ft_animate_sprite(data);
	if (ft_door_is_opening(data))
		ft_animate_open_door(data);
	if (ft_door_is_closing(data))
		ft_animate_close_door(data);
	if (data->p->jump)
		ft_animate_jump(data);
	mlx_destroy_image(data->mlx, data->img->img);
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp, \
		&data->img->line_len, &data->img->endian);
	ft_update_motion(data, data->p);
	ft_floor_raycast(data->floorcast, data->p, data);
	ft_ceiling_raycast(data->floorcast, data->p, data);
	ft_raycast(data->ray, data->p, data);
	ft_minimap(data);
	ft_draw_cursor(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
	ft_print_welcome_message(data);
	ft_print_door_message(data);
	return (0);
}
