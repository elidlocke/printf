/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:26:29 by enennige          #+#    #+#             */
/*   Updated: 2018/04/25 16:33:21 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_wstrdup mallocs a new wide string from a wide char
*/

wchar_t	*ft_wchrtostr(wchar_t wchar)
{
	wchar_t	*wstr;

	wstr = malloc(sizeof(*wstr) * (2));
	if (wstr)
	{
		wstr[0] = wchar;
		wstr[1] = L'\0';
	}
	return (wstr);
}
