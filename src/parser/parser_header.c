/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:49:22 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/11/01 19:14:02 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	saves in the structure the data texture then the color
	and returns NULL if it incounters any problem
*/
static t_list	*ft_txture_color(t_file *file, t_list *list)
{
	list = ft_save_texture(list, file);
	if (!list)
		return (0);
	if (!ft_isemptyline((char *)list->content))
		return (NULL);
	while (list && ft_isemptyline((char *)list->content))
		list = list->next;
	if (!list)
		return (0);
	list = ft_save_color(list, file);
	if (!list)
		return (0);
	if (!ft_isemptyline((char *)list->content))
		return (NULL);
	return (list);
}

/*
	saves in the structure the data color then the texture
	and returns NULL if it incounters any problem
*/
static t_list	*ft_color_txture(t_file *file, t_list *list)
{
	list = ft_save_color(list, file);
	if (!list)
		return (0);
	if (!ft_isemptyline((char *)list->content))
		return (NULL);
	while (list && ft_isemptyline((char *)list->content))
		list = list->next;
	if (!list)
		return (0);
	list = ft_save_texture(list, file);
	if (!list)
		return (0);
	if (!ft_isemptyline((char *)list->content))
		return (NULL);
	return (list);
}

/* 
	checks what is the first type of element found if it 
	does match texture or color it return NULL
*/
static t_list	*ft_parse_texture_color(t_file *file, t_list *list)
{
	if (ft_istexture((char *)list->content))
		return (ft_txture_color(file, list));
	else if (ft_iscolor((char *)list->content))
		return (ft_color_txture(file, list));
	return (NULL);
}

int	ft_no_duplicate(t_file *file)
{
	if (file->ea == NULL || file->we == NULL || file->so == NULL
		|| file->no == NULL || file->crgb[0] == -1 || file->frgb[0] == -1)
		return (0);
	return (1);
}

//TODO add check that there is at least white 
// space after the first two blocks
t_list	*ft_parse_header(t_file *file, t_list *list, t_data *data)
{
	if (!list)
		ft_free_all(data, "Empty file !", 1);
	while (list && ft_isemptyline((char *)list->content))
		list = list->next;
	if (!list)
		ft_free_all(data, "Invalid format !", 1);
	list = ft_parse_texture_color(file, list);
	if (!list || !ft_no_duplicate(file))
		ft_free_all(data, "Invalid format !", 1);
	while (list && ft_isemptyline((char *)list->content))
		list = list->next;
	if (!list)
		ft_free_all(data, "Missing map", 1);
	return (list);
}
