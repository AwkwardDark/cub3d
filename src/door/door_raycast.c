/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:46:50 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/30 20:23:38 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_hit_door(t_data *data, int y, int x, int i)
{
	if (y > 0 && y < ft_count_row(data->file->map) && x > 0 && \
		x < ft_count_column(data->file->map[y]))
	{
		if (data->file->map[y][x] == 'D' && ft_select_door(data, y, x, i))
			return (1);
	}
	return (0);
}

static void	ft_apply_door_texture(t_data *data, t_elem *elem, int x, int y)
{
	int	color;

	elem->ray.dist_factor = 1.0 / (1.0 + pow(elem->ray.wall_dist, 2) * 0.008);
	color = ft_get_pixel_color(&data->tex->img[elem->door_id], \
		data->tex->x, data->tex->y);
	if (color > 0 && (color & 0x00FFFFFF) != 0)
		ft_mlx_pixel_put(data->img, x, y, ft_color_dark(color, \
			elem->ray.dist_factor));
}

void	ft_dda_door(t_raycast *ray, t_data *data, int i)
{
	int	j;

	j = 0;
	while (j < 200)
	{
		if (ray->side.x < ray->side.y)
		{
			ray->side.x += ray->delta.x;
			ray->map.x += ray->step.x;
			ray->side_col = 0;
		}
		else
		{
			ray->side.y += ray->delta.y;
			ray->map.y += ray->step.y;
			ray->side_col = 1;
		}
		if (ft_hit_door(data, (int)ray->map.y, (int)ray->map.x, i))
			break ;
		j++;
	}
}

void	ft_calculate_wall_door(t_raycast *ray, t_player *p)
{
	if (ray->side_col == 0)
		ray->wall_dist = (ray->map.x - p->pos.x + (1 - ray->step.x) / 2) \
			/ ray->dir.x + 0.5;
	else
		ray->wall_dist = (ray->map.y - p->pos.y + (1 - ray->step.y) / 2) \
			/ ray->dir.y + 0.5;
	ray->height = (int)(HEIGHT / ray->wall_dist);
	ray->y_vertical.x = -ray->height / 2 + HEIGHT / 2 - p->pitch;
	ray->y_vertical.y = ray->height + ray->y_vertical.x;
	if (ray->y_vertical.y >= HEIGHT)
		ray->y_vertical.y = HEIGHT - 1;
	if (ray->side_col == 0)
		ray->wall_x = p->pos.y + ray->wall_dist * ray->dir.y;
	else
		ray->wall_x = p->pos.x + ray->wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

void	ft_calc_door_text(t_data *data, t_raycast *ray, t_elem *elem, int x)
{
	int	y;

	data->tex->x = (int)(ray->wall_x * DOOR_SIZE);
	if ((ray->side_col == 0 && ray->dir.x < 0) || \
		(ray->side_col == 1 && ray->dir.y > 0))
		data->tex->x = DOOR_SIZE - data->tex->x - 1;
	data->tex->step = 1.0 * DOOR_SIZE / ray->height;
	data->tex->pos = (ray->y_vertical.x - HEIGHT / 2 + data->p->pitch + \
		ray->height / 2) * data->tex->step;
	y = ray->y_vertical.x;
	while (y < ray->y_vertical.y)
	{
		data->tex->y = (int)data->tex->pos & (DOOR_SIZE - 1);
		data->tex->pos += data->tex->step;
		if (ray->wall_dist < data->ray->dist_buffer_wall[x])
			ft_apply_door_texture(data, elem, x, y);
		y++;
	}
}
