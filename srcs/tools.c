/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:25:52 by evogel            #+#    #+#             */
/*   Updated: 2019/01/14 19:26:51 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*int		error_1(void)
{
	ft_putstr("\n\terror: wrong conversion format\n");
	ft_putstr("\t%[flags][width][.precision][length_mod]conv_char\n\t");
	ft_putstr("supported flags: 0+- #\n\tsupportted conv_chars: diouxXcspfb\n");
	return (0);
}

int		error_2(void)
{
	ft_putstr("\nerror: ft_printf failed, check arguments\n\t");
	return (0);
}*/

char	*ft_malloc_c(size_t size, char c)
{
	char	*res;

	if (!(res = ft_strnew(size)))
		return (NULL);
	ft_memset(res, c, size);
	return (res);
}

int		set_preci(t_format *fmt)
{
	int		len;
	char	*tmp;

	len = ft_strlen(RES) - NEG;
	if (PRECI > len)
	{
		if (!(tmp = ft_malloc_c(PRECI + NEG, '0'))) //malloc new size filled with 0
			return (0);
		ft_strcpy(tmp + (PRECI - len) + NEG, RES + NEG); //copy res int new string with correct increment
		if (NEG == 1)
			tmp[0] = '-'; //copy back the minus in front if there was one
		free(RES);
		RES = tmp;
	}
	else if (PRECI == 0 && RES[0] == '0') //when num & preci both 0, res is empty
	{
		if (!(tmp = ft_strnew(0)))
			return (0);
		free(RES);
		RES = tmp;
	}
	return (1);
}

int		set_prefx(t_format *fmt)
{
	char	*tmp;
	int		add;

	add = (CONV == 'x' || CONV == 'p' ? 2 : 1);
	if (!(tmp = ft_malloc_c(ft_strlen(RES) + add, '0'))) //rejoute soit 1 ou 2 zeros devant
		return (0);
	ft_strcpy(tmp + add, RES); //recopie res avec correct increment
	if (CONV != 'x' && CONV != 'o' && CONV != 'p') //+ or space prefix for non base numbers
		tmp[0] = (PLUS ? '+' : ' ');
	else if (CONV == 'x' || CONV == 'p') //for hexa replace second 0 with x to make 0x
		tmp[1] = 'x';
	free(RES);
	RES = tmp;
	return (1);
}

int		set_width(t_format *fmt)
{
	char	c;
	char	*tmp;
	int		len;
	int		add;

	len = (CONV == 'c' ? 1 : (int)ft_strlen(RES)); //explicitly set len to 1 for chars
	c = (ZERO == 1 && MINUS == 0 && (PRECI == -1 || CONV == 'f') ? '0' : ' '); //find char to fill width space
	if (!(tmp = ft_malloc_c(WIDTH, c))) //make new string with filler char
		return (0);
	if (MINUS == 1 && ft_memcpy(tmp, RES, len))
		tmp[len] = c; //when copying in front with '-' flag, write over final '\0' to not end string early
	else if (c == '0' && CONV != 's' && CONV != 'c' //with flag zero, ignoring c and s converters
			&& (PLUS == 1 || SPACE == 1 || NEG == 1 || RES[1] == 'x')) //and if there is a prefix, copy it in front
	{
		add = (RES[1] == 'x' && len > 1 ? 1 : 0);
		ft_strcpy(tmp + (WIDTH - len) + 1 + add, RES + 1 + add);
		tmp[add] = RES[add];
	}
	else
		ft_memcpy(tmp + (WIDTH - len), RES, len); //otherwise copy at the end normally
	free(RES);
	RES = tmp;
	return (1);
}
