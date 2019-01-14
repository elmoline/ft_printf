/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:22:05 by evogel            #+#    #+#             */
/*   Updated: 2019/01/14 19:40:57 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int		treatment(va_list *ap, t_format *fmt)
{
	int i;

	i = 0;
	while (!ft_strchr(TYPE[i], CONV) && i < 5)
		i++;
	if (!TREAT_TYPE[i](ap, fmt))
		return (0);
	return (1);
}

int		converter(va_list *ap, const char **format)
{
	t_format	*fmt;
	int			ret;

	if (!(fmt = get_format(ap, format)))
		return (0);
	if (!treatment(ap, fmt))
	{
		if (RES)
			free(RES);
		ft_memdel((void**)&fmt);
		return (0);
	}
	write(1, RES, RET);
	ret = RET;
	free(RES);
	ft_memdel((void**)&fmt);
	return (ret);
}

//adjust GET_ARG to use new struct strings

//changed names of structure, must carry to the rest of functions
//have to make error cases checks and securities for mallocs etc

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		ret;

	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			ret += converter(&ap, &format);
		}
		else
		{
			ft_putchar(*format++);
			++ret;
		}
	}
	va_end(ap);
	return (ret);
}
