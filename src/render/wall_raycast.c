/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:56:31 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/30 21:58:09 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_rays(t_raycast *ray, t_player *p, int x)
{
	double	cam_x;

	cam_x = 2 * x / (double)WIDTH - 1;
	ray->dir.x = p->dir.x + p->plane.x * cam_x;
	ray->dir.y = p->dir.y + p->plane.y * cam_x;
	ray->map.x = (int)p->pos.x;
	ray->map.y = (int)p->pos.y;
	if (ray->dir.x != 0)
		ray->delta.x = fabs(1 / ray->dir.x);
	if (ray->dir.y != 0)
		ray->delta.y = fabs(1 / ray->dir.y);
}

void	ft_step(t_raycast *ray, t_player *p)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side.x = (p->pos.x - ray->map.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side.x = (ray->map.x + 1.0 - p->pos.x) * ray->delta.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side.y = (p->pos.y - ray->map.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side.y = (ray->map.y + 1.0 - p->pos.y) * ray->delta.y;
	}
}

void	ft_dda(t_raycast *ray, t_data *data)
{
	while (1)
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
		if (data->file->map[(int)ray->map.y][(int)ray->map.x] == '1')
			break ;
	}
}

void	ft_calculate_wall(t_raycast *ray, t_player *p)
{
	if (ray->side_col == 0)
		ray->wall_dist = (ray->map.x - p->pos.x + (1 - ray->step.x) / 2) \
			/ ray->dir.x;
	else
		ray->wall_dist = (ray->map.y - p->pos.y + (1 - ray->step.y) / 2) \
			/ ray->dir.y;
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

void	ft_calculate_text(t_data *data, t_texture *tex, t_raycast *ray, int x)
{
	int	y;

	ft_get_texture_orientation(tex, ray);
	tex->x = (int)(ray->wall_x * TEX_SIZE);
	if ((ray->side_col == 0 && ray->dir.x < 0) || \
		(ray->side_col == 1 && ray->dir.y > 0))
		tex->x = TEX_SIZE - tex->x - 1;
	tex->step = 1.0 * TEX_SIZE / ray->height;
	tex->pos = (ray->y_vertical.x - HEIGHT / 2 + data->p->pitch + \
		ray->height / 2) * tex->step;
	y = ray->y_vertical.x;
	while (y < ray->y_vertical.y)
	{
		tex->y = (int)tex->pos & (TEX_SIZE - 1);
		tex->pos += tex->step;
		ft_apply_texture_color(data, tex->orientation, x, y);
		y++;
	}
}
