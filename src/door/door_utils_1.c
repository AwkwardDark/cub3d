/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:29:50 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/30 20:24:53 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_door_is_opening(t_data *data)
{
	int	i;

	i = ft_find_nearest_door_index(data);
	if (i == -1)
		return (0);
	if (data->elem[i].status == IS_OPENING)
		return (1);
	return (0);
}

int	ft_door_is_closing(t_data *data)
{
	int	i;

	i = ft_find_nearest_door_index(data);
	if (i == -1)
		return (0);
	if (data->elem[i].status == IS_CLOSING)
		return (1);
	return (0);
}

int	ft_find_nearest_door_index(t_data *data)
{
	int	i;

	i = data->file->elem_count - 1;
	while (i >= 0)
	{
		if (data->elem[i].type == DOOR)
			return (i);
		i--;
	}
	return (-1);
}

int	ft_is_near_door(t_data *data, int i)
{
	if (data->elem[i].dist <= 9)
		return (1);
	return (0);
}

int	ft_door_status(t_data *data, int y, int x)
{
	int	i;

	i = data->file->elem_count - 1;
	while (i >= 0)
	{
		if (((int)data->elem[i].pos.x == x) && ((int)data->elem[i].pos.y == y))
			return (data->elem[i].status);
		i--;
	}
	return (0);
}
