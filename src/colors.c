/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:45:59 by agaygisi          #+#    #+#             */
/*   Updated: 2022/12/08 16:46:00 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	iter_color(t_frame *frame, int iter)
{
	int	color;

	if (iter == 0)
		return (0x00000000);
	else if (iter < MAX_ITER / 2)
	{
		color = 256 - (256 / (MAX_ITER / 2) * iter);
		color = color << 24;
		color = color + frame->color;
		return (color);
	}
	else
		return (0x00FFFFFF);
}

void	change_color(t_frame *frame)
{
	static int	i;
	int			*colors;

	colors = malloc(sizeof(int) * 6);
	colors[0] = 0x00FF0000;
	colors[1] = 0x0000FF00;
	colors[2] = 0x000000FF;
	colors[3] = 0x00FFFF00;
	colors[4] = 0x0000FFFF;
	colors[5] = 0x00FF00FF;
	frame->color = colors[i % 6];
	i++;
	mlx_clear_window(frame->mlx, frame->mlx_win);
	ft_show_frame(frame);
	free(colors);
}
