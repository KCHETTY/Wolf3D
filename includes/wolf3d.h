/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 11:25:28 by kchetty           #+#    #+#             */
/*   Updated: 2016/06/26 13:00:43 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# include <math.h>

# define WIN_W 640
# define WIN_H 320

# define KB_ESC 65307
# define KB_UP 65362
# define KB_DOWN 65364
# define KB_LEFT 65361
# define KB_RIGHT 65363

# define RED1		0xFF0000
# define RED2		0x550000
# define GREEN1		0x00FF00
# define GREEN2		0x005500
# define BLUE1		0x0000FF
# define BLUE2		0x000055
# define YELLOW1	0xFFFF00
# define YELLOW2	0x555500
# define PURPLE1	0xBF3EFF
# define PURPLE2	0x551A8B

typedef struct	s_raycaster
{
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		ray_pos_x;
	double		ray_pos_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			draw_start;
	int			draw_end;
	int			detect_wall;
	int			side;
	int			line_height;
}				t_raycaster;

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	int			step_x;
	int			step_y;
	double		r_speed;
	double		m_speed;
	int			map_x;
	int			map_y;
	double		h_camera;
	int			wall_side;
	int			left;
	int			right;
	int			up;
	int			down;
}				t_player;

typedef struct	s_map
{
	int		x;
	int		y;
	int		i;
	char	*buf;
	int		j;
}				t_map;

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	int				ex;
	int				ey;
	void			*img;
	int				**map;
	char			*data;
	int				fd;
	int				bpp;
	unsigned int	color;
	int				size_line;
	int				endian;
}				t_env;

typedef struct	s_glob
{
	t_env		env;
	t_map		map;
	t_player	p;
	t_raycaster ray;
}				t_glob;

void			ft_error(int err);
void			ft_colors(t_glob *g, float x, int y);
int				ft_esc(int keycode);
int				quitwin();
int				key_press(int keycode, t_glob *g);
int				key_release(int keycode, t_glob *g);
void			get_map(t_glob *g, char *file);
void			loops_hook(t_glob *g);
void			move(t_glob *g);
#endif
