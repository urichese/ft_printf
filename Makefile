LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		sources/ft_processes.c \
		sources/ft_process_width.c \
		sources/ft_u_itoa.c \
		sources/ft_ull_base.c \
		sources/ft_putchar.c \
		sources/ft_str_tolower.c \
		sources/ft_process_string.c \
		sources/ft_process_char.c \
		sources/ft_process_pointer.c \
		sources/ft_process_int.c \
		sources/ft_process_uint.c \
		sources/ft_process_percent.c \
		sources/ft_process_hexa.c \
		sources/ft_process_flags.c

SURPL_O = 	ft_process_width.o \
			ft_processes.o \
			ft_process_width.o \
			ft_u_itoa.o \
			ft_ull_base.o \
			ft_putchar.o \
			ft_str_tolower.o \
			ft_process_string.o \
			ft_process_char.o \
			ft_process_pointer.o \
			ft_process_int.o \
			ft_process_uint.o \
			ft_process_percent.o \
			ft_process_hexa.o \
			ft_process_flags.o

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS) libft.a
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O)
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all