/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:34:02 by evogel            #+#    #+#             */
/*   Updated: 2018/12/19 11:35:24 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		treat_int(long long d, t_flags *flag)
{
	char	*res;
	int		ret;

	res = ft_itoa(d);
	res = set_preci(flag->preci, res);
	if (d >= 0 && (flag->p == 1 || flag->s == 1))
		res = set_prefix(res, flag);
	if (flag->width > (int)ft_strlen(res))
		res = set_width(flag->width, res, flag);
	ft_putstr(res);
	ret = ft_strlen(res);
	free(res);
	return (ret);
}
