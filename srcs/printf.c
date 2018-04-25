/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 18:59:53 by enennige          #+#    #+#             */
/*   Updated: 2018/04/25 11:31:41 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


/*
** Temp function to print out the contents of a structure
*/
void	print_arg(t_arg arg_struct)
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

/*
** Writes the variable chunk and returns the size of chars written
*/
int		write_arg(t_arg arg_struct)
{
	int		str_size;

	if (arg_struct.type == is_char && arg_struct.str == NULL)
		str_size = ft_putchar(0);
	else if (arg_struct.type == is_string && arg_struct.str == NULL)
		str_size = ft_putstr("(null)");
	else if (arg_struct.is_invalid == 1)
		str_size = 0;
	else
		str_size = ft_putstr(arg_struct.str);
	return(str_size);
}

/*
** Gets the data & prints it
*/
int		get_and_print_data(char *fmt, va_list *args)
{
	int		chars_printed;
	char	*input_chunk;
	t_arg	arg_struct;

	//parse string
	chars_printed = 0;
	while ((input_chunk = parse_string(&fmt)))
	{
		if (input_chunk[0] == '%')
		{
			arg_struct = parse_arg(input_chunk, args);
			/* DEBUG */
			print_arg(arg_struct);
			/* END DEBUG */
			chars_printed += write_arg(arg_struct);
		}
		else
		{
			chars_printed += ft_putstr(input_chunk);	
		}
	}
	return (chars_printed);	
}

/*
** Modelled after the printf() function in C, ft_printf() takes a variable
** list of arguments and converts each variable into it's string
** representation and then prints the full string. See man 3 printf
*/

int     ft_printf(const char *restrict format, ...)
{
    va_list args;
    char    *fmt_copy;
    int     chars_printed;

    fmt_copy = ft_strdup(format);
    if (!fmt_copy)
        return (0);
    va_start(args, format);
    chars_printed = get_and_print_data(fmt_copy, &args);
    free(fmt_copy);
    va_end(args);
    return (chars_printed);}
