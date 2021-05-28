#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef	struct		s_flags
{
	int				already_print;
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}					t_flags;

int					flag_dot(const char *save, int start,
								   t_flags *flags, va_list args);
t_flags				flag_zero(t_flags flags);
t_flags				flag_minus(t_flags flags);
t_flags				flag_width(va_list args, t_flags flags);
t_flags				flag_digit(char c, t_flags flags);



int		putstrprec(char *str, int prec);
char		*ft_ull_base(unsigned long long ull, int base);
char	*ft_str_tolower(char *str);
int		process_width(int width, int minus, int has_zero);

#endif