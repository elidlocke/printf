/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:43:05 by enennige          #+#    #+#             */
/*   Updated: 2018/04/30 10:24:13 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_putwstr() function outputs a string to the standard output.
*/

int		ft_putwstr(wchar_t *ws)
{
	int i;

	i = 0;
	while (ws[i] != '\0')
	{
		ft_putchar(ws[i]);
		i++;	
	}
	
	return (i);
	
}
