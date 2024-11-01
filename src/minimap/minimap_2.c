/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:40:44 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/30 22:51:51 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_minimap(t_data *data)
{
	t_minimap	*minimap;

	minimap = data->minimap;
	minimap->size = ft_min(WIDTH, HEIGHT) / 6;
	minimap->start.x = WIDTH / 50;
	minimap->start.y = 9 * HEIGHT / 12;
}

void	ft_draw_tile(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			if (x + j > data->minimap->start.x \
				&& x + j < data->minimap->start.x + data->minimap->size && \
					y + i > data->minimap->start.y && \
						y + i < data->minimap->start.y + data->minimap->size)
				ft_mlx_pixel_put(data->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_minimap_sprite(t_data *data, t_minimap *minimap, int x, int y)
{
	t_point	center;
	int		radius;

	center.x = x + TILE_SIZE / 2;
	center.y = y + TILE_SIZE / 2;
	radius = TILE_SIZE / 3;
	if (y > minimap->start.y && y < minimap->start.y + minimap->size && \
		x > minimap->start.x && x < minimap->start.x + minimap->size)
		ft_draw_circle(center, radius, BLUE, data);
}

void	ft_choose_tile_color(t_data *data, int x, int y, t_point r_c)
{
	int	x_column;	
	int	y_row;

	x_column = r_c.x;
	y_row = r_c.y;
	if (data->file->map[y_row][x_column] == '1')
		ft_draw_tile(data, x, y, BLACK);
	if (data->file->map[y_row][x_column] == 'X')
		ft_draw_minimap_sprite(data, data->minimap, x, y);
	if (data->file->map[y_row][x_column] == 'D' \
		&& ft_door_status(data, y_row, x_column) == CLOSE)
		ft_draw_tile(data, x, y, RED2);
	if (data->file->map[y_row][x_column] == 'D' \
		&& ft_door_status(data, y_row, x_column) == OPEN)
		ft_draw_tile(data, x, y, MENTHE);
	if (data->file->map[y_row][x_column] == 'D' \
		&& (ft_door_status(data, y_row, x_column) == IS_CLOSING \
			|| ft_door_status(data, y_row, x_column) == IS_OPENING))
		ft_draw_tile(data, x, y, ORANGE);
}
