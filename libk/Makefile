C++_SRC_NAME = putstr.c++ \
				strlen.c++ \
				terminal.c++ \
				scrollUp.c++ \
				putstr_color.c++

C++_OBJ_NAME = $(C++_SRC_NAME:.c++=.o)

ASM_SRC_NAME = # None
ASM_OBJ_NAME = $(ASM_SRC_NAME:.s=.o)

C++ = i686-elf-g++
ASM = i686-elf-as
LD = i686-elf-gcc -T linker.ld

C++_SRC_PATH = ./c++/
ASM_SRC_PATH = ./asm/

C++_OBJ_PATH = ./objc++/
ASM_OBJ_PATH = ./objasm/

NAME = ../libk.a

C++_FLAGS= -fno-builtin -fno-exceptions -fno-stack-protector -fno-rtti -nostdlib -nodefaultlibs

C++_SRC = $(addprefix $(C++_PATH),$(C++_SRC_NAME))
ASM_SRC = $(addprefix $(ASM_PATH),$(ASM_SRC_NAME))

C++_OBJ = $(addprefix $(C++_OBJ_PATH),$(C++_OBJ_NAME))
ASM_OBJ = $(addprefix $(ASM_OBJ_PATH),$(ASM_OBJ_NAME))

INCLUDES = ./
INCLUDE_FLAGS = $(addprefix -I ,$(INCLUDES))

OBJ = $(C++_OBJ) $(ASM_OBJ)

ccred = \033[0;31m
cccyan = \033[0;36m
ccgreen = \033[0;32m
ccend = \033[0m

all: $(NAME)

PRINT = a

$(NAME): $(OBJ)
	@ar r $(NAME) $^ >&- 2>&-
	@/bin/echo -e '$(ccred)'libk'$(ccend)': Compiled.'\n'

$(C++_OBJ_PATH)%.o: $(C++_SRC_PATH)%.c++
	@printf "$(ccred)libk$(ccend): Compiling...\n"
	@$(C++) $(C++_FLAGS) $(INCLUDE_FLAGS) -c $< -o $@
	@/bin/echo -e '$(ccred)'libk'$(ccend)':'\t''$(ccgreen)'[C]'$(ccend)' : $<

$(ASM_OBJ_PATH)%.o: $(ASM_SRC_PATH)%.s
	@$(ASM) $< -o $@
	@/bin/echo -e '$(ccred)'libk'$(ccend)':'\t''$(ccgreen)'[ASM]'$(ccend)' : $<

clean:
	@rm -fv $(OBJ)

fclean: clean
	@rm -fv $(NAME)

re: fclean all
