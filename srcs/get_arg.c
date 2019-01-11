/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:02:30 by evogel            #+#    #+#             */
/*   Updated: 2019/01/11 16:29:19 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long long			get_int(va_list *ap, t_flags *flag)
{
	long long d;

	if (flag->l)
		d = (long long)va_arg(*ap, long);
	else if (flag->ll)
		d = va_arg(*ap, long long);
	else if (flag->h)
		d = (short)va_arg(*ap, int);
	else if (flag->hh)
		d = (char)va_arg(*ap, int);
	else
		d = (long long)va_arg(*ap, int);
	return (d);
}

static unsigned long long	get_unsigned(va_list *ap, t_flags *flag)
{
	unsigned long long u;

	if (flag->l)
		u = (unsigned long long)va_arg(*ap, unsigned long);
	else if (flag->ll || flag->c == 'p')
		u = va_arg(*ap, unsigned long long);
	else if (flag->h)
		u = (unsigned short)va_arg(*ap, unsigned int);
	else if (flag->hh)
		u = (unsigned char)va_arg(*ap, unsigned int);
	else
		u = (unsigned long long)va_arg(*ap, unsigned int);
	return (u);
}

int							treat_type(va_list *ap, t_flags *flag)
{
	char	c;
	int		ret;

	ret = 0;
	c = flag->c;
	if (c == 'd' || c == 'i')
		ret = treat_int(get_int(ap, flag), flag);
	else if (c == 'u' || c == 'o' || c == 'x' || c == 'X' || c == 'p')
		ret = treat_unsigned(get_unsigned(ap, flag), flag);
	else if (c == 'c' || c == '%')
		ret = treat_char((c == '%' ? '%' : (char)va_arg(*ap, int)), flag);
	else if (c == 's')
		ret = treat_string(va_arg(*ap, char*), flag);
	else if (c == 'f' && flag->l_cap == 1)
		ret = treat_float(va_arg(*ap, long double), flag);
	else if (c == 'f')
		ret = treat_float(va_arg(*ap, double), flag);
	return (ret);
}
