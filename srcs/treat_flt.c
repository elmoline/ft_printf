/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:32:17 by evogel            #+#    #+#             */
/*   Updated: 2019/01/11 16:30:59 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int	get_len(double f)
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

char		*ft_flotoa(double f, int preci)
{
	int					len;
	int					i;
	double				nb;
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
	printf("nb = %.20f\n", nb);
	while (i < len)
	{
		num[i] = (int)nb + '0';
		if (i == len - 1 && preci == 0 && (int)nb + 0.5 > (int)nb)
			num[i]++;
		nb -= (int)nb;
	printf("nb = %.20f\n", nb);
		nb *= 10;
		i++;
//		printf("nb = %.20f\n", nb);
	}
	if (preci > 0)
		num[len++] = '.';
	while (preci > 0)
	{
		num[len++] = (int)nb + '0';
		nb -= (int)nb;
		nb = nb * 10 + (preci == 1 ? 0.5 : 0);
		--preci;
//		printf("nb = %.20f\n", nb);
	}
	return (num);
}

int		treat_float(double f, t_flags *flag)
{
	int		ret;
	char	*res;

	res = ft_flotoa(f, (flag->preci == -1 ? 6 : flag->preci));
	if (f >= 0 && (flag->p == 1 || flag->s == 1))
		res = set_prefix(res, flag);
	if (flag->width > (int)ft_strlen(res))
		res = set_width(flag->width, res, flag);
	ft_putstr(res);
	ret = ft_strlen(res);
	free(res);
	return (ret);
}
