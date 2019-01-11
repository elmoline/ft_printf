/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:22:05 by evogel            #+#    #+#             */
/*   Updated: 2018/12/19 14:19:44 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		dispatcher(va_list *ap, const char **fmt)
{
	t_flags	*flag;
	int		ret;

	if (!(flag = get_flags(fmt, ap)))
		return (-1);
	flag->c = **fmt;
	++(*fmt);
	ret = treat_type(ap, flag);
	free(flag);
	return (ret);
}

int		ft_printf(const char *fmt, ...)
{
	va_list ap;
	int		ret;

	ret = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			++fmt;
			ret += dispatcher(&ap, &fmt);
		}
		else
		{
			ft_putchar(*fmt++);
			++ret;
		}
	}
	va_end(ap);
	return (ret);
}
