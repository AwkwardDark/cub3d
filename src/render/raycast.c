/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:34:57 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/30 23:20:15 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_raycast_sprite_door(t_data *data)
{
	int	x;
	int	i;

	i = -1;
	while (++i < data->file->elem_count)
	{
		if (data->elem[i].type == SPRITE)
		{
			ft_transform_sprite(data, i);
			ft_calc_width_height(data);
			ft_draw_sprites(data, i);
		}
		if (data->elem[i].type == DOOR)
		{
			x = -1;
			while (++x < WIDTH)
			{
				ft_init_rays(&data->elem[i].ray, data->p, x);
				ft_step(&data->elem[i].ray, data->p);
				ft_dda_door(&data->elem[i].ray, data, i);
				ft_calculate_wall_door(&data->elem[i].ray, data->p);
				ft_calc_door_text(data, &data->elem[i].ray, &data->elem[i], x);
			}
		}
	}
}

void	ft_raycast(t_raycast *ray, t_player *p, t_data *data)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		ft_init_rays(ray, p, x);
		ft_step(ray, p);
		ft_dda(ray, data);
		ft_calculate_wall(ray, p);
		ft_calculate_text(data, data->tex, data->ray, x);
		ray->dist_buffer_wall[x] = ray->wall_dist;
		x++;
	}
	ft_sort_elem_by_dist(data);
	ft_raycast_sprite_door(data);
}

void	ft_get_texture_orientation(t_texture *tex, t_raycast *ray)
{
	if (ray->side_col == 0)
	{
		if (ray->dir.x < 0)
			tex->orientation = WEST;
		else
			tex->orientation = EAST;
	}
	else
	{
		if (ray->dir.y > 0)
			tex->orientation = SOUTH;
		else
			tex->orientation = NORTH;
	}
}

void	ft_apply_texture_color(t_data *data, int id, int x, int y)
{
	int	color;

	data->ray->dist_factor = 1.0 / (1.0 + pow(data->ray->wall_dist, 2) * 0.008);
	color = ft_get_pixel_color(&data->tex->img[id], data->tex->x, data->tex->y);
	if (color >= 0)
		ft_mlx_pixel_put(data->img, x, y, \
			ft_color_dark(color, data->ray->dist_factor));
}
