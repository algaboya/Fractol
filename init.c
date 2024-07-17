/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:08:02 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/11 15:49:04 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractol *fractol)
{
	fractol->escape_val = 4;
	fractol->iter_num = 42;
	fractol->x_shift = 0.0;
	fractol->y_shift = 0.0;
	fractol->zoom = 1.0;
}

static void	event_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_window, ON_KEYDOWN, 0, key_handler, fractol);
	mlx_hook(fractol->mlx_window, ON_MOUSEDOWN, 0, mouse_handler, fractol);
	mlx_hook(fractol->mlx_window, ON_DESTROY, 0, close_handler, fractol);
	mlx_hook(fractol->mlx_window, ON_MOUSEMOVE, 0, mouse_julia, fractol);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connect = mlx_init();
	if (fractol->mlx_connect == NULL)
		my_exit("initialize error\n");
	fractol->mlx_window = mlx_new_window(fractol->mlx_connect,
			WIDTH, HEIGHT, fractol->name);
	if (fractol->mlx_window == NULL)
	{
		mlx_destroy_window(fractol->mlx_connect, fractol->mlx_window);
		my_exit("window init error\n");
	}
	fractol->image.image_ptr = mlx_new_image(fractol->mlx_connect,
			WIDTH, HEIGHT);
	if (fractol->image.image_ptr == NULL)
	{
		mlx_destroy_window(fractol->mlx_connect, fractol->mlx_window);
		my_exit("image init error\n");
	}
	fractol->image.pixel_ptr = mlx_get_data_addr(fractol->image.image_ptr,
			&fractol->image.bit_pixel, &fractol->image.line_len,
			&fractol->image.endian);
	event_init(fractol);
	data_init(fractol);
}
