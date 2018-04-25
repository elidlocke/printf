/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:08:25 by enennige          #+#    #+#             */
/*   Updated: 2018/04/25 16:05:31 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** Temp function to print out the contents of a structure
*/
void    print_arg(t_arg arg_struct)
{
    printf("\n\n");
    printf("***FLAGS***\n");
    printf("has_spaceflag: %d\n", arg_struct.flags->has_spaceflag);
    printf("has_hashflag: %d\n", arg_struct.flags->has_hashflag);
    printf("has_zeroflag: %d\n", arg_struct.flags->has_zeroflag);
    printf("has_minusflag: %d\n", arg_struct.flags->has_minusflag);
    printf("has_plusflag: %d\n", arg_struct.flags->has_plusflag);
    printf("***WIDTHS***\n");
    printf("fieldwidth: %d\n", arg_struct.fieldwidth);
    printf("precision: %d\n", arg_struct.precision);
    printf("***LETTERS***\n");
    printf("modifiers: %s\n", arg_struct.modifiers);
    printf("specifier: %c\n", arg_struct.specifier);
    printf("***OPTIONS***\n");
    printf("is_invalid: %d\n", arg_struct.is_invalid);
    printf("is_negative: %d\n", arg_struct.is_negative);
    printf("base: %d\n", arg_struct.base);
    printf("***TYPE***\n");
    printf("type: %d\n", arg_struct.type);
    printf("***DATA***\n");
    if (arg_struct.type == is_unum)
        printf("data: %zu\n", *(size_t *)arg_struct.data);
    if (arg_struct.type == is_snum)
        printf("data: %jd\n", *(intmax_t *)arg_struct.data);
    else if (arg_struct.type == is_char)
        printf("data: %c\n", *(char *)arg_struct.data);
    else if (arg_struct.type == is_string)
        printf("data: %s\n", (char *)arg_struct.data);
    printf("\n\n");
    printf("STRING: %s\n", arg_struct.str);
    printf("\n\n");
}

t_arg	parse_arg(char *input_chunk, va_list *args)
{
	t_arg	arg_struct;

	initialize_struct(&arg_struct);
	set_struct(input_chunk, &arg_struct, args);
	apply_widths_and_flags(&arg_struct);
	//print_arg(arg_struct);

	return(arg_struct);
}
