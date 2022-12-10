/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:46:44 by agaygisi          #+#    #+#             */
/*   Updated: 2022/12/08 16:46:45 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_frame_init(t_frame *f)
{
	f->xs = -2.0;
	f->xe = 1.0;
	f->ys = 1.0;
	f->ye = -1.0;
	f->x = -2.0;
	f->y = 1.0;
	f->xd = (f->xe - f->xs) / WIDTH;
	f->yd = (f->ys - f->ye) / HEIGHT;
	f->px = 0;
	f->py = 0;
	f->color = 0x0000FF00;
	f->jul = 0;
	f->fractal = 0;
	f->mlx = mlx_init();
	f->mlx_win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bits_per_pixel,
			&f->img.line_length, &f->img.endian);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_show_frame(t_frame *frame)
{
	if (frame->fractal == 1)
		show_mandelbrot(frame);
	else if (frame->fractal == 2)
		show_julia(frame);
	else if (frame->fractal == 3)
		show_snail(frame);
}

void	frame_restore(t_frame *frame, t_new_frame *new_frame)
{
	frame->ye = new_frame->nye;
	frame->ys = new_frame->nys;
	frame->xe = new_frame->nxe;
	frame->xs = new_frame->nxs;
	frame->x = frame->xs;
	frame->y = frame->ys;
	frame->xd = (frame->xe - frame->xs) / WIDTH;
	frame->yd = (frame->ys - frame->ye) / HEIGHT;
	frame->px = 0;
	frame->py = 0;
}

void	new_frame_init(t_frame *frame, t_new_frame *new_frame)
{
	new_frame->ratio = (double)WIDTH / (double)HEIGHT;
	new_frame->yzm = 200;
	new_frame->xzm = (int)((float)new_frame->yzm * new_frame->ratio);
	new_frame->nxs = frame->xs;
	new_frame->nxe = frame->xe;
	new_frame->nys = frame->ys;
	new_frame->nye = frame->ye;
}
