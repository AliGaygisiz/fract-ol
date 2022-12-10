/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:44:55 by agaygisi          #+#    #+#             */
/*   Updated: 2022/12/08 16:45:17 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# define HEIGHT 600
# define WIDTH 900
# define MAX_ITER 64

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_julia_z
{
	double	z_r;
	double	z_i;
}			t_julia_z;

typedef struct s_frame
{
	double	xs;
	double	xe;
	double	ys;
	double	ye;
	double	x;
	double	y;
	double	xd;
	double	yd;
	int		px;
	int		py;
	int		color;
	int		jul;
	int		fractal;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}			t_frame;

typedef struct s_new_frame
{
	double	ratio;
	int		xzm;
	int		yzm;
	double	nxs;
	double	nxe;
	double	nys;
	double	nye;
}			t_new_frame;

void		ft_frame_init(t_frame *f);
double		julia_r(int jul);
double		julia_i(int jul);
int			julia(double z_r, double z_i, t_frame *frame);
double		f_abs(double nbr);
int			snail(double z_r, double z_i);
int			mandelbrot(double z_r, double z_i);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			iter_color(t_frame *frame, int iter);
void		show_julia(t_frame *f);
void		show_mandelbrot(t_frame *f);
void		show_snail(t_frame *f);
void		ft_show_frame(t_frame *frame);
void		frame_restore(t_frame *frame, t_new_frame *new_frame);
void		new_frame_init(t_frame *frame, t_new_frame *new_frame);
int			zoom(int button, int x, int y, t_frame *f);
void		arrow_key(int keycode, t_frame *frame, t_new_frame *new_frame);
int			ft_quit(t_frame *frame);
void		change_color(t_frame *frame);
void		change_julia(t_frame *frame);
int			hook_keys(int kc, t_frame *frame);
void		print_error(void);
void		draw_frame(t_frame *frame);
#endif
