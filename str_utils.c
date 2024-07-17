/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:27:43 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/10 18:52:13 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
		return (0);
	if (ft_strlen(s1) == 0)
		return (-1);
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

double	ft_atodbl(char *str)
{
	long	int_part;
	int		sign;
	double	aft_dot;
	double	pow;

	pow = 1;
	int_part = 0;
	aft_dot = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while (*str != '.' && *str)
		int_part = (int_part * 10) + (*str++ - 48);
	if (*str == '.')
		str++;
	while (*str)
	{
		pow /= 10;
		aft_dot = aft_dot + (*str - 48) * pow;
		str++;
	}
	return ((int_part + aft_dot) * sign);
}
