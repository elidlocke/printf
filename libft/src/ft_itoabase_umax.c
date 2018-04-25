/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase_umax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:39:15 by enennige          #+#    #+#             */
/*   Updated: 2018/04/23 17:36:56 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_unumlen(size_t num, int base)
{
	int	i;

	i = 1;
	while (num /= base)
		i++;
	return (i);
}

/*
** The ft_itoabase_umax() function takes an unsigned size_t number and
** converts it into a string, printed in the specified base
*/

char		*ft_itoabase_umax(size_t num, int base)
{
	char			*str;
	int				len;
	char			*basestr;

	basestr = ft_strdup("0123456789abcdef");
	len = get_unumlen(num, base);
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
	{
		return (NULL);
	}
	str[len] = '\0';
	str[--len] = basestr[num % base];
	while (num /= base)
	{
		str[--len] = basestr[num % base];
	}
	free(basestr);
	return (str);
}
