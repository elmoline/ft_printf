/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:02:30 by evogel            #+#    #+#             */
/*   Updated: 2019/01/14 20:12:41 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long			get_int(va_list *ap, t_format *fmt)
{
	long long d;

	if (L)
		d = (long long)va_arg(*ap, long);
	else if (LL)
		d = va_arg(*ap, long long);
	else if (H)
		d = (short)va_arg(*ap, int);
	else if (HH)
		d = (char)va_arg(*ap, int);
	else
		d = (long long)va_arg(*ap, int);
	return (d);
}

unsigned long long	get_uns(va_list *ap, t_format *fmt)
{
	unsigned long long u;

	if (L)
		u = (unsigned long long)va_arg(*ap, unsigned long);
	else if (LL || CONV == 'p')
		u = va_arg(*ap, unsigned long long);
	else if (H)
		u = (unsigned short)va_arg(*ap, unsigned int);
	else if (HH)
		u = (unsigned char)va_arg(*ap, unsigned int);
	else
		u = (unsigned long long)va_arg(*ap, unsigned int);
	return (u);
}

long double			get_flt(va_list *ap, t_format *fmt)
{
	long double f;

	if (FL)
		f = va_arg(*ap, long double);
	else
		f = (long double)va_arg(*ap, double);
	return (f);
}
