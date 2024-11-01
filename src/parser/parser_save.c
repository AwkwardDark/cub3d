/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:16:15 by pierre            #+#    #+#             */
/*   Updated: 2024/11/01 19:13:35 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_savetxture(char **info, t_file *file)
{
	if (!ft_strcmp(info[0], "NO"))
	{
		if (file->no)
			free(file->no);
		file->no = ft_strndup(info[1], ft_strlen(info[1]) - 1);
	}
	if (!ft_strcmp(info[0], "SO"))
	{
		if (file->so)
			free(file->so);
		file->so = ft_strndup(info[1], ft_strlen(info[1]) - 1);
	}
	if (!ft_strcmp(info[0], "WE"))
	{
		if (file->we)
			free(file->we);
		file->we = ft_strndup(info[1], ft_strlen(info[1]) - 1);
	}
	if (!ft_strcmp(info[0], "EA"))
	{
		if (file->ea)
			free(file->ea);
		file->ea = ft_strndup(info[1], ft_strlen(info[1]) - 1);
	}
}

static void	ft_parse_savecolaux(t_file *file, int color, int i, char **info)
{
	if (!ft_strcmp(info[0], "C"))
		file->crgb[i] = color;
	else
		file->frgb[i] = color;
}

int	ft_parse_savecolor(char **info, t_file *file)
{
	char	**rgb;
	int		i;
	int		j;

	if (ft_strcmp(info[0], "C") && ft_strcmp(info[0], "F"))
		return (ft_clear_wordar(info), 0);
	rgb = ft_split(info[1], ',');
	if (ft_tablen(rgb) != 3)
		return (ft_clear_wordar(rgb), ft_clear_wordar(info), 0);
	i = -1;
	while (rgb[++i])
	{
		j = -1;
		while (rgb[i][++j] && (i != 2 && rgb[i][j] != '\n'))
		{
			if (!ft_isalnum(rgb[i][j]))
				return (ft_clear_wordar(rgb), ft_clear_wordar(info), 0);
		}
		if (ft_atoi(rgb[i]) > 255)
			return (ft_clear_wordar(rgb), ft_clear_wordar(info), 0);
		ft_parse_savecolaux(file, ft_atoi(rgb[i]), i, info);
	}
	ft_clear_wordar(rgb);
	return (1);
}
