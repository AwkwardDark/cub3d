/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:23:58 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/01 12:25:46 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*Dimensions*/
# define WIDTH		 1920
# define HEIGHT 	 1015
# define TEX_SIZE	 64
# define DOOR_SIZE   64
# define SPRITE_SIZE 32
# define TILE_SIZE	 10

typedef struct s_data	t_data;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef enum e_dir
{
	NORTH=0,
	EAST=1,
	SOUTH=2,
	WEST=3,
	FLOOR=4,
	CEILING=5,
	SPRITE_0=6,
	SPRITE_1=7,
	SPRITE_2=8,
	SPRITE_3=9,
	SPRITE_4=10,
	SPRITE_5=11,
	SPRITE_6=12,
	SPRITE_7=13,
	SPRITE_8=14,
	SPRITE_9=15,
	DOOR_0=16,
	DOOR_1=17,
	DOOR_2=18,
	DOOR_3=19,
	DOOR_4=20,
	DOOR_5=21,
	DOOR_6=22,
	DOOR_7=23,
}	t_dir;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	rgb[3];
}	t_rgb;

typedef struct s_bresenham
{
	struct s_point	delta;
	struct s_point	p;
	struct s_point	p_inc;
}	t_bresenham;

typedef struct s_floorcast
{
	struct s_point	dir0;
	struct s_point	dir1;
	struct s_point	step;
	struct s_point	floor;
	double			pos_z;
	int				pos;
	int				cell_x;
	int				cell_y;
	double			row_dist;
}	t_floorcast;

typedef struct s_raycast
{
	struct s_point	dir;
	struct s_point	map;
	struct s_point	side;
	struct s_point	delta;
	struct s_point	step;
	struct s_point	y_vertical;
	double			wall_dist;
	double			wall_x;
	double			dist_factor;
	int				height;
	int				side_col;
	double			dist_buffer_wall[WIDTH];
}	t_raycast;

typedef struct s_player
{
	char			direction;
	struct s_point	pos;
	struct s_point	dir;
	struct s_point	plane;
	struct s_point	mouse;
	double			angle;
	double			speed;
	int				pitch;
	int				jump;
	int				ceiling_col;
	int				floor_col;
	int				move_up;
	int				move_down;
	int				move_left;
	int				move_right;
	int				rotate_right;
	int				rotate_left;
	int				rotate_up;
	int				rotate_down;
	int				open_door;
	int				close_door;
	int				speed_up;
	int				welcome;
}	t_player;

typedef struct s_img
{
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_elem
{
	t_point		pos;
	t_raycast	ray;
	double		dist;
	int			type;
	int			status;
	int			door_id;
	int			sprite_id;
}	t_elem;

typedef struct s_spriteray
{
	t_point	ray;
	t_point	trans;
	t_point	draw_start;
	t_point	draw_end;
	t_point	tex;
	double	inv_det;
	int		screen_x;
	int		sprite_height;
	int		sprite_width;
}	t_spriteray;

typedef struct s_minimap
{
	double	size;
	t_point	start;
}	t_minimap;

typedef struct s_file
{
	t_list	*fd_list;
	char	**map;
	int		crgb[3];
	int		frgb[3];
	char	orientation;
	double	start[2];
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		fd;
	int		elem_count;
}	t_file;

typedef struct s_texture
{
	t_img		*img;
	int			x;
	int			y;
	double		step;
	double		pos;
	int			orientation;
}	t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_texture	*tex;
	t_img		*img;
	t_file		*file;
	t_player	*p;
	t_raycast	*ray;
	t_spriteray	*spriteray;
	t_floorcast	*floorcast;
	t_elem		*elem;
	t_minimap	*minimap;
}	t_data;

#endif
