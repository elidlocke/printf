/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:43:05 by enennige          #+#    #+#             */
/*   Updated: 2018/04/25 17:23:03 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_putwstr() function outputs a string to the standard output.
*/

int		ft_putwstr(wchar_t *ws)
{
	int	size;
	if (ws)
	{
		size = 0;
		while (ws[size] != L'\0')
		{
			write(1, &ws[size], 1);
			size++;
		}
		return (size);
	}
	return (0);
}
