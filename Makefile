NAME = fractol

SRC = fractol.c \
	src/ft_init.c \
	src/ft_key_win.c \
	src/ft_catch_order.c \
	src/ft_mouse.c \
	src/ft_put_pixel.c \
	src/ft_check_argv.c \
	src/ft_draw_fractal.c \
	src/ft_mb.c \
	src/julia.c \
	src/ft_bsh.c

INCLUDES = -I/usr/local/include -I/usr/include

LIBOBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra
GLFLAGS = -lm -lmlx -framework OpenGL -framework AppKit

$(NAME): $(LIBOBJ)
		make -C ./libft
		gcc $(CFLAGS) $(LIBOBJ) -L./libft $(INCLUDES) $(GLFLAGS) -lft -o $(NAME)
%.o:%.c fractol.h keys.h
		gcc -MD -c $<  -o $@

all: $(NAME)


clean:
	make -C ./libft clean
	-rm -rf $(LIBOBJ)
	-rm -f src/*.d
	-rm -f libft/*.d
	-rm -f *.d

fclean: clean
	make -C ./libft fclean
	-rm -f $(NAME)
	-rm -f src/*.d
	-rm -f libft/*.d
	-rm -f *.d

re: fclean all
