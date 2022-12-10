/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:46:20 by agaygisi          #+#    #+#             */
/*   Updated: 2022/12/08 16:46:21 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdlib.h>

int	zoom(int button, int x, int y, t_frame *f)
{
	t_new_frame	nf;

	new_frame_init(f, &nf);
	if (button == 4)
	{
		nf.nye = f->ye + ((nf.yzm - ((y - f->ye) / HEIGHT) * nf.yzm) * f->yd);
		nf.nys = f->ys - (((((y - f->ye) / HEIGHT) * nf.yzm)) * f->yd);
		nf.nxe = f->xe - ((nf.xzm - (x - f->xe) / WIDTH * nf.xzm) * f->xd);
		nf.nxs = f->xs + (((((x - f->xe) / WIDTH) * nf.xzm)) * f->xd);
	}
	else if (button == 5)
	{
		nf.nye = f->ye - ((nf.yzm - ((y - f->ye) / HEIGHT) * nf.yzm) * f->yd);
		nf.nys = f->ys + (((((y - f->ye) / HEIGHT) * nf.yzm)) * f->yd);
		nf.nxe = f->xe + ((nf.xzm - (x - f->xe) / WIDTH * nf.xzm) * f->xd);
		nf.nxs = f->xs - (((((x - f->xe) / WIDTH) * nf.xzm)) * f->xd);
	}
	else
		return (0);
	frame_restore(f, &nf);
	mlx_clear_window(f->mlx, f->mlx_win);
	ft_show_frame(f);
	return (0);
}

void	arrow_key(int keycode, t_frame *frame, t_new_frame *new_frame)
{
	if (keycode == 124)
	{
		new_frame->nxs = frame->xs + (new_frame->xzm / 10.0 * frame->xd);
		new_frame->nxe = frame->xe + (new_frame->xzm / 10.0 * frame->xd);
	}
	else if (keycode == 123)
	{
		new_frame->nxs = frame->xs - (new_frame->xzm / 10.0 * frame->xd);
		new_frame->nxe = frame->xe - (new_frame->xzm / 10.0 * frame->xd);
	}
	else if (keycode == 126)
	{
		new_frame->nys = frame->ys + (new_frame->yzm / 10.0 * frame->yd);
		new_frame->nye = frame->ye + (new_frame->yzm / 10.0 * frame->yd);
	}
	else if (keycode == 125)
	{
		new_frame->nys = frame->ys - (new_frame->yzm / 10.0 * frame->yd);
		new_frame->nye = frame->ye - (new_frame->yzm / 10.0 * frame->yd);
	}
}

int	ft_quit(t_frame *frame)
{
	mlx_destroy_window(frame->mlx, frame->mlx_win);
	exit(0);
}

int	hook_keys(int kc, t_frame *frame)
{
	t_new_frame	new_frame;

	new_frame_init(frame, &new_frame);
	if (kc == 53 || kc == 12 || kc == 17)
		ft_quit(frame);
	else if (kc == 123 || kc == 124 || kc == 125 || kc == 126)
		arrow_key(kc, frame, &new_frame);
	else if (kc == 8)
		change_color(frame);
	else if (kc == 38)
		change_julia(frame);
	frame_restore(frame, &new_frame);
	mlx_clear_window(frame->mlx, frame->mlx_win);
	ft_show_frame(frame);
	return (0);
}

void	print_error(void)
{
	write(1, "./fractol [Mandelbrot, Julia, Snail]\n", 37);
	exit(0);
}
