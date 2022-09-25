NAME = matrix_rain
SRC_D = src
INC_D = inc
SRC_F = src/*.c
INC_H = inc/header.h
CFLAGS = clang -lncursesw
RM = rm -rf
all: clean $(NAME)

$(NAME):
	@$(CFLAGS) $(SRC_F) -o $@ -I $(INC_D)

clean:
	@$(RM) $(NAME)

uninstall: clean
	@$(RM) $(NAME)

reinstall: uninstall all

