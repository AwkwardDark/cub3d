/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:24:10 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/30 22:57:54 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_sprite_in_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->file->elem_count)
	{
		if (data->elem[i].type == SPRITE)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_calc_elem_dist(t_data *data, t_player *p)
{
	int	i;

	i = 0;
	while (i < data->file->elem_count)
	{
		data->elem[i].dist = pow(p->pos.x - data->elem[i].pos.x, 2) + \
			pow(p->pos.y - data->elem[i].pos.y, 2);
		i++;
	}
}

void	ft_sort_elem_by_dist(t_data *data)
{
	int			i;
	int			j;
	t_elem		tmp;

	ft_calc_elem_dist(data, data->p);
	i = 0;
	while (i < data->file->elem_count)
	{
		j = 0;
		while (j < data->file->elem_count - 1)
		{
			if (data->elem[j].dist < data->elem[j + 1].dist)
			{
				tmp = data->elem[j];
				data->elem[j] = data->elem[j + 1];
				data->elem[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
