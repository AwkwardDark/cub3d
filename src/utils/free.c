/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:26:22 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/01 19:15:51 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_lst(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = lst;
	while (temp)
	{
		lst = temp;
		temp = lst->next;
		free(lst->content);
		free(lst);
	}
}

static void	ft_parser_free(t_file *file)
{
	if (file->fd_list)
		free_lst(file->fd_list);
	if (file->map)
		ft_clear_wordar(file->map);
	if (file->no)
		free(file->no);
	if (file->so)
		free(file->so);
	if (file->we)
		free(file->we);
	if (file->ea)
		free(file->ea);
	free(file);
}

void	ft_free_texture_img(t_data *data, t_texture *tex)
{
	int	i;

	i = 0;
	while (i < 24)
	{
		if (tex->img[i].img)
			mlx_destroy_image(data->mlx, tex->img[i].img);
		i++;
	}
	free(data->tex->img);
}

static void	ft_free_all_aux(t_data *data)
{
	if (data->elem)
		free(data->elem);
	if (data->minimap)
		free(data->minimap);
	if (data->mlx && data->img && data->img->img)
		mlx_destroy_image(data->mlx, data->img->img);
	if (data->mlx && data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->img)
		free(data->img);
}

void	ft_free_all(t_data *data, char *message, int code)
{
	if (data->file)
		ft_parser_free(data->file);
	if (data->ray)
		free(data->ray);
	if (data->p)
		free(data->p);
	if (data->spriteray)
		free(data->spriteray);
	if (data->floorcast)
		free(data->floorcast);
	if (data->tex)
	{
		if (data->tex->img)
			ft_free_texture_img(data, data->tex);
		free(data->tex);
	}
	ft_free_all_aux(data);
	if (data)
		free(data);
	if (message)
		printf("%s\n", message);
	exit(code);
}
