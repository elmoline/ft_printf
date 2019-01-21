/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 11:32:05 by evogel            #+#    #+#             */
/*   Updated: 2019/01/21 17:11:20 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		get_flag(char c, t_format *fmt)
{
	if (c == '#' && (HASH = 1))
		return (1);
	else if (c == '0' && (ZERO = 1))
		return (1);
	else if (c == '-' && (MINUS = 1))
		return (1);
	else if (c == '+' && (PLUS = 1))
		return (1);
	else if (c == ' ' && (SPACE = 1))
		return (1);
	else if (c == '_' && (FILL = (unsigned char)va_arg(AP, int)))
		return (1);
	else if (c == '|' && (MID = 1))
		return (1);
	return (0);
}

void	get_field(const char **format, t_format *fmt)
{
	int	*n;
	int	tmp;

	if ((**format == '.' && ++(*format)) || (WIDTH && **format == '*'))
	{
		n = &PRECI;
		*n = 0;
	}
	else
		n = &WIDTH;
	tmp = 0;
	while (ft_isdigit(**format) == 1)
	{
		tmp = tmp * 10 + (**format - '0');
		*n = tmp;
		++(*format);
	}
	if (**format == '*' && ++(*format))
	{
		*n = va_arg(AP, int);
		if (n == &WIDTH && *n < 0 && (MINUS = 1))
			*n = *n * -1;
	}
}

void	get_length(const char **format, t_format *fmt)
{
	if (**format == 'l')
	{
		++(*format);
		if (**format == 'l' && ++(*format))
			LL = 1;
		else
			L = 1;
	}
	else if (**format == 'h')
	{
		++(*format);
		if (**format == 'h' && ++(*format))
			HH = 1;
		else
			H = 1;
	}
	else if (**format == 'L' && ++(*format))
		FL = 1;
}

int		get_converter(const char **format, t_format *fmt)
{
	if (**format == '\0' || !ft_strchr(SUPP, **format))
		return (0);
	CONV = **format;
	++(*format);
	if (ft_strchr(CAPS, CONV))
	{
		CAP = 1;
		CONV = CONV + 32;
	}
	if (ft_strchr(LLEN, CONV))
	{
		if (L == 1 && (LL = 1))
			L = 0;
		else
			L = 1;
		CONV = CONV + 32;
	}
	return (1);
}

void	get_base(t_format *fmt)
{
	if (CONV == 'o')
		ft_strcpy(BASE, "01234567");
	else if (CONV == 'x' || CONV == 'p')
		ft_strcpy(BASE, "0123456789abcdef");
	else if (CONV == 'b')
		ft_strcpy(BASE, va_arg(AP, char*));
	else
		ft_strcpy(BASE, "0123456789");
}
