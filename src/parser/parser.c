/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:01:20 by pierre            #+#    #+#             */
/*   Updated: 2024/11/01 19:11:06 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// reads all the content of the file and stores it in a chained list 
static int	ft_file_to_list(t_file *file)
{
	char	*line;

	line = get_next_line(file->fd);
	if (!line)
		return (0);
	while (line)
	{
		ft_lstadd_back_b(&file->fd_list, ft_lstnew_b(ft_strdup(line),
				ft_strlen(line)));
		free(line);
		line = get_next_line(file->fd);
	}
	return (1);
}

/* 
	-checks the file name is not empty
	-checks the file name ends with ".cub"
*/
static int	ft_is_valid_file_name(char *filename)
{
	if (!filename || !*filename || *filename == '.')
		return (0);
	while (*filename != '.')
		filename++;
	if (ft_strcmp(filename, ".cub") != 0)
		return (0);
	return (1);
}

static void	ft_reset_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'R')
				map[i][j] = '0';
			if (map[i][j] == 'G')
				map[i][j] = 'X';
			if (map[i][j] == 'B')
				map[i][j] = 'D';
			j++;
		}
		i++;
	}
}

// general parsing function
void	ft_parser(int argc, char **argv, t_file *file, t_data *data)
{
	t_list	*temp;

	if (TEX_SIZE != 64 || DOOR_SIZE != 64 || SPRITE_SIZE != 32 \
		|| TILE_SIZE != 10)
		ft_free_all(data, "Texture size macros not compatible with .xmp", 1);
	if (WIDTH < 1000 || HEIGHT < 500)
		ft_free_all(data, "Window dimensions too small", 1);
	if (argc != 2 || !ft_is_valid_file_name(argv[1]))
		ft_free_all(data, "invalid filename", 1);
	file->fd = open(argv[1], O_RDONLY);
	if (file->fd < 0)
		ft_free_all(data, "failed to open the file !", 1);
	ft_file_to_list(file);
	close(file->fd);
	temp = ft_parse_header(file, file->fd_list, data);
	ft_parse_map(file, temp, data);
	ft_reset_map(file->map);
	ft_parse_sprites_doors(file, data);
}
