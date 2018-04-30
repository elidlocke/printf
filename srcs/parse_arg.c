/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:08:25 by enennige          #+#    #+#             */
/*   Updated: 2018/04/30 11:03:16 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_arg	parse_arg(char *input_chunk, va_list *args)
{
	t_arg	arg_struct;

	initialize_struct(&arg_struct);
	set_struct(input_chunk, &arg_struct, args);
	apply_widths_and_flags(&arg_struct);
	return (arg_struct);
}
