/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settypeanddata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:54:52 by enennige          #+#    #+#             */
/*   Updated: 2018/04/24 22:26:04 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	set_type(t_arg *parg_struct)
{
	char s;
	char *m;

	s = parg_struct->specifier;
	m = parg_struct->modifiers;
	if (ft_strchr("di", s) &&
			!(ft_countletter(m, 'z') == 1))
		parg_struct->type = is_snum;
	else if (ft_strchr("dDioOuUxXbBp", s))
		parg_struct->type = is_unum;
	else if (s == 'C' || (m  && s == 'c' && ft_countletter(m, 'l') == 1))
		parg_struct->type = is_wchar;
	else if (s == 'S' || 
			(m && s == 'c' && ft_countletter(m, 'l') == 1))
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

void	set_snum(t_arg *parg_struct, va_list *ap)
{
	intmax_t	pnum;
	
	if (!parg_struct->modifiers)
		pnum = va_arg(*ap, int);
	else if (ft_countletter(parg_struct->modifiers, 'j') == 1)
		pnum = va_arg(*ap, intmax_t);
	else if (ft_countletter(parg_struct->modifiers, 'l') == 2)
		pnum = va_arg(*ap, long long);
	else if (ft_countletter(parg_struct->modifiers, 'l') == 1)
		pnum = va_arg(*ap, long);
	else if (ft_countletter(parg_struct->modifiers, 'h') == 2)
		pnum = (char)va_arg(*ap, int);
	else if (ft_countletter(parg_struct->modifiers, 'h') == 1)
		pnum = (short)va_arg(*ap, int);
	else
		pnum = va_arg(*ap, intmax_t);
	parg_struct->data = &pnum;
}

void	set_unum(t_arg *parg_struct, va_list *ap)
{
	size_t	pnum;

	if (parg_struct->specifier == 'D' || parg_struct->specifier == 'O' ||
		parg_struct->specifier == 'U' || parg_struct->specifier == 'p')
		pnum = va_arg(*ap, size_t);
	else if (!parg_struct->modifiers)
		pnum = va_arg(*ap, unsigned int);
	else if (ft_countletter(parg_struct->modifiers, 'z') == 1)
		pnum = va_arg(*ap, size_t);
	else if (ft_countletter(parg_struct->modifiers, 'l') == 1)
		pnum = va_arg(*ap, unsigned long);
	else if (ft_countletter(parg_struct->modifiers, 'h') == 2)
		pnum = (unsigned char)va_arg(*ap, int);
	else if (ft_countletter(parg_struct->modifiers, 'h') == 1)
		pnum = (unsigned short)va_arg(*ap, int);
	else
		pnum = va_arg(*ap, size_t);
	parg_struct->data = &pnum;
}

void	set_string(t_arg *parg_struct, va_list *ap)
{
	char	*str;
	str = va_arg(*ap, char *);
	parg_struct->data = str;
}

void	set_char(t_arg *parg_struct, va_list *ap)
{
	char	c;
	c = (char)va_arg(*ap, int);
	parg_struct->data = &c;
}

void	set_escape(t_arg *parg_struct)
{
	char	c;
	c = parg_struct->specifier;
	parg_struct->data = &c;
}

void	set_data(t_arg *parg_struct, va_list *ap)
{
	if (parg_struct->type == is_escape)
		set_escape(parg_struct);
	else if (parg_struct->type == is_snum)
		set_snum(parg_struct, ap);
	else if (parg_struct->type == is_unum)
		set_unum(parg_struct, ap);
	else if (parg_struct->type == is_char)
		set_char(parg_struct, ap);
	else if (parg_struct->type == is_string)
		set_string(parg_struct, ap);
	/*
	else if (parg_struct->type == is_wchar)
		set_wchar(parg_struct);
	else if (parg_struct->type == is_wstring)
		set_wstring(parg_struct);
	*/
}
