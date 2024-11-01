/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:11:48 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/30 22:08:27 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_wall_collision(double x, double y, t_data *data)
{
	int	i;

	i = ft_find_nearest_door_index(data);
	if (data->file->map[(int)y][(int)x] == '1' || \
		(data->file->map[(int)y][(int)x] == 'D' && data->elem[i].status))
		return (1);
	return (0);
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = (y * img->line_len + x * (img->bpp / 8));
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
