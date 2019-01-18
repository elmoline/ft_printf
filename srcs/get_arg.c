/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:02:30 by evogel            #+#    #+#             */
/*   Updated: 2019/01/18 13:46:48 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long			get_int(t_format *fmt)
{
	long long d;

	if (L)
		d = (long long)va_arg(AP, long);
	else if (LL)
		d = va_arg(AP, long long);
	else if (H)
		d = (short)va_arg(AP, int);
	else if (HH)
		d = (char)va_arg(AP, int);
	else
		d = (long long)va_arg(AP, int);
	return (d);
}

unsigned long long	get_uns(t_format *fmt)
{
	unsigned long long u;

	if (L)
		u = (unsigned long long)va_arg(AP, unsigned long);
	else if (LL || CONV == 'p')
		u = va_arg(AP, unsigned long long);
	else if (H)
		u = (unsigned short)va_arg(AP, unsigned int);
	else if (HH)
		u = (unsigned char)va_arg(AP, unsigned int);
	else
		u = (unsigned long long)va_arg(AP, unsigned int);
	return (u);
}

long double			get_flt(t_format *fmt)
{
	long double f;

	if (FL)
		f = va_arg(AP, long double);
	else
		f = (long double)va_arg(AP, double);
	return (f);
}
