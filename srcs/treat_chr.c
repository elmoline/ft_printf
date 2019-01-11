/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 18:54:03 by evogel            #+#    #+#             */
/*   Updated: 2019/01/11 16:30:35 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int		treat_char(char c, t_flags *flag)
{
	char	*res;
	int		ret;

	if (flag->width > 1)
	{
		res = ft_strnew(1);
		res[0] = c;
		res = set_width(flag->width, res, flag);
		write(1, res, (ret = flag->width));
		free(res);
	}
	else
		write(1, &c, (ret = 1));
	return (ret);
}
