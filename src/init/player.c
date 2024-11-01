/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:23:50 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/01 12:24:15 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_set_direction_aux(t_player *p)
{
	if (p->direction == 'E')
	{
		p->dir.x = 1;
		p->dir.y = 0;
		p->plane.x = 0;
		p->plane.y = 0.66;
	}
	if (p->direction == 'W')
	{
		p->dir.x = -1;
		p->dir.y = 0;
		p->plane.x = 0;
		p->plane.y = -0.66;
	}
}

static void	ft_set_direction(t_player *p)
{
	if (p->direction == 'N')
	{
		p->dir.x = 0;
		p->dir.y = -1;
		p->plane.x = 0.66;
		p->plane.y = 0;
	}
	if (p->direction == 'S')
	{
		p->dir.x = 0;
		p->dir.y = 1;
		p->plane.x = -0.66;
		p->plane.y = 0;
	}
	ft_set_direction_aux(p);
}

void	ft_player_init(t_data *data)
{
	data->p->pos.x = data->file->start[1] + 0.5;
	data->p->pos.y = data->file->start[0] + 0.5;
	data->p->ceiling_col = ft_rgb_to_hex(data->file->crgb);
	data->p->floor_col = ft_rgb_to_hex(data->file->frgb);
	data->p->angle = 0.04;
	data->p->speed = 0.15;
	data->p->pitch = 0;
	data->p->move_down = 0;
	data->p->move_up = 0;
	data->p->move_left = 0;
	data->p->move_right = 0;
	data->p->rotate_left = 0;
	data->p->rotate_right = 0;
	data->p->rotate_down = 0;
	data->p->rotate_up = 0;
	data->p->open_door = 0;
	data->p->close_door = 0;
	data->p->speed_up = 0;
	data->p->jump = 0;
	data->p->welcome = 1;
	data->p->direction = data->file->orientation;
	data->p->mouse.x = WIDTH / 2;
	data->p->mouse.y = HEIGHT / 2;
	ft_set_direction(data->p);
}
