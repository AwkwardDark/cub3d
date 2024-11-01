/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:37:26 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/30 22:24:21 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_apply_tex(t_data *data, int id, int x, int y)
{
	int	color;

	data->ray->dist_factor = 1.0 / (1.0 + \
		pow(data->floorcast->row_dist, 2) * 0.04);
	color = ft_get_pixel_color(&data->tex->img[id], data->tex->x, data->tex->y);
	if (color > 0)
		ft_mlx_pixel_put(data->img, x, y, \
			ft_color_dark(color, data->ray->dist_factor));
}

static void	ft_init_step_dda(t_floorcast *ray, t_player *p, int y)
{
	ray->dir0.x = p->dir.x - p->plane.x;
	ray->dir0.y = p->dir.y - p->plane.y;
	ray->dir1.x = p->dir.x + p->plane.x;
	ray->dir1.y = p->dir.y + p->plane.y;
	ray->pos = y - HEIGHT / 2;
	ray->pos_z = HEIGHT * 0.5;
	ray->row_dist = ray->pos_z / ray->pos;
	ray->step.x = ray->row_dist * (ray->dir1.x - ray->dir0.x) / WIDTH;
	ray->step.y = ray->row_dist * (ray->dir1.y - ray->dir0.y) / WIDTH;
	ray->floor.x = p->pos.x + ray->row_dist * ray->dir0.x;
	ray->floor.y = p->pos.y + ray->row_dist * ray->dir0.y;
}

void	ft_ceiling_raycast(t_floorcast *ray, t_player *p, t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < HEIGHT - data->p->pitch)
	{
		ft_init_step_dda(ray, p, y);
		x = 0;
		while (x < WIDTH)
		{
			ray->cell_x = (int)ray->floor.x;
			ray->cell_y = (int)ray->floor.y;
			data->tex->x = (int)(TEX_SIZE * (ray->floor.x - ray->cell_x)) \
				& (TEX_SIZE - 1);
			data->tex->y = (int)(TEX_SIZE * (ray->floor.y - ray->cell_y)) \
				& (TEX_SIZE - 1);
			ray->floor.x += ray->step.x;
			ray->floor.y += ray->step.y;
			if (y > HEIGHT / 2)
				ft_apply_tex(data, CEILING, x, HEIGHT - data->p->pitch - y - 1);
			x++;
		}
		y++;
	}
}

void	ft_floor_raycast(t_floorcast *ray, t_player *p, t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < HEIGHT + data->p->pitch)
	{
		ft_init_step_dda(ray, p, y);
		x = 0;
		while (x < WIDTH)
		{
			ray->cell_x = (int)ray->floor.x;
			ray->cell_y = (int)ray->floor.y;
			data->tex->x = (int)(TEX_SIZE * (ray->floor.x - ray->cell_x)) \
				& (TEX_SIZE - 1);
			data->tex->y = (int)(TEX_SIZE * (ray->floor.y - ray->cell_y)) \
				& (TEX_SIZE - 1);
			ray->floor.x += ray->step.x;
			ray->floor.y += ray->step.y;
			if (y > HEIGHT / 2)
				ft_apply_tex(data, FLOOR, x, y - data->p->pitch);
			x++;
		}
		y++;
	}
}
