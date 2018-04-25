/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:17:56 by enennige          #+#    #+#             */
/*   Updated: 2018/04/25 16:30:14 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_wstrlen (const wchar_t *s)
{
	size_t len;
	
	len = 0;
	while (s[len] != L'\0')
	{
		if (s[++len] == L'\0')
			return len;
		if (s[++len] == L'\0')
			return len;
		if (s[++len] == L'\0')
			return len;
		++len;
	}
	return len;
}
