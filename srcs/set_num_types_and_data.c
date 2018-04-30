/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_num_types_and_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 10:55:54 by enennige          #+#    #+#             */
/*   Updated: 2018/04/30 11:02:17 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	set_string(t_arg *parg_struct, va_list *args)
{
	char *str;

	str = va_arg(*args, char *);
	parg_struct->data = str;
	if (str)
		parg_struct->str = ft_strdup(str);
}

void	set_char(t_arg *parg_struct, va_list *args)
{
	char c;

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
