/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flotoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:15:35 by evogel            #+#    #+#             */
/*   Updated: 2019/01/17 21:04:46 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static double	get_round(int preci)
{
	double round;

	round = 0.5;
	while (preci--)
		round /= 10.0;
	return (round);
}

static void		add_precision(char **num, double nb, int preci, int len)
{
	nb = nb - (unsigned long long)nb;
	(*num)[len++] = '.';
	while (preci-- > 0)
	{
		nb = nb * 10.0;
		(*num)[len++] = (int)nb + '0';
		nb = nb - (int)nb;
	}
}

char			*ft_flotoa(double f, int preci)
{
	char	*num;
	char	*tmp;
	double	nb;
	int		len;
	double	res;

	nb = (f < 0 ? -f : f);
	res = nb - (unsigned long long)nb;
	if (preci == 0 && res == 0.5 && (unsigned long long)nb % 2 == 1)
		nb = nb + 1;
	else if (preci == 0 && res > 0.5)
		nb = nb + 0.5;
	else
		nb = nb + get_round(preci);
	tmp = ft_itoabase((unsigned long long)nb, "0123456789");
	len = ft_strlen(tmp) + (f < 0 ? 1 : 0);
	if (!(num = ft_strnew(len + (preci > 0 ? preci + 1 : 0))))
		return (NULL);
	num[0] = (f < 0 ? '-' : num[0]);
	ft_strcat(num, tmp);
	free(tmp);
	if (preci > 0)
		add_precision(&num, nb, preci, len);
	return (num);
}
