/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <enennige@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 08:46:44 by enennige          #+#    #+#             */
/*   Updated: 2018/04/24 14:28:32 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putchar() function outputs the character c to the standard output.
*/

#include "libft.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
