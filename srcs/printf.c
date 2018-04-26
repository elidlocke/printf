/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 18:59:53 by enennige          #+#    #+#             */
/*   Updated: 2018/04/25 16:53:55 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
	else if (arg_struct.type == is_wchar || arg_struct.type == is_wstring)
		str_size = ft_putwstr(arg_struct.wstr);
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
			chars_printed += write_arg(arg_struct);
			free_struct(&arg_struct);
		}
		else
		{
			chars_printed += ft_putstr(input_chunk);	
		}
		free(input_chunk);
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
