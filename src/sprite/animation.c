/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:04:46 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/31 16:47:37 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_animate_sprite_aux(t_data *data, int *fps)
{
	if (*fps < 63)
		data->elem->sprite_id = SPRITE_7;
	else if (*fps < 66)
		data->elem->sprite_id = SPRITE_8;
	else if (*fps < 106)
		data->elem->sprite_id = SPRITE_9;
	else if (*fps < 109)
		data->elem->sprite_id = SPRITE_8;
	else if (*fps < 112)
		data->elem->sprite_id = SPRITE_7;
	else if (*fps < 115)
		data->elem->sprite_id = SPRITE_6;
	else if (*fps < 118)
		data->elem->sprite_id = SPRITE_5;
	else if (*fps < 121)
		data->elem->sprite_id = SPRITE_4;
	else if (*fps < 124)
		data->elem->sprite_id = SPRITE_3;
	else if (*fps < 127)
		data->elem->sprite_id = SPRITE_2;
	else if (*fps < 130)
		data->elem->sprite_id = SPRITE_1;
	else
		*fps = 0;
}

void	ft_animate_sprite(t_data *data)
{
	static int	fps = 0;

	if (fps < 40)
		data->elem->sprite_id = SPRITE_0;
	else if (fps < 43)
		data->elem->sprite_id = SPRITE_1;
	else if (fps < 46)
		data->elem->sprite_id = SPRITE_2;
	else if (fps < 49)
		data->elem->sprite_id = SPRITE_3;
	else if (fps < 52)
		data->elem->sprite_id = SPRITE_4;
	else if (fps < 55)
		data->elem->sprite_id = SPRITE_5;
	else if (fps < 58)
		data->elem->sprite_id = SPRITE_6;
	else
		ft_animate_sprite_aux(data, &fps);
	fps++;
}

void	ft_animate_open_door(t_data *data)
{
	static int	fps = 0;
	int			i;

	i = ft_find_nearest_door_index(data);
	if (fps < 3)
		data->elem[i].door_id = DOOR_0;
	else if (fps < 6)
		data->elem[i].door_id = DOOR_1;
	else if (fps < 9)
		data->elem[i].door_id = DOOR_2;
	else if (fps < 12)
		data->elem[i].door_id = DOOR_3;
	else if (fps < 15)
		data->elem[i].door_id = DOOR_4;
	else if (fps < 18)
		data->elem[i].door_id = DOOR_5;
	else if (fps < 21)
		data->elem[i].door_id = DOOR_6;
	else
	{
		data->elem[i].door_id = DOOR_7;
		data->elem[i].status = OPEN;
		fps = 0;
	}
	fps++;
}

void	ft_animate_close_door(t_data *data)
{
	static int	fps = 0;
	int			i;

	i = ft_find_nearest_door_index(data);
	if (fps < 3)
		data->elem[i].door_id = DOOR_7;
	else if (fps < 6)
		data->elem[i].door_id = DOOR_6;
	else if (fps < 9)
		data->elem[i].door_id = DOOR_5;
	else if (fps < 12)
		data->elem[i].door_id = DOOR_4;
	else if (fps < 15)
		data->elem[i].door_id = DOOR_3;
	else if (fps < 18)
		data->elem[i].door_id = DOOR_2;
	else if (fps < 21)
		data->elem[i].door_id = DOOR_1;
	else
	{
		data->elem[i].door_id = DOOR_0;
		data->elem[i].status = CLOSE;
		fps = 0;
	}
	fps++;
}

void	ft_animate_jump(t_data *data)
{
	static int	fps = 0;

	if (fps < 5)
		data->p->pitch -= 15;
	else if (fps < 10)
		data->p->pitch -= 4;
	else if (fps < 15)
		data->p->pitch += 4;
	else if (fps < 20)
		data->p->pitch += 15;
	else
	{
		data->p->jump = 0;
		fps = 0;
	}
	fps++;
}
