##
## EPITECH PROJECT, 2024
## MiniLibC
## File description:
## Makefile
##

AS 				= 	nasm

ASFLAGS 		= 	-f elf64

LINKER 			= 	ld

SRC				:=	$(shell find src/ -name "*.asm")

NAME			=	libasm.so

OBJ				=	$(SRC:.asm=.o)

SRC_TESTS  		:= $(shell find tests/ -name "*.c")

RUN_TEST		=	--coverage -lcriterion

NAME_TESTS		=	unit_tests

OBJ_TESTS		=	$(SRC:.c=.o)

CFLAGS			=	-W -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(LINKER) -fPIC -shared -o $(NAME) $(OBJ)

%.o: %.asm
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TESTS)

re: fclean all

unit_tests: re
	gcc -o $(NAME_TESTS) $(SRC_TESTS) $(NAME) $(CFLAGS) $(RUN_TEST) -ldl

tests_run: unit_tests
	LD_LIBRARY_PATH=. LD_PRELOAD=./libasm.so ./unit_tests

gcovr:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

.PHONY: all clean fclean re unit_tests tests_run gcovr
