/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:35:43 by pierre            #+#    #+#             */
/*   Updated: 2024/11/01 19:18:01 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_valid_door(int x, int y, char **map)
{
	if (!ft_is_valid_zero(x, y, map))
		return (0);
	else if (map[x - 1][y] == '1' && map[x + 1][y] == '1')
		return (1);
	else if (map[x][y - 1] == '1' && map[x][y + 1] == '1')
		return (1);
	else
		return (0);
}
