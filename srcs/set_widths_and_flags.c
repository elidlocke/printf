/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_widths_and_flags.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:54:39 by enennige          #+#    #+#             */
/*   Updated: 2018/04/24 22:32:23 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	set_flags(char **str_var, t_arg *parg_struct)
{
	printf("I AM HERE");
	while (**str_var == '#' || **str_var == '0' || **str_var == '-' ||
			**str_var == '+' || **str_var == ' ')
	{
		if (**str_var == '#')
			parg_struct->flags->has_hashflag = 1;
		else if (**str_var == '0')
			parg_struct->flags->has_zeroflag = 1;
		else if (**str_var == '-')
			parg_struct->flags->has_minusflag = 1;
		else if (**str_var == '+')
			parg_struct->flags->has_plusflag = 1;
		else if (**str_var == ' ')
			parg_struct->flags->has_spaceflag = 1;
		(*str_var)++;
	}
}

void	set_fieldwidth(char **str_var, t_arg *parg_struct)
{
	char	num_str[12];
	int		ni;

	if (**str_var >= '0' && **str_var <= '9')
	{
		ni = 0;
		while (**str_var >= '0' && **str_var <= '9')
		{
			num_str[ni] = **str_var;
			(*str_var)++;
			ni++;
		}
		num_str[ni] = '\0';
		parg_struct->fieldwidth = ft_atoi(num_str);
	}
}

void	set_precision(char **str_var, t_arg *parg_struct)
{
	char	num_str[12];
	int		ni;

	if (**str_var == '.')
	{
		(*str_var)++;
		if (**str_var >= '0' && **str_var <= '9')
		{
			ni = 0;
			while (**str_var >= '0' && **str_var <= '9')
			{
				num_str[ni] = **str_var;
				(*str_var)++;
				ni++;
			}
			num_str[ni] = '\0';
			parg_struct->precision = ft_atoi(num_str);
		}
		else
			parg_struct->precision = 0;
	}
	while ((**str_var == '.')
			|| (**str_var > '0' && **str_var <= '9'))
		(*str_var)++;
}

void	clean_flags(t_arg *parg_struct)
{
	if (parg_struct->flags->has_spaceflag && parg_struct->flags->has_plusflag)
		parg_struct->flags->has_spaceflag = 0;
	if (parg_struct->flags->has_zeroflag && parg_struct->flags->has_minusflag)
		parg_struct->flags->has_zeroflag = 0;
	if (parg_struct->flags->has_zeroflag && parg_struct->precision != -1)
		parg_struct->flags->has_zeroflag = 0;
	if (parg_struct->flags->has_zeroflag && parg_struct->precision != -1)
		parg_struct->flags->has_zeroflag = 0;
}
