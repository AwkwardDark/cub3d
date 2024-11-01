/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:39:44 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/30 23:07:57 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_color_dark(int color, double fact)
{
	return (((int)((color >> 16 & 0xFF) * fact) << 16) + \
	((int)((color >> 8 & 0xFF) * fact) << 8) + (int)((color & 0xFF) * fact));
}

int	ft_get_pixel_color(t_img *img, int x, int y)
{
	char	*color;

	color = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(int *)color);
}

int	ft_rgb_to_hex(int *rgb)
{
	if (rgb[0] < 0)
		rgb[0] = 0;
	if (rgb[0] > 255)
		rgb[0] = 255;
	if (rgb[1] < 0)
		rgb[1] = 0;
	if (rgb[1] > 255)
		rgb[1] = 255;
	if (rgb[2] < 0)
		rgb[2] = 0;
	if (rgb[2] > 255)
		rgb[2] = 255;
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}
