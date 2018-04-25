/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:03:09 by enennige          #+#    #+#             */
/*   Updated: 2018/04/25 14:04:03 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	set_base(t_arg *parg_struct)
{
	char specifier;

	specifier = parg_struct->specifier;
	if (specifier == 'x' || specifier == 'X' || specifier == 'p')
		parg_struct->base = 16;
	else if (specifier == 'b' || specifier == 'B')
		parg_struct->base = 2;
	else if (specifier == 'o' || specifier == 'O')
		parg_struct->base = 8;
}

void	set_is_negative(t_arg *parg_struct)
{
	char specifier;

	specifier = parg_struct->specifier;
	if ((specifier == 'd' || specifier == 'i') &&
		*(intmax_t *)parg_struct->data < 0)
	{
		parg_struct->is_negative = 1;
		*(intmax_t *)(parg_struct->data) *= -1;
	}
}
