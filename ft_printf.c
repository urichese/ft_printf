#include "ft_printf.h"

int	ft_process_str(const char *str, va_list args)
{
	int			i;
	t_flags		flags;
	int			char_count;

	i = 0;
	char_count = 0;
	while (1)
	{
		flags = ft_init_flags();
		if (!str[i])
			break ;
		else if (str[i] == '%' && str[i + 1])
		{
			i = ft_parse_flag(str, ++i, &flags, args);
			if (ft_is_in_type_list(str[i]))
				char_count += ft_process((char)flags.type, flags, args);
			else if (str[i])
				char_count += ft_putchar(str[i]);
		}
		else if (str[i] != '%')
			char_count += ft_putchar(str[i]);
		i++;
	}
	return (char_count);
}

int	ft_printf(const char *s, ...)
{
	const char	*str;
	va_list		args;
	int			char_count;

	str = ft_strdup(s);
	char_count = 0;
	va_start(args, s);
	char_count += ft_process_str(str, args);
	va_end(args);
	free((char *)str);
	return (char_count);
}
