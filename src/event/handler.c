/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:12:22 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/31 15:42:11 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_update_motion(t_data *data, t_player *p)
{
	if (p->move_up)
		ft_move_up(p, data);
	if (p->move_down)
		ft_move_down(p, data);
	if (p->move_right)
		ft_move_right(p, data);
	if (p->move_left)
		ft_move_left(p, data);
	if (p->rotate_right)
		ft_rotate(p, p->angle);
	if (p->rotate_left)
		ft_rotate(p, -p->angle);
	if (p->rotate_up)
		ft_rotate_up(p);
	if (p->rotate_down)
		ft_rotate_down(p);
	if (p->open_door)
		ft_open_door(data);
	if (p->close_door)
		ft_close_door(data);
	if (p->speed_up)
		ft_speed_up(p);
}

static void	ft_key_press_aux(int keycode, t_player *p)
{
	if (keycode == XK_e)
		p->open_door = 1;
	else if (keycode == XK_q)
		p->close_door = 1;
	else if (keycode == XK_Shift_L)
		p->speed_up = 1;
	else if (keycode == XK_space)
		p->jump = 1;
	else if (keycode == 65293)
		p->welcome = 0;
}

int	ft_key_press(int keycode, t_data *data)
{
	t_player	*p;

	p = data->p;
	if (keycode == XK_Escape)
		ft_close(data);
	if (keycode == XK_w)
		p->move_up = 1;
	else if (keycode == XK_s)
		p->move_down = 1;
	else if (keycode == XK_d)
		p->move_right = 1;
	else if (keycode == XK_a)
		p->move_left = 1;
	else if (keycode == XK_Right)
		p->rotate_right = 1;
	else if (keycode == XK_Left)
		p->rotate_left = 1;
	else if (keycode == XK_Up)
		p->rotate_up = 1;
	else if (keycode == XK_Down)
		p->rotate_down = 1;
	else
		ft_key_press_aux(keycode, data->p);
	return (0);
}

static void	ft_key_release_aux(int keycode, t_player *p)
{
	if (keycode == XK_e)
		p->open_door = 0;
	else if (keycode == XK_q)
		p->close_door = 0;
	else if (keycode == XK_Shift_L)
	{
		p->speed = 0.15;
		p->speed_up = 0;
	}
}

int	ft_key_release(int keycode, t_data *data)
{
	t_player	*p;

	p = data->p;
	if (keycode == XK_w)
		p->move_up = 0;
	else if (keycode == XK_s)
		p->move_down = 0;
	else if (keycode == XK_d)
		p->move_right = 0;
	else if (keycode == XK_a)
		p->move_left = 0;
	else if (keycode == XK_Right)
		p->rotate_right = 0;
	else if (keycode == XK_Left)
		p->rotate_left = 0;
	else if (keycode == XK_Up)
		p->rotate_up = 0;
	else if (keycode == XK_Down)
		p->rotate_down = 0;
	else
		ft_key_release_aux(keycode, data->p);
	return (0);
}
