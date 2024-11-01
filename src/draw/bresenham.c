/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:23:40 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/16 17:14:03 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_aux_x(t_point *start, t_point *end, t_bresenham *b)
{
	int	temp;

	if (start->x > end->x)
	{
		temp = start->x;
		start->x = end->x;
		end->x = temp;
		temp = start->y;
		start->y = end->y;
		end->y = temp;
	}
	b->p_inc.y = -1;
	if (end->y >= start->y)
		b->p_inc.y = 1;
	b->p.y = start->y;
	b->p.x = start->x;
}

static void	ft_aux_y(t_point *start, t_point *end, t_bresenham *b)
{
	int	temp;

	if (start->y > end->y)
	{
		temp = start->x;
		start->x = end->x;
		end->x = temp;
		temp = start->y;
		start->y = end->y;
		end->y = temp;
	}
	b->p_inc.x = -1;
	if (end->x >= start->x)
		b->p_inc.x = 1;
	b->p.x = start->x;
	b->p.y = start->y;
}

static void	ft_draw_line_x(t_point *end, t_bresenham *b, t_data *data)
{
	int	d;

	d = 2 * b->delta.y - b->delta.x;
	while (b->p.x < end->x)
	{
		if (b->p.x >= 0 && b->p.x < WIDTH && b->p.y >= 0 && b->p.y < HEIGHT)
			ft_mlx_pixel_put(data->img, b->p.x, b->p.y, RED);
		if (d > 0)
		{
			b->p.y += b->p_inc.y;
			d -= 2 * b->delta.x;
		}
		d += 2 * b->delta.y;
		b->p.x++;
	}
}

static void	ft_draw_line_y(t_point *end, t_bresenham *b, t_data *data)
{
	int	d;

	d = 2 * b->delta.x - b->delta.y;
	while (b->p.y <= end->y)
	{
		if (b->p.x >= 0 && b->p.x < WIDTH && b->p.y >= 0 && b->p.y < HEIGHT)
			ft_mlx_pixel_put(data->img, b->p.x, b->p.y, RED);
		if (d > 0)
		{
			b->p.x += b->p_inc.x;
			d -= 2 * b->delta.y;
		}
		d += 2 * b->delta.x;
		b->p.y++;
	}
}

void	ft_bresenham(t_point start, t_point end, t_data *data)
{
	t_bresenham	bresenham;

	bresenham.delta.x = fabs(end.x - start.x);
	bresenham.delta.y = fabs(end.y - start.y);
	if (bresenham.delta.x > bresenham.delta.y)
	{
		ft_aux_x(&start, &end, &bresenham);
		ft_draw_line_x(&end, &bresenham, data);
	}
	else
	{
		ft_aux_y(&start, &end, &bresenham);
		ft_draw_line_y(&end, &bresenham, data);
	}
}
