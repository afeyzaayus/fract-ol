/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:57:16 by aserbest          #+#    #+#             */
/*   Updated: 2025/02/20 17:58:38 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	set_variables(double *res, double *fraction, double *div, int *sign)
{
	*res = 0.0;
	*fraction = 0.0;
	*div = 1.0;
	*sign = 1;
}

int	is_valid_number(const char *str)
{
	int	dot_count;

	dot_count = 0;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0' || *str == '.')
		return (0);
	while (*str)
	{
		if (*str == '.')
		{
			if (++dot_count > 1)
				return (0);
		}
		else if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	if (*(str - 1) == '.')
		return (0);
	return (1);
}

static int	return_sign(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	double	divisor;
	int		sign;

	set_variables(&result, &fraction, &divisor, &sign);
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		sign = return_sign(*str++);
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			fraction = fraction * 10.0 + (*str++ - '0');
			divisor *= 10.0;
		}
	}
	return (sign * (result + fraction / divisor));
}

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = s;
	while (len > 0)
	{
		*(ptr++) = (unsigned char)c;
		len--;
	}
	return (s);
}
