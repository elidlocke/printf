/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:43:05 by enennige          #+#    #+#             */
/*   Updated: 2018/04/30 10:22:41 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		big_to_little_endian(int c)
{
	return (((c >> 24) & 0xff) | ((c << 8) & 0xff0000) |
		((c >> 8) & 0xff00) | ((c << 24) & 0xff000000));
}

static int		get_mask(wint_t c, size_t *len)
{
	if (c <= 0x7FF)
	{
		*len = 2;
		return (0xC080);
	}
	else if (c <= 0xFFFF)
	{
		*len = 3;
		return (0xE08080);
	}
	else
	{
		*len = 4;
		return (0xF0808080);
	}
}

size_t	ft_putwchar(wint_t c)
{
	int		output;
	size_t	len;

	output = 0xF0808080;
	if (c <= 0x7F)
	{
		output = c & 127;
		len = 1;
	}
	else
	{
		output = get_mask(c, &len);
		output |= (((c >> 6) & 0x3F) << 8) | (c & 0x3F);
		if (c > 0x7FF)
			output |= (((c >> 12) & 0xF) << 16);
		if (c > 0xFFFF)
			output |= (((c >> 18) & 0x7) << 24);
	}
	output = big_to_little_endian(output);
	write(1, &output, sizeof(wchar_t));
	return (len);
}

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
