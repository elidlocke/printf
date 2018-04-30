/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 12:07:12 by enennige          #+#    #+#             */
/*   Updated: 2018/04/30 10:01:56 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strdup mallocs a new string from a char
*/

#include "libft.h"

char	*ft_chrtostr(char c)
{
	char	*str;

	str = malloc(sizeof(*str) * (2));
	if (str)
	{
		str[0] = c;
		str[1] = '\0';
	}
	return (str);
}
