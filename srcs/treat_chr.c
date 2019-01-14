/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 18:54:03 by evogel            #+#    #+#             */
/*   Updated: 2019/01/14 19:26:47 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		treat_chr(va_list *ap, t_format *fmt)
{
	char c;

	c = (CONV == '%' ? '%' : (char)va_arg(*ap, int));
	if (!(RES = ft_strnew(1)))
		return (0);
	RES[0] = c;
	if (WIDTH > 1)
	{
		if (!(set_width(fmt)))
			return (0);
		RET = WIDTH;
	}
	else
		RET = 1;
	return (1);
}
