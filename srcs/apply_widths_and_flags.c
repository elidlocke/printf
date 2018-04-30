/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_widths_and_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:53:29 by enennige          #+#    #+#             */
/*   Updated: 2018/04/30 10:43:07 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	manage_precision(t_arg *parg_struct)
{
	int		len;
	char	*str;

	if (parg_struct->precision != -1)
	{
		str = parg_struct->str;
		len = parg_struct->precision - ft_strlen(str);
		if (parg_struct->type == is_string && len < 0)
		{
			if ((parg_struct->str = ft_strndup(str, parg_struct->precision)))
				free(str);
		}
		else if (parg_struct->type == is_unum || parg_struct->type == is_snum)
		{
			if (parg_struct->precision == 0 && str[0] == '0' && str[1] == '\0')
				parg_struct->str[0] = '\0';
			else if (len > 0)
			{
				ft_addnfix(&(parg_struct->str), '0', len, 1);
			}
		}
	}
}

void	manage_fieldwidth(t_arg *arg_struct)
{
	int		len;
	char	*tmp;

	if (arg_struct->fieldwidth != -1 && arg_struct->flags->has_zeroflag == 0)
	{
		tmp = arg_struct->str;
		len = arg_struct->fieldwidth - ft_strlen(arg_struct->str);
		if (len > 0)
		{
			if (arg_struct->flags->has_minusflag)
			{
				ft_addnfix(&(arg_struct->str), ' ', len, 2);
			}
			else
			{
				ft_addnfix(&(arg_struct->str), ' ', len, 1);
			}
		}
	}
}

void	manage_case(t_arg *arg_struct)
{
	int i;

	if (arg_struct->specifier == 'X')
	{
		i = 0;
		while (arg_struct->str[i] != '\0')
		{
			arg_struct->str[i] = ft_toupper(arg_struct->str[i]);
			i++;
		}
	}
}

void	apply_widths_and_flags(t_arg *parg_struct)
{
	manage_precision(parg_struct);
	manage_zeroed_fieldwidth(parg_struct);
	manage_sign(parg_struct);
	manage_hash(parg_struct);
	manage_case(parg_struct);
	manage_fieldwidth(parg_struct);
}
