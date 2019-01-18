/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ppw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:25:52 by evogel            #+#    #+#             */
/*   Updated: 2019/01/18 12:51:58 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_malloc_c(size_t size, char c)
{
	char	*res;

	if (!(res = ft_strnew(size)))
		return (NULL);
	ft_memset(res, c, size);
	return (res);
}

/*
** Preci mallocs at new size filled with zeros
** copies res into new string at correct position, leving zeros in front
** puts back minus in front of all zeros if necessary
** When the number and precision both 0, res is empty
*/

int			set_preci(t_format *fmt)
{
	int		len;
	char	*tmp;

	len = ft_strlen(RES) - NEG;
	if (PRECI > len)
	{
		if (!(tmp = ft_malloc_c(PRECI + NEG, '0')))
			return (0);
		ft_strcpy(tmp + (PRECI - len) + NEG, RES + NEG);
		if (NEG)
			tmp[0] = '-';
		free(RES);
		RES = tmp;
	}
	else if (PRECI == 0 && RES[0] == '0')
	{
		if (!(tmp = ft_strnew(0)))
			return (0);
		free(RES);
		RES = tmp;
	}
	return (1);
}

/*
** Mallocs +1 or +2 depending on type of prefix needed
** copies back res with proper increment (1 or 2)
** then copies prefix:
** prefix of '+' or ' ' for non base numbers
** prefix of 0x for hex
*/

int			set_prefx(t_format *fmt)
{
	char	*tmp;
	int		add;

	add = (CONV == 'x' || CONV == 'p' ? 2 : 1);
	if (!(tmp = ft_malloc_c(ft_strlen(RES) + add, '0')))
		return (0);
	ft_strcpy(tmp + add, RES);
	if (CONV != 'x' && CONV != 'o' && CONV != 'p')
		tmp[0] = (PLUS ? '+' : ' ');
	else if (CONV == 'x' || CONV == 'p')
		tmp[1] = 'x';
	free(RES);
	RES = tmp;
	return (1);
}

/*
** When getting len, len is 1 for char conv
** Get correct char to fill spaces with: '0' or ' ' depending
** Create new string with filler char
** copy back original string following certain conditions:
** when copying in front, make sure str doesn't end early because of copied '\0'
** when '0' fill && prefix, copy at end without prefix then add prefix in front
** in all other cases, copy at end normally
*/

static int	zero_fill(t_format *fmt)
{
	if (CONV == 's' || CONV == 'c')
		return (0);
	else if (HASH && CONV == 'x')
		return (2);
	else if (CONV != 'x' && (PLUS || SPACE || NEG))
		return (1);
	return (0);
}

int			set_width(t_format *fmt)
{
	char	c;
	char	*tmp;
	int		len;
	int		add;

	len = (CONV == 'c' ? 1 : (int)ft_strlen(RES));
	c = (ZERO && !MINUS && !MID && (PRECI == -1 || CONV == 'f') ? '0' : ' ');
	c = (FILL ? FILL : c);
	if (!(tmp = ft_malloc_c(WIDTH, c)))
		return (0);
	if (MID == 1)
		ft_memcpy(tmp + (WIDTH / 2) - (len / 2), RES, len);
	else if (MINUS && ft_memcpy(tmp, RES, len))
		tmp[len] = c;
	else if (c == '0' && (add = zero_fill(fmt)))
	{
		ft_memcpy(tmp + (WIDTH - len) + add, RES + add, len);
		tmp[add - 1] = RES[add - 1];
	}
	else
		ft_memcpy(tmp + (WIDTH - len), RES, len);
	free(RES);
	RES = tmp;
	return (1);
}
