/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:32:17 by evogel            #+#    #+#             */
/*   Updated: 2019/01/14 21:19:44 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	get_len(long double f)
{
	int		len;

	len = 1;
	while (f > 9)
	{
		len++;
		f /= 10;
	}
	return (len);
}

char		*ft_flotoa(long double f, int preci)
{
	int					len;
	int					i;
	long double			nb;
	char				*num;

	nb = (f < 0 ? -f : f);
	len = (f < 0 ? get_len(nb) + 1 : get_len(nb));
	if (!(num = ft_strnew(len + (preci > 0 ? preci + 1 : 0))))
		return (NULL);
	i = 0;
	if (f < 0 && ++i)
		num[0] = '-';
	while (nb > 9)
		nb /= 10;
	while (i < len)
	{
		num[i] = (int)nb + '0';
		if (i == len - 1 && preci == 0 && (int)nb + 0.5 > (int)nb)
			num[i]++;
		nb -= (int)nb;
		nb *= 10;
		i++;
	}
	if (preci > 0)
		num[len++] = '.';
	while (preci > 0)
	{
		num[len++] = (int)nb + '0';
		nb -= (int)nb;
		nb = nb * 10 + (preci == 1 ? 0.5 : 0);
		--preci;
	}
	return (num);
}

int		treat_flt(va_list *ap, t_format *fmt)
{
	long double f;

	f = get_flt(ap, fmt);
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
