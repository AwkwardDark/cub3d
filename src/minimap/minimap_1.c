/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:10:23 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/30 22:44:52 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_draw_blur_minimap(t_minimap *minimap, t_data *data)
{
	t_point	p;

	p.y = minimap->start.y;
	while (p.y < minimap->start.y + minimap->size)
	{
		p.x = minimap->start.x;
		while (p.x < minimap->start.x + minimap->size)
		{
			if (p.y > minimap->start.y && p.y < minimap->start.y + \
				minimap->size && p.x > minimap->start.x \
					&& p.x < minimap->start.x + minimap->size)
				ft_put_pixel_blurred(data->img, &p, WHITE);
			p.x++;
		}
		p.y++;
	}
}

static void	ft_draw_border(t_minimap *minimap, t_data *data)
{
	int	x;
	int	y;

	y = minimap->start.y - 5;
	while (y < minimap->start.y + minimap->size + 5)
	{
		x = minimap->start.x - 5;
		while (x < minimap->start.x + minimap->size + 5)
		{
			if (y < minimap->start.y || y > minimap->start.y + minimap->size \
				|| x < minimap->start.x || x > minimap->start.x + minimap->size)
				ft_mlx_pixel_put(data->img, x, y, WHITE);
			x++;
		}
		y++;
	}
}

static void	ft_draw_player(t_minimap *minimap, t_data *data)
{
	t_point	center;
	t_point	player_dir;
	int		radius;

	center.x = minimap->start.x + minimap->size / 2;
	center.y = minimap->start.y + minimap->size / 2;
	radius = TILE_SIZE / 2;
	ft_draw_circle(center, radius, RED, data);
	player_dir.x = center.x + 3 * TILE_SIZE * data->p->dir.x / 2;
	player_dir.y = center.y + 3 * TILE_SIZE * data->p->dir.y / 2;
	ft_bresenham(center, player_dir, data);
}

static void	ft_draw_minimap(t_minimap *minimap, t_data *data)
{
	t_point	r_c;
	int		x;
	int		y;
	int		y_row;
	int		x_column;

	y = ft_start_y(minimap, data);
	y_row = 0;
	while (y_row < ft_count_row(data->file->map))
	{
		x_column = 0;
		x = ft_start_x(minimap, data);
		while (x_column < ft_count_column(data->file->map[y_row]))
		{
			r_c.x = x_column;
			r_c.y = y_row;
			ft_choose_tile_color(data, x, y, r_c);
			x += TILE_SIZE;
			x_column++;
		}
		y += TILE_SIZE;
		y_row++;
	}
}

void	ft_minimap(t_data *data)
{
	ft_init_minimap(data);
	ft_draw_blur_minimap(data->minimap, data);
	ft_draw_player(data->minimap, data);
	ft_draw_minimap(data->minimap, data);
	ft_draw_border(data->minimap, data);
}
