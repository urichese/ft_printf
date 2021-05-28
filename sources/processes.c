#include "../ft_printf.h"

int		ft_is_in_type_list(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int		ft_is_in_flags_list(int c)
{
	return ((c == '-') || (c == '0') || (c == '.') || (c == '*'));
}

t_flags		init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int		process(int c, t_flags flags, va_list args)
{
	int char_count;

	char_count = 0;
	if (c == 'c')
		char_count = process_char(va_arg(args, int), flags);
	else if (c == 's')
		char_count = process_string(va_arg(args, char *), flags);
	else if (c == 'p')
		char_count = process_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		char_count = process_int(va_arg(args, int), flags);
	else if (c == 'u')
		char_count += process_uint((unsigned int)va_arg(args, unsigned int),
	flags);
	else if (c == 'x')
		char_count += process_hexa(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		char_count += process_hexa(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		char_count += process_percent(flags);
	return (char_count);
}

int			parse_flag(const char *str, int i, t_flags *flags, va_list args)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_is_in_type_list(str[i])
			&& !ft_is_in_flags_list(str[i]))
			break ;
		if (str[i] == '0')
			*flags = flag_zero(*flags);
		if (str[i] == '.')
			i = flag_dot(str, i, flags, args);
		if (str[i] == '-')
			*flags = flag_minus(*flags);
		if (str[i] == '*')
			*flags = flag_width(args, *flags);
		if (ft_isdigit(str[i]))
			*flags = flag_digit(str[i], *flags);
		if (ft_is_in_type_list(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}