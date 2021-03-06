/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:46:29 by evogel            #+#    #+#             */
/*   Updated: 2019/01/17 13:39:03 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	set_preci_s(t_format *fmt)
{
	char	*tmp;
	int		len;

	len = (int)ft_strlen(RES);
	if (len > PRECI && PRECI >= 0)
	{
		if (!(tmp = ft_strnew(PRECI)))
			return (0);
		ft_strncpy(tmp, RES, PRECI);
		free(RES);
		RES = tmp;
	}
	return (1);
}

int			treat_str(t_format *fmt)
{
	if (!(RES = ft_strdup(va_arg(AP, char*))))
		RES = ft_strdup("(null)");
	if (!(set_preci_s(fmt)))
		return (0);
	if (WIDTH > (int)ft_strlen(RES))
		if (!(set_width(fmt)))
			return (0);
	if (CAP == 1)
		ft_capitalize(RES);
	RET = ft_strlen(RES);
	return (1);
}
