/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:21:03 by evogel            #+#    #+#             */
/*   Updated: 2019/01/11 16:29:30 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		check_flag(char c, t_flags *flag)
{
	if (c == '#' && (flag->hs = 1))
		return (1);
	else if (c == '0' && (flag->z = 1))
		return (1);
	else if (c == '-' && (flag->m = 1))
		return (1);
	else if (c == '+' && (flag->p = 1))
		return (1);
	else if (c == ' ' && (flag->s = 1))
		return (1);
	return (0);
}

static void		check_field(const char **fmt, t_flags *flag, va_list *ap)
{
	int	*n;
	int	i;

	i = 1;
	if (**fmt == '.' && ++(*fmt))
	{
		n = &flag->preci;
		*n = 0;
	}
	else
		n = &flag->width;
	while (ft_isdigit(**fmt) == 1)
	{
		*n = *n * 10 + (**fmt - '0');
		++(*fmt);
	}
	if (**fmt == '*')
		*n = va_arg(*ap, int);
}

static void		check_length(const char **fmt, t_flags *flag)
{
	if (**fmt == 'l')
	{
		++(*fmt);
		if (**fmt == 'l' && ++(*fmt))
			flag->ll = 1;
		else
			flag->l = 1;
	}
	else if (**fmt == 'h')
	{
		++(*fmt);
		if (**fmt == 'h' && ++(*fmt))
			flag->hh = 1;
		else
			flag->h = 1;
	}
	else if (**fmt == 'L')
	{
		++(*fmt);
		flag->l_cap = 1;
	}
}

t_flags			*get_flags(const char **fmt, va_list *ap)
{
	t_flags	*flag;

	if (!(flag = (t_flags*)ft_memalloc(sizeof(t_flags))))
		return (NULL);
	flag->preci = -1;
	while (check_flag(**fmt, flag) == 1)
		++(*fmt);
	check_field(fmt, flag, ap);
	check_field(fmt, flag, ap);
	check_length(fmt, flag);
	return (flag);
}
