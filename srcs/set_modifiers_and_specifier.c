/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_modifiers_and_specifier.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:53:08 by enennige          #+#    #+#             */
/*   Updated: 2018/04/30 10:48:14 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	set_modifiers(char **str_var, t_arg *parg_struct)
{
	char	*modifiers;
	int		i;

	i = 0;
	modifiers = NULL;
	if (ft_strchr(MODIFIERS, **str_var) != NULL)
	{
		modifiers = malloc(sizeof(*str_var) + 1);
	}
	while (**str_var && ft_strchr(MODIFIERS, **str_var))
	{
		modifiers[i] = **str_var;
		(*str_var)++;
		i++;
	}
	if (modifiers)
	{
		modifiers[i] = '\0';
		parg_struct->modifiers = modifiers;
	}
}

void	set_specifier(char **str_var, t_arg *parg_struct)
{
	char	specifier;

	specifier = **str_var;
	if (!(ft_isalpha(specifier) || specifier == '%'))
		return ;
	(*str_var)++;
	parg_struct->specifier = specifier;
}
