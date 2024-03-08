/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:34:56 by ruiolive          #+#    #+#             */
/*   Updated: 2024/03/08 10:04:29 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <wait.h>
# include <signal.h>
# include <pthread.h>
# include "./include/Libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_info
{
	char	*angle_x;
	char	*angle_y;
	char	*angle_z;
	char	*zoom;
	char	*high;
	char	*horizontal;
	char	*Vertical;
	char	*color_rad;
}	t_info;

typedef struct s_fdf
{
	float	z;
	int		color;
}	t_fdf;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	float	z;
	float	z1;
	double	zoom;
	double	u;
	double	v;
	double	x_step;
	double	y_step;
	int		width;
	int		height;
	int		max;
	int		color_default;
	int		menu_color;
	int		color_save;
	int		add_color;
	int		hor;
	int		hey;
	int		button;
	int		max_z;
	int		min_z;
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
	int		render_status;
	char	*map_to_render;
	char	*choose_img;
	char	*choose_file;
	char	*menu_entry_file;
	char	*entry_img;
	char	*menu_img;
	char	*menu_file;
	t_info	info;
	t_fdf	**map;
	t_img	img;
	float	z_copy;
	float	z1_copy;
	int		red;
	int		green;
	int		blue;	
}	t_data;

///////////////////////////////
//       Map Functions       //
///////////////////////////////

void	creat_map(char *file, t_data *data);
void	map_size(char *file, t_data *data);
void	ft_write_map(t_data *data);
void	fill_map(char *file, t_data *data);
void	fill_matrix(t_data *data, int x, int y, char *splited);
void	ft_read_error(char *line);
void	ft_open_error(int fd);

///////////////////////////////
//       Init Functions      //
///////////////////////////////

int		init_window(t_data *data);
void	open_window(t_data *data);
void	init_data(t_data *data);

///////////////////////////////
//      Render Functions     //
///////////////////////////////

int		render_map(t_data *data);
int		menu_render(t_data *data);
int		menu_background_render(t_data *data);
void	render_strings1(t_data *data);
void	render_strings2(t_data *data);
void	map_par(t_data *data);
void	map_impar(t_data *data);
void	map_misto1(t_data *data);
void	map_misto2(t_data *data);
int		render_menu(t_data *data);
int		render_choose_menu(t_data *data);

///////////////////////////////
//    Bresenham Functions    //
///////////////////////////////

int		build_img(t_data *data);
float	positive(float n);
float	max_step(float x_step, float y_step);
void	bresenham(t_data *data, double x1, double y1);


///////////////////////////////
//     Handlers Functions    //
///////////////////////////////

int		handle_keypress(int keysym, t_data *data);
int		handle_entry_menu_keypress(int keysym, t_data *data);
int		handle_close(t_data *data);
int		handle_menu_close(t_data *data);
int		handle_menu_choose_close(t_data *data);
int		handle_mouse_move(int x, int y, t_data *data);
int		handle_entry_mouse_move(int x, int y, t_data *data);
int		handle_choose_map_mouse_move(int x, int y, t_data *data);
int		handle_mouse_down(int button, int x, int y, t_data *data);
int		handle_entry_mouse_down(int button, int x, int y, t_data *data);
int		handle_choose_map_mouse_down(int button, int x, int y, t_data *data);
int		handle_mouse_up(int button, int x, int y, t_data *data);
int		handle_entry_mouse_up(int button, int x, int y, t_data *data);
int		handle_choose_map_mouse_up(int button, int x, int y, t_data *data);
int		move_handle(int keysym, t_data *data);
int		angle_handle(int keysym, t_data *data);
int		projection_handle(int keysym, t_data *data);
int		z_handle(int keysym, t_data *data);
int		check_if_between(int begin, int end, int num_to_check);

///////////////////////////////
//      Colors Functions     //
///////////////////////////////

int		atoi_base(char *str);
int		check_for_colors(char *str);
int		get_pos(char c);
int		color_handler(int keysym, t_data *data);
void	colors_change(t_data *data);
void	colors1(t_data *data);
void	colors2(t_data *data);
void	colors3(t_data *data);
void	colors4(t_data *data);
void	get_max_z(t_data *data);
void	get_min_z(t_data *data);

////////////////////////////////////////////////////
//     Rotation / Translation / zoom Functions    //
////////////////////////////////////////////////////

void	rotation(t_data *data, double *x1, double *y1);
void	rotate_x_axis(t_data *data, double *y, float *z);
void	rotate_y_axis(t_data *data, double *x, float *z);
void	rotate_z_axis(t_data *data, double *x, double *y);
void	zoom(double *x, double *y, t_data *data);
void	map_move(double *x, double *y, t_data *data);

///////////////////////////////
//       Keys Functions      //
///////////////////////////////

int		decrease_z(t_data *data);
int		increase_z(t_data *data);

///////////////////////////////
//       Free functions      //
///////////////////////////////

void	ft_free_map(t_data *data);
void	ft_free_splited(char **splited);
void	free_info(t_data *data);



void ftoa(float n, char* res, int afterpoint) ;

///////////////////////////////
//       Roid_functions      //
///////////////////////////////

int		roid_render_map(t_data *data);
void	roid_map_par(t_data *data);
void	roid_map_impar(t_data *data);
void	roid_map_misto1(t_data *data);
void	roid_map_misto2(t_data *data);
void	roid_bresenham(t_data *data, double x1, double y1);
int		roid_rotation(t_data *data, double *x1, double *y1);
int		roid_handle_keypress(int keysym, t_data *data);
int		roid_handle_mouse_move(int x, int y, t_data *data);
int		roid_handle_mouse_down(int button, int x, int y, t_data *data);
void	roid_bresenham_colour(t_data *data, double x1, double y1);
int 	roid_color(t_data *data, double z_point);
int		roid_colors_above_2(t_data *data, double z_point);
int		roid_colors_below_2(t_data *data, double z_point);
int		roid_colors_above_3(t_data *data, double z_point);
int		roid_colors_below_3(t_data *data, double z_point);
int		roid_colors_above_4(t_data *data, double z_point);
int		roid_colors_below_4(t_data *data, double z_point);
int		roid_build_img(t_data *data, int color);


#endif