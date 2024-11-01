/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:13:06 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/30 21:41:17 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_down(t_player *p, t_data *data)
{
	if (!ft_wall_collision(p->pos.x - p->dir.x * 0.3, p->pos.y, data))
		p->pos.x -= p->dir.x * p->speed;
	if (!ft_wall_collision(p->pos.x, p->pos.y - p->dir.y * 0.3, data))
		p->pos.y -= p->dir.y * p->speed;
}

void	ft_move_left(t_player *p, t_data *data)
{
	if (!ft_wall_collision(p->pos.x - p->plane.x * 0.3, p->pos.y, data))
		p->pos.x -= p->plane.x * p->speed;
	if (!ft_wall_collision(p->pos.x, p->pos.y - p->plane.y * 0.3, data))
		p->pos.y -= p->plane.y * p->speed;
}

void	ft_move_right(t_player *p, t_data *data)
{
	if (!ft_wall_collision(p->pos.x + p->plane.x * 0.3, p->pos.y, data))
		p->pos.x += p->plane.x * p->speed;
	if (!ft_wall_collision(p->pos.x, p->pos.y + p->plane.y * 0.3, data))
		p->pos.y += p->plane.y * p->speed;
}

void	ft_open_door(t_data *data)
{
	int	i;

	i = ft_find_nearest_door_index(data);
	if (i == -1)
		return ;
	if (data->elem[i].status == CLOSE && ft_is_near_door(data, i))
		data->elem[i].status = IS_OPENING;
}

void	ft_close_door(t_data *data)
{
	int	i;

	i = ft_find_nearest_door_index(data);
	if (i == -1)
		return ;
	if (data->elem[i].status == OPEN && ft_is_near_door(data, i) && \
		!ft_select_door(data, data->p->pos.y, data->p->pos.x, i))
		data->elem[i].status = IS_CLOSING;
}
