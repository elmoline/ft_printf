/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_uns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 11:33:39 by evogel            #+#    #+#             */
/*   Updated: 2019/01/18 11:16:27 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Prefix condition:
** when preci already put 0 in front of octal, no need to add prefix
** hexa no prefix when 0
*/

int			treat_uns(t_format *fmt)
{
	unsigned long long u;

	u = get_uns(fmt);
	if (!(RES = ft_itoabase(u, BASE)))
		return (0);
	if (!(set_preci(fmt)))
		return (0);
	if ((HASH && ((CONV == 'o' && RES[0] != '0') || (CONV == 'x' && u != 0)))
			|| CONV == 'p')
		if (!(set_prefx(fmt)))
			return (0);
	if (WIDTH > (int)ft_strlen(RES))
		if (!(set_width(fmt)))
			return (0);
	if (CAP == 1)
		ft_capitalize(RES);
	RET = ft_strlen(RES);
	return (1);
}
