/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <enennige@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 08:52:05 by enennige          #+#    #+#             */
/*   Updated: 2018/04/24 18:10:43 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putstr() function outputs a string to the standard output.
*/

#include "libft.h"

int		ft_putstr(char const *s)
{
	int	size;
	if (s)
	{
		size = ft_strlen(s);
		write(1, s, size);
		return (size);
	}	

	return (0);
}
