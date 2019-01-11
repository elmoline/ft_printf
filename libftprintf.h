/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:57:17 by evogel            #+#    #+#             */
/*   Updated: 2019/01/11 15:54:53 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"

# include <strings.h>
# include <stdarg.h>
# include <stdlib.h>

# define LL_MAX 9223372036854775807
# define LL_MIN -9223372036854775808
# define ULL_MAX 18446744073709551615

typedef struct	s_flags
{
	int	hs;
	int	z;
	int	m;
	int	p;
	int	s;

	int	width;
	int	preci;

	int	h;
	int	hh;
	int	l;
	int	ll;
	int l_cap;

	int c;
}				t_flags;
/*
struct			s_convs
{
	char	supp[22] = "dDioOuUxXcspeEfFgG";
	char	d[3] = "dDi";
	char	u[6] = "oOuUxXp";
	char	s[1] = "s";
	char	c[1] = "c";
	char	f[2] = "efg";
	char	len_l[5] = "DOU";
	char	cap[5] = "XEFG";"
}

const char		base_conversions[5][2] = {
	{'d' , "0123456789"},
	{'i' , "0123456789"},
	{'o' , "01234567"},
	{'x' , "0123456789abcdef"},
	{'b' , "01"},
}
*/
int				ft_printf(const char *fmt, ...);

char			*ft_itoabase(unsigned long long n, char *base);

char			*ft_malloc_c(size_t size, char c);
int				dispatcher(va_list *ap, const char **fmt);
t_flags			*get_flags(const char **fmt, va_list *ap);
int				treat_type(va_list *ap, t_flags *flag);
int				treat_int(long long d, t_flags *flag);
int				treat_unsigned(unsigned long long u, t_flags *flag);
int				treat_char(char c, t_flags *flag);
int				treat_string(char *s, t_flags *flag);
int				treat_float(double f, t_flags *flag);
char			*set_preci(int preci, char *res);
char			*set_prefix(char *res, t_flags *flag);
char			*set_width(int width, char *res, t_flags *flag);

#endif
