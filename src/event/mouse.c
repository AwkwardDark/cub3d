/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:37:15 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/01 19:19:41 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_trap_mouse(int x, int y, t_data *data)
{
	if (x > WIDTH - 10)
	{
		x = 10;
		mlx_mouse_move(data->mlx, data->mlx_win, x, y);
	}
	if (x < 10)
	{
		x = WIDTH - 10;
		mlx_mouse_move(data->mlx, data->mlx_win, x, y);
	}
	if (y > HEIGHT - 10)
	{
		y = 10;
		mlx_mouse_move(data->mlx, data->mlx_win, x, y);
	}
	if (y < 10)
	{
		y = HEIGHT - 10;
		mlx_mouse_move(data->mlx, data->mlx_win, x, y);
	}
}

int	ft_mouse(int x, int y, t_data *data)
{
	t_player	*p;
	int			old_x;
	int			old_y;

	p = data->p;
	ft_trap_mouse(x, y, data);
	mlx_mouse_hide(data->mlx, data->mlx_win);
	old_x = p->mouse.x;
	if (x > old_x)
		ft_rotate(p, p->angle / 1.2);
	if (x < old_x)
		ft_rotate(p, -p->angle / 1.2);
	p->mouse.x = x;
	old_y = p->mouse.y;
	if (y > old_y)
		ft_rotate_down(p);
	if (y < old_y)
		ft_rotate_up(p);
	p->mouse.y = y;
	return (0);
}

int	ft_close(t_data *data)
{
	ft_free_all(data, NULL, 0);
	return (0);
}
