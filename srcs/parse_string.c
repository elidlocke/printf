/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:35:07 by enennige          #+#    #+#             */
/*   Updated: 2018/04/25 14:48:04 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** Gets the length until a specific character
*/

int		get_lenuntil(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

/*
** Gets the length until one of the specifier characters, or the %.
** Meant to be used to see how long a variable starting with % is.
*/

int		get_varlen(char *str)
{
	int i;

	i = 1;
	while (ft_strchr(FLAGS, str[i]) || ft_strchr(DIGITS, str[i])
			|| str[i] == PRECISION_SEPERATOR || ft_strchr(MODIFIERS, str[i]))
	{
		i++;
	}
	if (str[i] != '\0')
		i += 1;
	return (i);
}

/*
** Given a string, get_nextchunk() gets the next chunk of input, and forwards
** the string to the first character after the returned chunk.
** Note: a chunk of input is defined as either a string before a % symbol, a
** string that contains a variable aka %#0.5llx or a string after a variable is
** over.
*/

char	*parse_string(char **str)
{
	int		str_len;
	char	*str_chunk;

	str_len = 0;
	if (**str == '\0')
		return (0);
	else if (**str == '%')
	{
		str_len = get_varlen(*str);
	}
	else
	{
		str_len = get_lenuntil(*str, '%');
	}
	if ((str_chunk = ft_strsub(*str, 0, str_len)))
	{
		*str += str_len;
		return (str_chunk);
	}
	return (0);
}
