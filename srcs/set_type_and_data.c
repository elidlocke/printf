/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settypeanddata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:54:52 by enennige          #+#    #+#             */
/*   Updated: 2018/04/30 10:20:53 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	set_type(t_arg *parg_struct)
{
	char s;
	char *m;

	s = parg_struct->specifier;
	m = parg_struct->modifiers;
	if (ft_strchr("di", s))
		parg_struct->type = is_snum;
	else if (ft_strchr("dDioOuUxXbBp", s))
		parg_struct->type = is_unum;
	else if (s == 'C' || (m  && s == 'c' && ft_countletter(m, 'l') == 1))
		parg_struct->type = is_wchar;
	else if (s == 'S' || (m && s == 's' && ft_countletter(m, 'l') == 1))
		parg_struct->type = is_wstring;
	else if (s == 'c')
		parg_struct->type = is_char;
	else if (s  == 's')
		parg_struct->type = is_string;
	else if (s == '%' || (ft_strchr(CONVERSIONS, s) == NULL
		 && ft_isalpha(s)))
			parg_struct->type = is_escape;
	else
		parg_struct->type = is_null;
}

void	set_snum(t_arg *parg_struct, va_list *args)
{
	intmax_t	snum;
		
	if (!parg_struct->modifiers)
		snum = va_arg(*args, int);
	else if (ft_countletter(parg_struct->modifiers, 'j') == 1 ||
			ft_countletter(parg_struct->modifiers, 'z') == 1)
		snum = va_arg(*args, intmax_t);
	else if (ft_countletter(parg_struct->modifiers, 'l') == 2)
		snum = va_arg(*args, long long);
	else if (ft_countletter(parg_struct->modifiers, 'l') == 1)
		snum = va_arg(*args, long);
	else if (ft_countletter(parg_struct->modifiers, 'h') == 2)
		snum = (char)va_arg(*args, int);
	else if (ft_countletter(parg_struct->modifiers, 'h') == 1)
		snum = (short)va_arg(*args, int);
	else
		snum = va_arg(*args, intmax_t);
	parg_struct->data = &snum;
	set_is_negative(parg_struct);
	parg_struct->str = ft_itoabase_umax(snum, parg_struct->base);
}

void	set_unum(t_arg *parg_struct, va_list *args)
{
	size_t	unum;

	if (parg_struct->specifier == 'D' || parg_struct->specifier == 'O' ||
		parg_struct->specifier == 'U' || parg_struct->specifier == 'p')
		unum = va_arg(*args, size_t);
	else if (!parg_struct->modifiers)
		unum = va_arg(*args, unsigned int);
	else if (ft_countletter(parg_struct->modifiers, 'z') == 1)
		unum = va_arg(*args, size_t);
	else if (ft_countletter(parg_struct->modifiers, 'l') == 1)
		unum = va_arg(*args, unsigned long);
	else if (ft_countletter(parg_struct->modifiers, 'h') == 2)
		unum = (unsigned char)va_arg(*args, int);
	else if (ft_countletter(parg_struct->modifiers, 'h') == 1)
		unum = (unsigned short)va_arg(*args, int);
	else
		unum = va_arg(*args, size_t);
	parg_struct->data = &unum;
	set_base(parg_struct);
	parg_struct->str = ft_itoabase_umax(unum, parg_struct->base);
}

void	set_string(t_arg *parg_struct, va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	parg_struct->data = str;
	if (str)
		parg_struct->str = ft_strdup(str);
}

void	set_char(t_arg *parg_struct, va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	parg_struct->data = &c;
	if (c)
		parg_struct->str = ft_chrtostr(c);
}

void	set_wstring(t_arg *parg_struct, va_list *args)
{
	void *wstr;

	wstr = va_arg(*args, wchar_t *);
	parg_struct->data = wstr;
	if (wstr)
		parg_struct->wstr = ft_wstrdup(wstr);
}

void	set_wchar(t_arg *parg_struct, va_list *args)
{
	wchar_t wc;

	wc = va_arg(*args, wchar_t);
	parg_struct->data = &wc;
	if (wc)
		parg_struct->wstr = ft_wchrtostr(wc);
}

void	set_escape(t_arg *parg_struct, va_list *args)
{
	char	c;
	(void)args;
	c = parg_struct->specifier;
	parg_struct->data = &c;
	if (c)
		parg_struct->str = ft_chrtostr(c);
}

void	set_data(t_arg *parg_struct, va_list *args)
{
	void    (*set_datatype[num_types])(t_arg *, va_list *);
	
	set_datatype[is_snum] = set_snum;
	set_datatype[is_unum] = set_unum;
	set_datatype[is_char] = set_char;
	set_datatype[is_string] = set_string;
	set_datatype[is_wchar] = set_wchar;
	set_datatype[is_wstring] = set_wstring;
	set_datatype[is_escape] = set_escape;
	set_datatype[parg_struct->type](parg_struct, args);
}
