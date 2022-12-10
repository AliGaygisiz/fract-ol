/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:45:41 by agaygisi          #+#    #+#             */
/*   Updated: 2022/12/08 16:45:43 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int	main(int argc, char *argv[])
{
	t_frame	frame;

	if (argc != 2)
		print_error();
	if (!ft_strncmp(argv[1], "Mandelbrot", 11))
	{
		ft_frame_init(&frame);
		frame.fractal = 1;
	}
	else if (!ft_strncmp(argv[1], "Julia", 6))
	{
		ft_frame_init(&frame);
		frame.fractal = 2;
	}
	else if (!ft_strncmp(argv[1], "Snail", 6))
	{
		ft_frame_init(&frame);
		frame.fractal = 3;
	}
	else
		print_error();
	draw_frame(&frame);
	return (0);
}

void	draw_frame(t_frame *frame)
{
	ft_show_frame(frame);
	mlx_key_hook(frame->mlx_win, hook_keys, frame);
	mlx_hook(frame->mlx_win, 4, 1L << 0, zoom, frame);
	mlx_hook(frame->mlx_win, 17, 0, ft_quit, frame);
	mlx_loop(frame->mlx);
}
