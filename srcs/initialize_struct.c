/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:09:46 by enennige          #+#    #+#             */
/*   Updated: 2018/04/30 10:47:41 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_flag	*new_flags(void)
{
	t_flag *flags;

	flags = (t_flag *)malloc(sizeof(t_flag));
	if (!flags)
		return (NULL);
	flags->has_plusflag = 0;
	flags->has_spaceflag = 0;
	flags->has_hashflag = 0;
	flags->has_zeroflag = 0;
	flags->has_minusflag = 0;
	return (flags);
}

void	initialize_struct(t_arg *argument)
{
	argument->type = is_null;
	argument->flags = new_flags();
	argument->fieldwidth = -1;
	argument->precision = -1;
	argument->modifiers = NULL;
	argument->specifier = 0;
	argument->is_invalid = 0;
	argument->is_negative = 0;
	argument->base = 10;
	argument->data = NULL;
	argument->str = NULL;
	argument->wstr = NULL;
}

void	set_struct(char *input_chunk, t_arg *parg_struct, va_list *args)
{
	input_chunk++;
	set_flags(&input_chunk, parg_struct);
	set_fieldwidth(&input_chunk, parg_struct);
	set_precision(&input_chunk, parg_struct);
	set_modifiers(&input_chunk, parg_struct);
	set_specifier(&input_chunk, parg_struct);
	set_type(parg_struct);
	set_data(parg_struct, args);
	clean_flags(parg_struct);
}

void	free_struct(t_arg *parg_struct)
{
	free(parg_struct->flags);
	parg_struct->flags = NULL;
	if (parg_struct->modifiers)
	{
		free(parg_struct->modifiers);
		parg_struct->modifiers = NULL;
	}
	if (parg_struct->str)
	{
		free(parg_struct->str);
		parg_struct->str = NULL;
	}
}
