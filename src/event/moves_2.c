/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:41:26 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/30 21:41:34 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_speed_up(t_player *p)
{
	p->speed = 0.3;
}

void	ft_rotate_up(t_player *p)
{
	if (p->pitch > -2800)
		p->pitch -= 20;
}

void	ft_rotate_down(t_player *p)
{
	if (p->pitch < 2800)
		p->pitch += 20;
}

void	ft_rotate(t_player *p, double angle)
{
	double	tmp_x;

	tmp_x = p->dir.x;
	p->dir.x = p->dir.x * cos(angle) - p->dir.y * sin(angle);
	p->dir.y = tmp_x * sin(angle) + p->dir.y * cos(angle);
	tmp_x = p->plane.x;
	p->plane.x = p->plane.x * cos(angle) - p->plane.y * sin(angle);
	p->plane.y = tmp_x * sin(angle) + p->plane.y * cos(angle);
}

void	ft_move_up(t_player *p, t_data *data)
{
	if (!ft_wall_collision(p->pos.x + p->dir.x * 0.3, p->pos.y, data))
		p->pos.x += p->dir.x * p->speed;
	if (!ft_wall_collision(p->pos.x, p->pos.y + p->dir.y * 0.3, data))
		p->pos.y += p->dir.y * p->speed;
}
