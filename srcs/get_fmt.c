/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:21:03 by evogel            #+#    #+#             */
/*   Updated: 2019/01/17 14:56:35 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		get_flag(char c, t_format *fmt)
{
	if (c == '#' && (HASH = 1))
		return (1);
	else if (c == '0' && (ZERO = 1))
		return (1);
	else if (c == '-' && (MINUS = 1))
		return (1);
	else if (c == '+' && (PLUS = 1))
		return (1);
	else if (c == ' ' && (SPACE = 1))
		return (1);
	else if (c == '_' && (FILL = (unsigned char)va_arg(AP, int)))
		return (1);
	else if (c == '|' && (MID  = 1))
		return (1);
	return (0);
}

static void		get_field(const char **format, t_format *fmt)
{
	int	*n;
	int	i;

	i = 1;
	if (**format == '.' && (*format)++)
	{
		n = &PRECI;
		*n = 0;
	}
	else
		n = &WIDTH;
	while (ft_isdigit(**format) == 1)
	{
		*n = *n * 10 + (**format - '0');
		(*format)++;
	}
	if (**format == '*' && (*format)++)
	{
		*n = va_arg(AP, int);
		if (*n < 0 && (MINUS = 1))
			*n = *n * -1;
	}
}

static void		get_length(const char **format, t_format *fmt)
{
	if (**format == 'l')
	{
		(*format)++;
		if (**format == 'l' && (*format)++)
			LL = 1;
		else
			L = 1;
	}
	else if (**format == 'h')
	{
		(*format)++;
		if (**format == 'h' && (*format)++)
			HH = 1;
		else
			H = 1;
	}
	else if (**format == 'L' && (*format)++)
		FL = 1;
}

static int		get_converter(const char **format, t_format *fmt)
{
	if (!ft_strchr(SUPP, **format) || **format == '\0')
		return (0);
	CONV = **format;
	(*format)++;
	if (ft_strchr(CAPS, CONV))
	{
		CAP = 1;
		CONV = CONV + 32;
	}
	if (ft_strchr(LLEN, CONV))
	{
		if (L == 1 && (LL = 1))
			L = 0;
		else 
			L = 1;
		CONV = CONV + 32;
	}
	return (1);
}

static void		get_base(t_format *fmt)
{
	if (CONV == 'o')
		ft_strcpy(BASE, "01234567");
	else if (CONV == 'x' || CONV == 'p')
		ft_strcpy(BASE, "0123456789abcdef");
	else if (CONV == 'b')
		ft_strcpy(BASE, va_arg(AP, char*));
	else 
		ft_strcpy(BASE, "0123456789");
}

/*
** Tout commence a zero (car memalloc)
** preci doit etre -1 parce qu'une precision de 0 existe
** Initialisation des strings des convertisseurs corespondant a un certain type
** Init de tableau de fonctions correspondant aux types
*/

static void		init_format(t_format *fmt)
{
	RES = NULL;
	PRECI = -1;
	ft_strcpy(SUPP, "%dDioOuUxXcCsSpfFbB");
	ft_strcpy(INTS, "dDi");
	ft_strcpy(UNSI, "oOuUxXpbB");
	ft_strcpy(STRI, "sS");
	ft_strcpy(CHAR, "cC%");
	ft_strcpy(FLOT, "fF");
	ft_strcpy(CAPS, "XCSB");
	ft_strcpy(LLEN, "DOUF");
	TREAT_TYPE[0] = &treat_int;
	TREAT_TYPE[1] = &treat_uns;
	TREAT_TYPE[2] = &treat_str;
	TREAT_TYPE[3] = &treat_chr;
	TREAT_TYPE[4] = &treat_flt;
}

/*
** get_format initialise la structure
** lis les flags
** puis la width
** puis la precision
** puis la taille de l'argument (l, hh, etc)
** puis le convertisseur
** et choisi une base selon le convertisseur
*/

t_format		*get_format(va_list *ap, const char **format)
{
	t_format	*fmt;

	if (!(fmt = (t_format*)ft_memalloc(sizeof(t_format))))
		return (NULL);
	fmt->ap = ap;
	init_format(fmt);
	while (get_flag(**format, fmt) == 1)
		(*format)++;
	get_field(format, fmt);
	get_field(format, fmt);
	get_length(format, fmt);
	if (!get_converter(format, fmt))
	{
		ft_memdel((void**)&fmt);
		return (NULL);
	}
	get_base(fmt);
	return (fmt);
}
