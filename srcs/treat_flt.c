/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:32:17 by evogel            #+#    #+#             */
/*   Updated: 2019/01/17 13:38:30 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		treat_flt(t_format *fmt)
{
	double f;

	f = get_flt(fmt);
	RES = ft_flotoa(f, (PRECI == -1 ? 6 : PRECI));
	if (f >= 0 && (PLUS == 1 || SPACE == 1))
		if (!(set_prefx(fmt)))
				return (0);
	if (WIDTH > (int)ft_strlen(RES))
		if (!(set_width(fmt)))
			return (0);
	RET = ft_strlen(RES);
	return (1);
}
