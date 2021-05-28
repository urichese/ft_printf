#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
	int				already_print;
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}	t_flags;

int					ft_flag_dot(const char *save, int start,
						t_flags *flags, va_list args);
t_flags				ft_flag_zero(t_flags flags);
t_flags				ft_flag_minus(t_flags flags);
t_flags				ft_flag_width(va_list args, t_flags flags);
t_flags				ft_flag_digit(char c, t_flags flags);

int					ft_process_char(char c, t_flags flags);
int					ft_process_hexa(unsigned int ui, int lower, t_flags flags);
int					ft_process_int(int i, t_flags flags);
int					ft_process_percent(t_flags flags);
int					ft_process_pointer(unsigned long long ull, t_flags flags);
int					ft_process_string(char *str, t_flags flags);
int					ft_process_uint(unsigned int unsi, t_flags flags);

int					ft_putstrprec(char *str, int prec);
char				*ft_ull_base(unsigned long long ull, int base);
char				*ft_str_tolower(char *str);
int					ft_process_width(int width, int minus, int has_zero);
char				*ft_u_itoa(unsigned int n);

#endif