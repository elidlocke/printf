/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_smax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:24:24 by enennige          #+#    #+#             */
/*   Updated: 2018/04/15 19:08:42 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_snumlen(intmax_t num)
{
	int	i;

	i = 1;
	while (num /= 10)
		i++;
	return (i);
}

/*
** The ft_itoa_smax() function takes a number, which can be as large as
** intmax_t, and converts it into a string.
*/

char		*ft_itoa_smax(intmax_t num)
{
	char		*str;
	int			len;
	uintmax_t	tmp;

	len = get_snumlen(num);
	tmp = num;
	if (num < 0)
	{
		tmp = -num;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * len)))
	{
		return (NULL);
	}
	str[len] = '\0';
	str[--len] = tmp % 10 + '0';
	while (tmp /= 10)
		str[--len] = tmp % 10 + '0';
	if (num < 0)
		str[0] = '-';
	return (str);
}
