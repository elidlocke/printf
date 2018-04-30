/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:09:49 by enennige          #+#    #+#             */
/*   Updated: 2018/04/25 17:47:35 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** The ft_wstrdup() function allocates sufficient memory for a copy of the
** wide string wstr, does the copy, and returns a pointer to it.  The pointer
** may subsequently be used as an argument to the function free(3). If
** insufficient memory is available, NULL is returned
*/

wchar_t	*ft_wstrdup(const wchar_t *wstr)
{
	size_t	len;
	wchar_t	*wstr_copy;
	int		i;

	len = ft_wstrlen(wstr);
	wstr_copy = malloc(sizeof(*wstr_copy) * (len + 1));
	if (wstr_copy)
	{
		i = 0;
		while (wstr[i] != L'\0')
		{
			wstr_copy[i] = wstr[i];
			i++;
		}
		wstr_copy[i] = L'\0';
	}
	return (wstr_copy);
}
