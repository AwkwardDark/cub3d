/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:05:33 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/11/01 19:12:52 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_set_playerpos(t_file *file)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = file->map;
	while (tab && tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'N' || tab[i][j] == 'S' || tab[i][j] == 'E'
				|| tab[i][j] == 'W')
			{
				file->orientation = tab[i][j];
				file->start[0] = i;
				file->start[1] = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_valid_zero(int x, int y, char **map)
{
	if (y == 0 || x == 0)
		return (0);
	else if (map[x][y + 1] == ' ' || map[x][y + 1] == '\0'
		|| map[x][y + 1] == '\n')
		return (0);
	else if (map[x][y - 1] == ' ' || map[x][y - 1] == '\0'
		|| map[x][y - 1] == '\n')
		return (0);
	else if (map[x + 1][y] == ' ' || map[x + 1][y] == '\0'
		|| map[x + 1][y] == '\n')
		return (0);
	else if (map[x - 1][y] == ' ' || map[x - 1][y] == '\0'
		|| map[x - 1][y] == '\n')
		return (0);
	else
		return (1);
}

int	ft_map_flood_fill(char **tab, int x, int y, t_file *file)
{
	if (x < 0 || y < 0 || tab[x][y] == '1' || tab[x][y] == 'R' \
		|| tab[x][y] == 'X')
		return (1);
	else if ((tab[x][y] == '0' || tab[x][y] == 'N' || tab[x][y] == 'X'
		|| tab[x][y] == 'E' || tab[x][y] == 'W' || tab[x][y] == 'S')
		&& !ft_is_valid_zero(x, y, tab))
		return (printf("error at tab[%d][%d]: %c\n", x, y, tab[x][y]), 0);
	if (tab[x][y] == 'D' && !ft_is_valid_door(x, y, tab))
		return (printf("error at tab[%d][%d]: %c\n", x, y, tab[x][y]), 0);
	if (tab[x][y] == '0')
		tab[x][y] = 'R';
	if (tab[x][y] == 'X')
		tab[x][y] = 'G';
	if (tab[x][y] == 'D')
		tab[x][y] = 'B';
	return (ft_map_flood_fill(tab, x + 1, y, file)
		&& ft_map_flood_fill(tab, x - 1, y, file)
		&& ft_map_flood_fill(tab, x, y + 1, file)
		&& ft_map_flood_fill(tab, x, y - 1, file));
}

// Modified
int	ft_parse_map_aux(t_list *list, int len)
{
	char	*content;
	int		i;
	int		player;

	player = 0;
	while (len-- > 0)
	{
		i = 0;
		content = (char *)list->content;
		while (content[i])
		{
			if (content[i] == 'N' || content[i] == 'E'
				|| content[i] == 'S' || content[i] == 'W')
				player++;
			else if (content[i] != ' ' && content[i] != '0' && content[i] != '1'
				&& content[i] != '\n' && content[i] != '\0' && content[i] != 'X'
				&& content[i] != 'D')
				return (0);
			i++;
		}
		list = list->next;
	}
	if (player == 1)
		return (1);
	return (0);
}

void	ft_parse_map(t_file *file, t_list *list, t_data *data)
{
	int	len;

	len = ft_get_lstlen(list);
	if (!ft_end_of_map(list, len))
		ft_free_all(data, "Invalid content\ncharachters after map", 1);
	if (len == 0)
		ft_free_all(data, "Missing map !", 1);
	if (!ft_parse_map_aux(list, len))
		ft_free_all(data, INVALID_MAPCONTENT, 1);
	if (ft_save_map(len, file, list) != -1 || !ft_set_playerpos(file))
		ft_free_all(data, "UNEXPECTED ERROR", 1);
	if (ft_map_flood_fill(file->map, file->start[0], file->start[1], file))
		return ;
	else
		ft_free_all(data, INVALID_MAPSHAPE, 1);
}
