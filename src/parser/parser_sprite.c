/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:46:27 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/01 12:26:08 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_sprite_elem(t_data *data, int *e, int i, int j)
{
	data->elem[*e].pos.x = j + 0.5;
	data->elem[*e].pos.y = i + 0.5;
	data->elem[*e].type = SPRITE;
	data->elem[*e].status = OPEN;
	data->elem[*e].sprite_id = SPRITE_0;
	(*e)++;
}

static void	ft_init_door_elem(t_data *data, int *e, int i, int j)
{
	data->elem[*e].pos.x = j + 0.5;
	data->elem[*e].pos.y = i + 0.5;
	data->elem[*e].type = DOOR;
	data->elem[*e].status = CLOSE;
	data->elem[*e].door_id = DOOR_0;
	ft_bzero(&data->elem[*e].ray, sizeof(t_raycast));
	(*e)++;
}

static void	ft_count_sprites_doors(t_file *file, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (file->map[i])
	{
		j = 0;
		while (file->map[i][j])
		{
			if (file->map[i][j] == 'X' || file->map[i][j] == 'D')
				file->elem_count++;
			j++;
		}
		i++;
	}
	data->elem = ft_calloc(file->elem_count + 1, sizeof(t_elem));
	if (!data->elem)
		ft_free_all(data, "Malloc failed", 1);
}

void	ft_parse_sprites_doors(t_file *file, t_data *data)
{
	int	i;
	int	j;
	int	e;

	ft_count_sprites_doors(file, data);
	i = 0;
	e = 0;
	while (file->map[i])
	{
		j = 0;
		while (file->map[i][j])
		{
			if (file->map[i][j] == 'X')
				ft_init_sprite_elem(data, &e, i, j);
			if (file->map[i][j] == 'D')
				ft_init_door_elem(data, &e, i, j);
			j++;
		}
		i++;
	}
}
