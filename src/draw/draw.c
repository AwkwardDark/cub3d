/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:32:03 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/01 19:09:29 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_draw_cursor_x(t_data *data)
{
	t_point	x_line;
	int		i;

	x_line.x = WIDTH / 2 - 4;
	x_line.y = HEIGHT / 2 - 10;
	i = x_line.x;
	while (i <= x_line.x + 8)
	{
		ft_mlx_pixel_put(data->img, i, x_line.y, WHITE);
		i++;
	}
	x_line.x = WIDTH / 2 - 4;
	x_line.y = HEIGHT / 2 + 10;
	i = x_line.x;
	while (i <= x_line.x + 8)
	{
		ft_mlx_pixel_put(data->img, i, x_line.y, WHITE);
		i++;
	}
}

static void	ft_draw_cursor_y(t_data *data)
{
	t_point	y_line;
	int		i;

	y_line.x = WIDTH / 2 - 10;
	y_line.y = HEIGHT / 2 - 4;
	i = y_line.y;
	while (i <= y_line.y + 8)
	{
		ft_mlx_pixel_put(data->img, y_line.x, i, WHITE);
		i++;
	}
	y_line.x = WIDTH / 2 + 10;
	y_line.y = HEIGHT / 2 - 4;
	i = y_line.y;
	while (i <= y_line.y + 8)
	{
		ft_mlx_pixel_put(data->img, y_line.x, i, WHITE);
		i++;
	}
}

void	ft_draw_cursor(t_data *data)
{
	t_point	center;

	center.x = WIDTH / 2;
	center.y = HEIGHT / 2;
	ft_draw_circle(center, 1, WHITE, data);
	ft_draw_cursor_x(data);
	ft_draw_cursor_y(data);
}

void	ft_draw_circle(t_point center, int radius, int color, t_data *data)
{
	int	x;
	int	y;

	x = center.x - radius;
	while (x <= center.x + radius)
	{
		y = center.y - radius;
		while (y <= center.y + radius)
		{
			if (pow(x - center.x, 2) + pow(y - center.y, 2) <= pow(radius, 2))
				ft_mlx_pixel_put(data->img, x, y, color);
			y++;
		}
		x++;
	}
}

// void	ft_ground(t_data *data)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (y <= HEIGHT / 2 - data->p->pitch)
// 	{
// 		x = 0;
// 		while (x <= WIDTH)
// 		{
// 			ft_mlx_pixel_put(data->img, x, y, data->p->ceiling_col);
// 			x++;
// 		}
// 		y++;
// 	}
// 	while (y < HEIGHT)
// 	{
// 		x = 0;
// 		while (x <= WIDTH)
// 		{
// 			ft_mlx_pixel_put(data->img, x, y, data->p->floor_col);
// 			x++;
// 		}
// 		y++;
// 	}
// }