/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_save_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:31:15 by pierre            #+#    #+#             */
/*   Updated: 2024/11/01 19:18:35 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// the (char **) will contain an array of a size 
int	ft_save_map(int len, t_file *file, t_list *list)
{
	int	i;

	file->map = (char **)malloc(sizeof(char *) * (len + 1));
	file->map[len] = NULL;
	i = 0;
	while (i < len)
	{
		file->map[i] = (char *)malloc(sizeof(char)
				* (ft_strlen((char *)list->content) + 1));
		if (!file->map[i])
			return (i);
		ft_strcpy(file->map[i], (char *)list->content);
		list = list->next;
		i++;
	}
	return (-1);
}
