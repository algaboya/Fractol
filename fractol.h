/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:10:20 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/10 20:41:16 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx/mlx.h"

# define KEY_MINUS 27
# define KEY_PLUS 24
# define KEY_UP 	126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_ESCAPE 53

# define MOUSE_WHEELUP 5
# define MOUSE_WHEELDOWN 4

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define WIDTH 800
# define HEIGHT 800

// COLORS

# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define RED 0xFF0000  
# define GREEN 0x00FF00 
# define BLUE 0x0000FF 

enum e_sh
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_compl
{
	double	rx;
	double	iy;
}				t_compl;

typedef struct s_img
{
	void	*image_ptr;
	char	*pixel_ptr;
	int		bit_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_fractol
{
	void	*mlx_connect;
	void	*mlx_window;
	char	*name;
	t_img	image;
	double	escape_val;
	int		iter_num;
	double	x_shift;
	double	y_shift;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractol;

int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, int n);
void	my_exit(char *str);
void	ft_putstr(char *s);
void	fractol_init(t_fractol *fractol);
void	fractol_render(t_fractol *fractol);
void	put_my_pixel(int x, int y, t_img *img, int color);
double	map(double unscaled_num, double new_min,
			double new_max, double old_max);
void	fractol_render(t_fractol *fractol);
int		key_handler(int keysym, t_fractol *fractol);
int		close_handler(t_fractol *fractol);
int		mouse_handler(int button, int x, int y, t_fractol *fractol);
double	ft_atodbl(char *str);
int		mouse_julia(int x, int y, t_fractol *fractol);
t_compl	square_comp(t_compl z);
t_compl	sum_comp(t_compl a, t_compl b);

#endif