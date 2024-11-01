/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:51:58 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/30 22:55:05 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_count_column(char *map)
{
	return (ft_strlen(map));
}

int	ft_count_row(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_start_y(t_minimap *minimap, t_data *data)
{
	return (minimap->start.y + minimap->size / 2 - \
		data->p->pos.y * TILE_SIZE + 2);
}

int	ft_start_x(t_minimap *minimap, t_data *data)
{
	return (minimap->start.x + minimap->size / 2 - \
		data->p->pos.x * TILE_SIZE + 2);
}
