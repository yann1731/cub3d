/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:21:37 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/18 16:25:38 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/includes/libft.h"
# include "../mlx-mac/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <sys/time.h>
# define SCREENWIDTH 1024
# define SCREENHEIGHT 768

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	UPKEY = 13,
	DOWNKEY = 1,
	LEFTKEY = 0,
	RIGHTKEY = 2,
	LEFTARROW = 123,
	RIGHTARROW = 124,
	EKEY = 14,
	ESC = 53
};

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_point
{
	int		x;
	int		y;
	char	value;
}	t_point;

typedef struct s_map
{
	char	**textures;
	char	**map;
	int		ccolor;
	int		fcolor;
	int		height;
	int		width;
	int		size;
}	t_map;

typedef struct s_env
{
	t_img	*s_wall;
	t_img	*n_wall;
	t_img	*e_wall;
	t_img	*w_wall;
}	t_env;

typedef struct s_dda
{
	double	x;
	double	y;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	int		oldx;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	hitwall;
	bool	door;
	bool	shooting;
	int		s_frame;
}	t_dda;

// vector coordinates are normalized
typedef struct s_player
{
	char	direction;
	double	forward_accel;
	double	rear_accel;
	double	right_accel;
	double	left_accel;
	double	accel_rotate;
}	t_player;

typedef struct s_fnorm
{
	int	x;
	int	y;
	int	startx;
	int	starty;
}	t_fnorm;

typedef struct s_enemy
{
	double	x;
	double	y;
	double	dirx;
	double	diry;
	t_img	*s1;
	t_img	*s2;
	t_img	*s3;
	t_img	*s4;
}	t_enemy;

typedef struct s_data
{
	void			*mlx;
	void			*window;
	struct timeval	starttime;
	struct timeval	currenttime;
	t_fnorm			fnorm;
	t_img			*frame;
	t_img			*mmap;
	t_img			*arm;
	t_img			*shoot;
	t_img			*door;
	t_img			*nav_map;
	t_img			*carl;
	t_map			*map;
	t_player		*player;
	t_dda			*dda;
	t_env			*env;
	t_enemy			*enemy;
	bool			map_open;
}	t_data;

/*--- Functions ---*/

/*--- dda_routine.c ---*/
void			init_dda_vars(t_data *data);
void			dda_routine(t_data *data);
void			step_x(t_data *data);
void			step_y(t_data *data);
void			draw(t_data *data, int x);

/*--- dda.c ---*/
void			set_ray(t_data *data, int x);
void			set_step(t_data *data);
void			do_dda(t_data *data);
void			set_draw_len(t_data *data, int x);

/*--- error_utils.c ---*/
int				check_filepath(char *filepath);
void			error_checking(char *filepath);

/*--- init_utils.c ---*/
t_data			*init_struct(void);
void			alloc_images(t_data *data);
void			shade_segment(t_data *data, int x);

/*--- map_utils.c ---*/
void			my_put_player(t_data *data, int posx, int posy);
void			player_ray(t_data *data, int posx, int posy);
void			make_square(t_data *data, int x, int y, int color);
void			display_routine(t_data *data);
void			setup_navmap(t_data *data);

/*--- map_utils2.c ---*/
void			init_navmap(t_data *data);
void			fuck_norme(t_data *data);

/*--- mem_utils.c ---*/
void			destroy_images(t_data *data);
void			free_images(t_data *data);
void			x_free(void *tofree);
void			my_mlx_destroy_image(t_data *data, void *img);
void			memclean(t_data *data);

/*--- move_utils.c ---*/
void			move_up(t_data *data);
void			move_down(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);
void			movement(int keycode, t_data *data);

/*--- move_utils2.c ---*/
int				get_mouse_pos(int x, int y, t_data *data);
void			rotate_left(t_data *data);
void			rotate_right(t_data *data);

/*--- utils.c ---*/
int				destroy_window(t_data *data);
int				handle_keypress(int keysym, t_data *data);
int				convert_to_rgb(char *r, char *g, char *b);
void			print_structure(t_data *data);
char			*get_wall(int index);
void			memclean(t_data *data);
void			make_square(t_data *data, int x, int y, int color);

/*--- parse.c ---*/
int				parser(char *filepath, t_data *data);
int				setup_mlx(t_data *data);
void			set_plane(t_data *data);
void			set_vector(t_data *data);
int				get_map_len(char **map);

/*--- render_utils.c ---*/
int				render_loop(t_data *data);
int				get_mouse_pos(int x, int y, t_data *data);
void			my_clear_img(t_img *img);
void			player_ray(t_data *data, int posx, int posy);
void			movement(int keycode, t_data *data);
void			render_fps(t_data *data);
void			render_map(t_data *data);

/*--- render_utils_bonus2.c ---*/
void	shooting(t_data *data);

/*--- scaling_utils.c ---*/
unsigned int	get_colors(t_img *data, double x, double y);
void			my_get_data_addr(t_img *img);
void			my_mlx_pixel_put(t_img *data, double x, double y, int color);
void			image_scale_init(t_data *data, float scale);

/*--- texture_utils.c ---*/
int				texture_init_one(t_data *data);
int				texture_init_two(t_data *data);
int				texture_init_three(t_data *data);
int				enemy_texture_init(t_data *data);

/*--- UNSORTED ---*/
int				forge_structure(char **array, t_data *data);
char			**tokenize(char *line);
int				set_tokens(char **tokens, t_data *data);
int				parse_map(char **tokens, int *i, t_data *data);
int				calculate_dimensions(char **tokens, int *i, t_data *data);
int				check_map_integrity(t_data *data);
int				setup_mlx(t_data *data);
void			vert_slice(t_data *data, t_img *img, int x);
void			move(t_data *data);
int				decel(int keycode, t_data *data);
void			accel_up(t_data *data);
void			accel_down(t_data *data);
void			accel_right(t_data *data);
void			accel_left(t_data *data);
void			clear_scaled_img(t_img *img, float scale);
void			free_images_two(t_data *data);
void			render_ceiling(t_data *data);
void			render_floor(t_data *data);
void			accel_rotate_left(t_data *data);
void			accel_rotate_right(t_data *data);
void			rotate(t_data *data);
int				mouse_down(int button, int x, int y, t_data *data);

/*--- parsing_utils.c ---*/
char			**read_file(char *filepath);
char			*fill_line(char *line, int longest);

/*--- validation_map.c ---*/
int				validate_map(t_map *map, t_data *data);
int				is_map(char *line);

/*--- set_data.c ---*/
int				set_player(t_data *data);

/*--- axis.c ---*/
int				check_left(t_data *data, int x, int y);
int				check_right(t_data *data, int x, int y);
int				check_up(t_data *data, int x, int y);
int				check_down(t_data *data, int x, int y);

#endif
