/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:33:41 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/11/01 19:17:11 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_null_data(t_data *data)
{
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->tex = NULL;
	data->img = NULL;
	data->file = NULL;
	data->p = NULL;
	data->ray = NULL;
	data->spriteray = NULL;
	data->floorcast = NULL;
	data->elem = NULL;
	data->minimap = NULL;
}

static void	ft_init_data_aux(t_data *data)
{
	t_player	*p;
	t_spriteray	*spriteray;
	t_minimap	*minimap;
	t_floorcast	*floorcast;

	p = (t_player *)malloc(sizeof(t_player));
	if (!p)
		ft_free_all(data, "Malloc failed", 1);
	ft_bzero(p, sizeof(p));
	data->p = p;
	spriteray = (t_spriteray *)malloc(sizeof(t_spriteray));
	if (!spriteray)
		ft_free_all(data, "Malloc failed", 1);
	ft_bzero(spriteray, sizeof(spriteray));
	data->spriteray = spriteray;
	minimap = (t_minimap *)malloc(sizeof(t_minimap));
	if (!minimap)
		ft_free_all(data, "Malloc failed", 1);
	ft_bzero(minimap, sizeof(minimap));
	data->minimap = minimap;
	floorcast = (t_floorcast *)malloc(sizeof(t_floorcast));
	if (!floorcast)
		ft_free_all(data, "Malloc failed", 1);
	ft_bzero(floorcast, sizeof(floorcast));
	data->floorcast = floorcast;
}

t_data	*ft_init_data(void)
{
	t_data		*data;
	t_raycast	*ray;
	t_img		*img;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_free_all(data, "Malloc failed", 1);
	ft_null_data(data);
	data->file = ft_init_file(data);
	ray = (t_raycast *)malloc(sizeof(t_raycast));
	if (!ray)
		ft_free_all(data, "Malloc failed", 1);
	ft_bzero(ray, sizeof(ray));
	data->ray = ray;
	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		ft_free_all(data, "Malloc failed", 1);
	ft_bzero(img, sizeof(img));
	data->img = img;
	ft_init_data_aux(data);
	return (data);
}

t_file	*ft_init_file(t_data *data)
{
	t_file	*file;

	file = (struct s_file *)malloc(sizeof(struct s_file));
	if (!file)
		ft_free_all(data, "Malloc failed", 1);
	file->fd_list = NULL;
	file->ea = NULL;
	file->no = NULL;
	file->so = NULL;
	file->we = NULL;
	file->map = NULL;
	file->start[0] = -1;
	file->start[1] = -1;
	file->crgb[0] = -1;
	file->crgb[1] = -1;
	file->crgb[2] = -1;
	file->frgb[0] = -1;
	file->frgb[1] = -1;
	file->frgb[2] = -1;
	file->elem_count = 0;
	return (file);
}
