/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:46:29 by evogel            #+#    #+#             */
/*   Updated: 2019/01/11 16:31:31 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*set_preci_s(char *res, int preci)
{
	char	*tmp;
	int		len;

	len = (int)ft_strlen(res);
	if (len > preci && preci > 0)
	{
		tmp = ft_strnew(preci);
		ft_strncpy(tmp, res, preci);
		free(res);
		res = tmp;
	}
	return (res);
}

int			treat_string(char *src, t_flags *flag)
{
	char	*res;
	int		ret;

	if (src)
		res = ft_strdup(src);
	else
		res = ft_strdup("(null)");
	res = set_preci_s(res, flag->preci);
	if (flag->width > (int)ft_strlen(res))
		res = set_width(flag->width, res, flag);
	ft_putstr(res);
	ret = ft_strlen(res);
	free(res);
	return (ret);
}
