/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_flag_modifications.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 10:34:08 by enennige          #+#    #+#             */
/*   Updated: 2018/04/30 10:45:03 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		get_zeroed_fieldlen(t_arg *parg_struct)
{
	int len;

	len = parg_struct->fieldwidth - ft_strlen(parg_struct->str);
	if (parg_struct->flags->has_spaceflag || parg_struct->flags->has_plusflag
		|| parg_struct->is_negative)
		len = len - 1;
	if (parg_struct->flags->has_hashflag && parg_struct->base == 8)
		len = len - 2;
	if (parg_struct->flags->has_hashflag && parg_struct->base == 16)
		len = len - 2;
	return (len);
}

void	manage_zeroed_fieldwidth(t_arg *parg_struct)
{
	int	len;

	if (parg_struct->fieldwidth != -1 && parg_struct->flags->has_zeroflag)
	{
		len = get_zeroed_fieldlen(parg_struct);
		if (len > 0)
		{
			ft_addnfix(&(parg_struct->str), '0', len, 1);
		}
	}
}

void	manage_hash(t_arg *arg_struct)
{
	char *tmp;

	tmp = arg_struct->str;
	if (arg_struct->flags->has_hashflag)
	{
		if (arg_struct->base == 16 && (*(size_t *)arg_struct->data != 0
			|| arg_struct->specifier == 'p'))
		{
			if ((arg_struct->str = ft_strjoin("0x", tmp)))
				free(tmp);
		}
		else if (arg_struct->base == 8 && *(size_t *)arg_struct->data != 0)
		{
			if ((arg_struct->str = ft_strjoin("0", tmp)))
				free(tmp);
		}
	}
}

void	manage_sign(t_arg *parg_struct)
{
	if (parg_struct->specifier == 'd' || parg_struct->specifier == 'i')
	{
		if (parg_struct->is_negative)
			ft_addnfix(&(parg_struct->str), '-', 1, 1);
		else if (parg_struct->flags->has_spaceflag)
			ft_addnfix(&(parg_struct->str), ' ', 1, 1);
		else if (parg_struct->flags->has_plusflag)
			ft_addnfix(&(parg_struct->str), '+', 1, 1);
	}
}
