/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:21:03 by evogel            #+#    #+#             */
/*   Updated: 2019/01/14 21:19:19 by evogel           ###   ########.fr       */
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
	return (0);
}

static void		get_field(const char **format, t_format *fmt, va_list *ap)
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
		*n = va_arg(*ap, int);
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
	return (1);
}

static void		get_base(va_list *ap, t_format *fmt)
{
	if (CONV == 'o')
		ft_strcpy(BASE, "01234567");
	else if (CONV == 'x' || CONV == 'p')
		ft_strcpy(BASE, "0123456789abcdef");
	else if (CONV == 'b')
		ft_strcpy(BASE, va_arg(*ap, char*));
	else 
		ft_strcpy(BASE, "0123456789");
}

static void		init_format(t_format *fmt)
{
	RES = NULL;
	PRECI = -1;
	ft_strcpy(SUPP, "%dDioOuUxXcCsSpfFbB");
	ft_strcpy(INTS, "di");
	ft_strcpy(UNSI, "ouxXpb");
	ft_strcpy(STRI, "s");
	ft_strcpy(CHAR, "c%");
	ft_strcpy(FLOT, "fF");
	ft_strcpy(CAPS, "DOUXCSFB");
	TREAT_TYPE[0] = &treat_int;
	TREAT_TYPE[1] = &treat_uns;
	TREAT_TYPE[2] = &treat_str;
	TREAT_TYPE[3] = &treat_chr;
	TREAT_TYPE[4] = &treat_flt;
}

/*void			print_format(t_format *fmt)
{
	printf("res = [%s]\n", RES);
	printf("ret = [%d]\n", RET);
	printf("conv = [%c]\n", CONV);
	printf("supp = [%s]\n", SUPP);
	printf("ints = [%s]\n", INTS);
	printf("unsi = [%s]\n", UNSI);
	printf("stri = [%s]\n", STRI);
	printf("char = [%s]\n", CHAR);
	printf("flot = [%s]\n", FLOT);
	printf("caps = [%s]\n", CAPS);
	printf("width = [%d]\n", WIDTH);
	printf("preci = [%d]\n", PRECI);
	printf("hash = [%d]\n", HASH);
	printf("zero = [%d]\n", ZERO);
	printf("minus = [%d]\n", MINUS);
	printf("plus = [%d]\n", PLUS);
	printf("space = [%d]\n", SPACE);
	printf("l = [%d]\n", L);
	printf("ll = [%d]\n", LL);
	printf("h = [%d]\n", H);
	printf("hh = [%d]\n", HH);
	printf("L = [%d]\n", FL);
	printf("neg = [%d]\n", NEG);
	printf("cap = [%d]\n", CAP);
	printf("base = [%s]\n", BASE);
}*/

t_format		*get_format(va_list *ap, const char **format)
{
	t_format	*fmt;

	if (!(fmt = (t_format*)ft_memalloc(sizeof(t_format))))
		return (NULL);
	init_format(fmt);
	while (get_flag(**format, fmt) == 1)
		(*format)++;
	get_field(format, fmt, ap);
	get_field(format, fmt, ap);
	get_length(format, fmt);
	if (!get_converter(format, fmt))
	{
		ft_memdel((void**)&fmt);
		return (NULL);
	}
	get_base(ap, fmt);
//	print_format(fmt);
	return (fmt);
}
