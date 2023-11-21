NAME=libftprintf.a
SOURCES=ft_printf.c			\
		print_char.c		\
		print_ptr.c			\
		print_signed.c		\
		print_str.c			\
		print_unsigned.c	\
		get_flags.c

OBJECTS=$(SOURCES:.c=.o)
DEPENDENCIES=$(SOURCES:.c=.d)

CC=cc
CFLAGS=-Wall -Wextra -Werror -MMD
AR=ar
ARFLAGS=-c -r -s
RM=rm -f

all: $(NAME)
	@$(MAKE) --no-print-directory -C Libft

bonus: all

-include $(DEPENDENCIES)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJECTS)
	cp Libft/libft.a $(NAME)
	$(AR) $(ARFLAGS) $@ $^

clean:
	@$(MAKE) $@ -C Libft
	$(RM) $(OBJECTS) $(DEPENDENCIES)

fclean:
	@$(MAKE) $@ -C Libft
	$(RM) $(OBJECTS) $(DEPENDENCIES) $(NAME)


re: fclean all

.PHONY: all bonus clean fclean re
