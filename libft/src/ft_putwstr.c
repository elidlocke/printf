/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:43:05 by enennige          #+#    #+#             */
/*   Updated: 2018/04/25 16:46:12 by enennige         ###   ########.fr       */
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
		size = ft_wstrlen(ws);
		write(1, ws, size);
		return (size);
	}	

	return (0);
}
