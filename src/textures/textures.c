/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:12:17 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/01 12:35:39 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_xpm_to_door(t_data *data, t_texture *tex, char *path, int id)
{
	t_img	*img;
	int		door_size;

	door_size = DOOR_SIZE;
	img = mlx_xpm_file_to_image(data->mlx, path, &door_size, &door_size);
	if (!img)
		ft_free_all(data, "Texture not found", 1);
	tex->img[id].img = img;
	tex->img[id].addr = mlx_get_data_addr(img, &tex->img[id].bpp, \
		&tex->img[id].line_len, &tex->img[id].endian);
	if (!tex->img[id].addr)
		ft_free_all(data, MLX_ADDR, 1);
}

static void	ft_xpm_to_sprite(t_data *data, t_texture *tex, char *path, int id)
{
	t_img	*img;
	int		sprite_size;

	sprite_size = SPRITE_SIZE;
	img = mlx_xpm_file_to_image(data->mlx, path, &sprite_size, &sprite_size);
	if (!img)
		ft_free_all(data, "Texture not found", 1);
	tex->img[id].img = img;
	tex->img[id].addr = mlx_get_data_addr(img, &tex->img[id].bpp, \
		&tex->img[id].line_len, &tex->img[id].endian);
	if (!tex->img[id].addr)
		ft_free_all(data, MLX_ADDR, 1);
}

static void	ft_xpm_to_img(t_data *data, t_texture *tex, char *path, int id)
{
	void	*img;
	int		tex_size;

	tex_size = TEX_SIZE;
	img = mlx_xpm_file_to_image(data->mlx, path, &tex_size, &tex_size);
	if (!img)
		ft_free_all(data, "Texture not found", 1);
	tex->img[id].img = img;
	tex->img[id].addr = mlx_get_data_addr(img, &tex->img[id].bpp, \
		&tex->img[id].line_len, &tex->img[id].endian);
	if (!tex->img[id].addr)
		ft_free_all(data, MLX_ADDR, 1);
}

static void	ft_load_textures(t_data *data)
{
	ft_xpm_to_img(data, data->tex, data->file->no, NORTH);
	ft_xpm_to_img(data, data->tex, data->file->ea, EAST);
	ft_xpm_to_img(data, data->tex, data->file->so, SOUTH);
	ft_xpm_to_img(data, data->tex, data->file->we, WEST);
	ft_xpm_to_img(data, data->tex, "./textures/matrix.xpm", FLOOR);
	ft_xpm_to_img(data, data->tex, "./textures/matrix.xpm", CEILING);
	ft_xpm_to_sprite(data, data->tex, "./textures/sprite/0.xpm", SPRITE_0);
	ft_xpm_to_sprite(data, data->tex, "./textures/sprite/1.xpm", SPRITE_1);
	ft_xpm_to_sprite(data, data->tex, "./textures/sprite/2.xpm", SPRITE_2);
	ft_xpm_to_sprite(data, data->tex, "./textures/sprite/3.xpm", SPRITE_3);
	ft_xpm_to_sprite(data, data->tex, "./textures/sprite/4.xpm", SPRITE_4);
	ft_xpm_to_sprite(data, data->tex, "./textures/sprite/5.xpm", SPRITE_5);
	ft_xpm_to_sprite(data, data->tex, "./textures/sprite/6.xpm", SPRITE_6);
	ft_xpm_to_sprite(data, data->tex, "./textures/sprite/7.xpm", SPRITE_7);
	ft_xpm_to_sprite(data, data->tex, "./textures/sprite/8.xpm", SPRITE_8);
	ft_xpm_to_sprite(data, data->tex, "./textures/sprite/9.xpm", SPRITE_9);
	ft_xpm_to_door(data, data->tex, "./textures/door/0.xpm", DOOR_0);
	ft_xpm_to_door(data, data->tex, "./textures/door/1.xpm", DOOR_1);
	ft_xpm_to_door(data, data->tex, "./textures/door/2.xpm", DOOR_2);
	ft_xpm_to_door(data, data->tex, "./textures/door/3.xpm", DOOR_3);
	ft_xpm_to_door(data, data->tex, "./textures/door/4.xpm", DOOR_4);
	ft_xpm_to_door(data, data->tex, "./textures/door/5.xpm", DOOR_5);
	ft_xpm_to_door(data, data->tex, "./textures/door/6.xpm", DOOR_6);
	ft_xpm_to_door(data, data->tex, "./textures/door/7.xpm", DOOR_7);
}

void	ft_textures_init(t_data *data)
{
	t_texture	*tex;

	tex = malloc(sizeof(t_texture));
	if (!tex)
		ft_free_all(data, "Malloc failed", 1);
	ft_bzero(tex, sizeof(tex));
	data->tex = tex;
	tex->img = ft_calloc(sizeof(t_img), 24);
	if (!tex->img)
		ft_free_all(data, "Malloc failed", 1);
	ft_load_textures(data);
}
