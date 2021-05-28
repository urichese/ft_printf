#include "../ft_printf.h"

int	putstrprec(char *str, int prec)
{
	int char_count;

	char_count = 0;
	while (str[char_count] && char_count < prec)
		ft_putchar(str[char_count++]);
	return (char_count);
}

static int	put_part_int(char *str, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.dot >= 0)
	{
		char_count += process_width(flags.dot, ft_strlen(str), 0);
		char_count += putstrprec(str, flags.dot);
	}
	else
	{
		char_count += putstrprec(str, ft_strlen(str));
	}
	return (char_count);
}

int	process_string(char *str, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		char_count += ft_put_part_int(str, flags);
	if (flags.dot >= 0)
		char_count += process_width(flags.width, flags.dot, 0);
	else
		char_count += process_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		char_count += ft_put_part_int(str, flags);
	return (char_count);
}
