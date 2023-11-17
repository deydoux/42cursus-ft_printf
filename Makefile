NAME=libftprintf.a
SOURCES=ft_printf.c			\
		print_int.c			\
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

-include $(DEPENDENCIES)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJECTS)
	@$(MAKE) -C Libft
	cp Libft/libft.a $@
	$(AR) $(ARFLAGS) $@ $^

clean:
	@$(MAKE) $@ -C Libft
	$(RM) $(OBJECTS) $(DEPENDENCIES)

fclean:
	@$(MAKE) $@ -C Libft
	$(RM) $(OBJECTS) $(DEPENDENCIES) $(NAME)


re: fclean all

.PHONY: all clean fclean re
