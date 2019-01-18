/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:21:03 by evogel            #+#    #+#             */
/*   Updated: 2019/01/18 11:40:20 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Tout est set a zero dans memalloc
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
