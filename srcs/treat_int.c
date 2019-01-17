/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:34:02 by evogel            #+#    #+#             */
/*   Updated: 2019/01/17 13:38:44 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		treat_int(t_format *fmt)
{
	long long d;

	d = get_int(fmt);
	NEG = (d < 0 ? 1 : 0);
	if (!(RES = ft_itoa(d)))
		return (0);
	if (!(set_preci(fmt)))
		return (0);
	if (d >= 0 && (PLUS == 1 || SPACE == 1))
		if (!(set_prefx(fmt)))
			return (0);
	if (WIDTH > (int)ft_strlen(RES))
		if (!(set_width(fmt)))
			return (0);
	RET = ft_strlen(RES);
	return (1);
}
