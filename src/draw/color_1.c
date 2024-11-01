/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:16:35 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/30 21:05:50 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_blur_radius(int *count, t_point *p, t_rgb *total, t_img *img)
{
	int				i;
	int				j;
	t_point			new;
	unsigned int	color;

	i = -5;
	while (i <= 5)
	{
		j = -5;
		while (j <= 5)
		{
			new.x = p->x + i;
			new.y = p->y + j;
			if (new.x >= 0 && new.x < WIDTH && new.y >= 0 && new.y < HEIGHT)
			{
				color = ft_get_pixel_color(img, new.x, new.y);
				total->r += (color >> 16) & 0xFF;
				total->g += (color >> 8) & 0xFF;
				total->b += color & 0xFF;
				(*count)++;
			}
			j++;
		}
		i++;
	}
}

unsigned int	ft_blur(t_img *img, t_point *p)
{	
	t_rgb	total;
	t_rgb	avg;
	int		count;

	total.r = 0;
	total.g = 0;
	total.b = 0;
	count = 0;
	ft_blur_radius(&count, p, &total, img);
	avg.r = total.r / count;
	avg.g = total.g / count;
	avg.b = total.b / count;
	avg.rgb[0] = avg.r;
	avg.rgb[1] = avg.g;
	avg.rgb[2] = avg.b;
	return (ft_rgb_to_hex(avg.rgb));
}

void	ft_put_pixel_blurred(t_img *img, t_point *p, unsigned int color)
{
	unsigned int	bg_color;
	char			*color_def;
	t_rgb			front;
	t_rgb			back;
	t_rgb			blur;

	bg_color = ft_blur(img, p);
	front.r = (color >> 16) & 0xFF;
	front.g = (color >> 8) & 0xFF;
	front.b = color & 0xFF;
	back.r = (bg_color >> 16) & 0xFF;
	back.g = (bg_color >> 8) & 0xFF;
	back.b = bg_color & 0xFF;
	blur.r = (int)((1 - 0.1) * back.r + 0.1 * front.r);
	blur.g = (int)((1 - 0.1) * back.g + 0.1 * front.g);
	blur.b = (int)((1 - 0.1) * back.b + 0.1 * front.b);
	blur.rgb[0] = blur.r;
	blur.rgb[1] = blur.r;
	blur.rgb[2] = blur.b;
	color_def = img->addr + ((int)p->y * img->line_len + \
		(int)p->x * (img->bpp / 8));
	*(unsigned int *)color_def = ft_rgb_to_hex(blur.rgb);
}
