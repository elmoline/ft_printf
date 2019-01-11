/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:25:52 by evogel            #+#    #+#             */
/*   Updated: 2019/01/09 15:56:22 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_malloc_c(size_t size, char c)
{
	char	*res;
	size_t	i;

	if (!(res = ft_strnew(size)))
		return (NULL);
	i = 0;
	while (i < size)
		res[i++] = c;
	res[size] = '\0';
	return (res);
}

char	*set_preci(int preci, char *res)
{
	int		len;
	char	*tmp;
	int		add;

	add = (res[0] == '-' ? 1 : 0);
	len = ft_strlen(res) - add;
	if (preci > len)
	{
		tmp = ft_malloc_c(preci + add, '0');
		ft_strcpy(tmp + (preci - len) + add, res + add);
		if (add == 1)
			tmp[0] = '-';
		free(res);
		res = tmp;
	}
	else if (preci == 0 && res[0] == '0')
	{
		tmp = ft_strnew(0);
		free(res);
		res = tmp;
	}
	return (res);
}

char	*set_prefix(char *res, t_flags *flag)
{
	char	*tmp;
	char	c;
	int		add;

	c = flag->c;
	add = (c == 'd' || c == 'i' || c == 'o' || c == 'f' ? 1 : 2);
	tmp = ft_malloc_c(ft_strlen(res) + add, '0');
	ft_strcpy(tmp + add, res);
	if (c == 'd' || c == 'i' || c == 'f')
		tmp[0] = (flag->p ? '+' : ' ');
	else if (c != 'o')
		tmp[1] = (c == 'X' ? c : 'x');
	free(res);
	res = tmp;
	return (res);
}

char	*set_width(int width, char *res, t_flags *flag)
{
	char	c;
	char	*tmp;
	int		len;
	int		add;

	len = (flag->c != 'c' ? (int)ft_strlen(res) : 1);
	c = (flag->z == 1 && flag->m == 0 && (flag->preci == -1 || flag->c == 'f') ? '0' : ' ');
	tmp = ft_malloc_c(width, c);
	if (flag->m == 1 && (ft_memcpy(tmp, res, len)))
		tmp[len] = c;
	else if (c == '0' && flag->c != 's' && flag->c != 'c'
			&& ((ft_isdigit(res[0]) == 0 && flag->c != 'x' && flag->c != 'X')
				|| flag->hs == 1))
	{
		add = ((flag->c == 'x' || flag->c == 'X') && len > 1 ? 1 : 0);
		ft_strcpy(tmp + (width - len) + 1 + add, res + 1 + add);
		tmp[add] = res[add];
	}
	else
		ft_memcpy(tmp + (width - len), res, len);
	free(res);
	res = tmp;
	return (res);
}
