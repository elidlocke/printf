#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *restrict format, ...);

typedef	enum e_type {
	is_null,
	is_snum,
	is_unum,
	is_char,
	is_string,
	is_wchar,
	is_wstring,
	is_escape,
	num_types
} f_type;

typedef struct s_flag {
	int	has_spaceflag;
	int	has_hashflag;
	int	has_zeroflag;
	int	has_minusflag;
	int	has_plusflag;
} t_flag;

typedef	struct s_arg {
	f_type	type;
	t_flag	*flags;
	int		fieldwidth;
	int		precision;
	char	*modifiers;
	int		specifier;
	int		is_invalid;
	int		is_negative;
	int		base;
	void	*data;
	char	*str;
} t_arg;

char	*parse_string(char **str);
t_arg	parse_arg(char *input_chunk, va_list *args);

void    set_flags(char **str_var, t_arg *parg_struct);
void    set_fieldwidth(char **str_var, t_arg *parg_struct);
void    set_precision(char **str_var, t_arg *parg_struct);
void    set_modifiers(char **str_var, t_arg *parg_struct);
void    set_specifier(char **str_var, t_arg *parg_struct);
void    set_type(t_arg *parg_struct);
void    set_data(t_arg *parg_struct, va_list *ap);
void    clean_flags(t_arg *parg_struct);

void    set_base(t_arg *parg_struct);
void    set_is_negative(t_arg *parg_struct);

void	apply_widths_and_flags(t_arg *parg_struct);

void    initialize_struct(t_arg *argument);
void    set_struct(char *input_chunk, t_arg *parg_struct, va_list *args);

#define CONVERSIONS "sSpdDioOuUxXcCb%"
#define FLAGS "+- 0#"
#define PRECISION_SEPERATOR '.'
#define DIGITS "0123456789"
#define MODIFIERS "hljz"

#endif
