/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:57:16 by aserbest          #+#    #+#             */
/*   Updated: 2025/02/25 20:04:50 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	set_variable(double *integer, double *fract, double *div, int *sign)
{
	*integer = 0.0;
	*fract = 0.0;
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

double	ft_atod(const char *str)
{
	double	integer;
	double	fraction;
	double	divisor;
	int		sign;

	set_variable(&integer, &fraction, &divisor, &sign);
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		sign = return_sign(*str++);
	while (*str >= '0' && *str <= '9')
		integer = integer * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			fraction = fraction * 10.0 + (*str++ - '0');
			divisor *= 10.0;
		}
	}
	return (sign * (integer + fraction / divisor));
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
