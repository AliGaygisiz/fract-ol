/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:46:27 by agaygisi          #+#    #+#             */
/*   Updated: 2022/12/08 16:46:28 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	julia_r(int jul)
{
	if (jul % 4 == 0)
		return (0.33);
	else if (jul % 4 == 1)
		return (-0.4);
	else if (jul % 4 == 2)
		return (-0.835);
	else
		return (-0.8);
}

double	julia_i(int jul)
{
	if (jul % 4 == 0)
		return (0.42);
	else if (jul % 4 == 1)
		return (0.6);
	else if (jul % 4 == 2)
		return (-0.2321);
	else
		return (0.126);
}

int	julia(double z_r, double z_i, t_frame *frame)
{
	double		x;
	double		y;
	t_julia_z	jul;
	int			iter;
	double		temp_r;

	jul.z_r = julia_r(frame->jul);
	jul.z_i = julia_i(frame->jul);
	iter = -1;
	x = z_r;
	y = z_i;
	while (x * x + y * y <= 4 && ++iter < MAX_ITER)
	{
		temp_r = x * x - y * y + jul.z_r;
		y = 2 * x * y + jul.z_i;
		x = temp_r;
	}
	if (iter == 0 || iter == MAX_ITER)
		return (0);
	return (iter);
}

void	show_julia(t_frame *f)
{
	int	iter;

	while (f->py < HEIGHT)
	{
		while (f->px < WIDTH)
		{
			iter = julia(f->x, f->y, f);
			my_mlx_pixel_put(&f->img, f->px, f->py, iter_color(f, iter));
			f->x += f->xd;
			f->px++;
		}
		f->x = f->xs;
		f->px = 0;
		f->y -= f->yd;
		f->py++;
	}
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->img.img, 0, 0);
}

void	change_julia(t_frame *frame)
{
	frame->jul++;
	mlx_clear_window(frame->mlx, frame->mlx_win);
	ft_show_frame(frame);
}
