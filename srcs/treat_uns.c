/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_uns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 11:33:39 by evogel            #+#    #+#             */
/*   Updated: 2018/12/19 14:18:59 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			treat_unsigned(unsigned long long u, t_flags *flag)
{
	char	*res;
	char	c;
	int		ret;

	res = NULL;
	c = flag->c;
	if (c == 'u')
		res = ft_itoabase(u, "0123456789");
	else if (c == 'o')
		res = ft_itoabase(u, "01234567");
	else if (c == 'x' || c == 'p')
		res = ft_itoabase(u, "0123456789abcdef");
	else if (c == 'X')
		res = ft_itoabase(u, "0123456789ABCDEF");
	res = set_preci(flag->preci, res);
	if (c == 'p' || (flag->hs && c == 'o' && res[0] != '0')
			|| (flag->hs && (c == 'x' || c == 'X') && u != 0))
		res = set_prefix(res, flag);
	if (flag->width > (int)ft_strlen(res))
		res = set_width(flag->width, res, flag);
	ft_putstr(res);
	ret = ft_strlen(res);
	free(res);
	return (ret);
}
