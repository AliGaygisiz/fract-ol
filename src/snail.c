/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snail.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:46:50 by agaygisi          #+#    #+#             */
/*   Updated: 2022/12/08 16:46:52 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	f_abs(double nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	snail(double z_r, double z_i)
{
	double	x;
	double	y;
	int		iter;
	double	temp_r;

	iter = -1;
	x = z_r;
	y = z_i;
	while (x * x + y * y <= 4 && ++iter < MAX_ITER)
	{
		temp_r = x * x - y * y + z_i;
		y = f_abs(2 * x * y);
		x = temp_r;
	}
	if (iter == 0 || iter == MAX_ITER)
		return (0);
	return (iter);
}

void	show_snail(t_frame *f)
{
	int	iter;

	while (f->py < HEIGHT)
	{
		while (f->px < WIDTH)
		{
			iter = snail(f->x, f->y);
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
