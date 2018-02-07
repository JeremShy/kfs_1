C++_SRC_NAME = kernel.c++
C++_OBJ_NAME = $(C++_SRC_NAME:.c++=.o)

ASM_SRC_NAME = boot.s
ASM_OBJ_NAME = $(ASM_SRC_NAME:.s=.o)

C++ = i686-elf-g++
ASM = i686-elf-as
LD = i686-elf-gcc -T linker.ld

C++_SRC_PATH = ./c++/
ASM_SRC_PATH = ./asm/

C++_OBJ_PATH = ./objc++/
ASM_OBJ_PATH = ./objasm/

PRENAME = jcamhi_kernel
ISO_NAME = $(PRENAME).iso
BIN_NAME = $(PRENAME).bin
NAME = $(ISO_NAME)

C++_FLAGS = -fno-builtin -fno-exceptions -fno-stack-protector -fno-rtti -nostdlib -nodefaultlibs
C++_SRC = $(addprefix $(C++_PATH),$(C++_SRC_NAME))
ASM_SRC = $(addprefix $(ASM_PATH),$(ASM_SRC_NAME))

C++_OBJ = $(addprefix $(C++_OBJ_PATH),$(C++_OBJ_NAME))
ASM_OBJ = $(addprefix $(ASM_OBJ_PATH),$(ASM_OBJ_NAME))
OBJ = $(C++_OBJ) $(ASM_OBJ)

INCLUDES = ./libk
INCLUDE_FLAGS = $(addprefix -I ,$(INCLUDES))

ccred = \033[0;31m
cccyan = \033[0;36m
ccgreen = \033[0;32m
ccend = \033[0m

all: lib $(NAME)

$(NAME) : $(OBJ) libk.a
	$(LD) -o $(BIN_NAME) $(OBJ) $(C++_FLAGS) -L. -lk
	@/bin/echo -e '$(ccred)'kernel'$(ccend)': Compiled and linked.'\n'
	@mkdir -p isodir/boot/grub
	@cp $(BIN_NAME) isodir/boot/$(BIN_NAME)

	@/bin/echo -e Making a bootable cd...
	grub-mkrescue -o $(ISO_NAME) isodir
	@/bin/echo -e '$(ccgreen)'Everything ok '$(ccend)'

lib:
	@$(MAKE) --no-print-directory -C libk

$(C++_OBJ_PATH)%.o: $(C++_SRC_PATH)%.c++
	@/bin/echo -e '\r''$(ccred)'kernel'$(ccend)': Compiling...
	@$(C++) $(C++_FLAGS) $(INCLUDE_FLAGS) -c $< -o $@
	@/bin/echo -e '$(ccgreen)'[C]'$(ccend)' : $<

$(ASM_OBJ_PATH)%.o: $(ASM_SRC_PATH)%.s
	@$(ASM) $< -o $@
	@/bin/echo -e '$(cccyan)'[ASM]'$(ccend)' : $<

clean:
	@$(MAKE) -C libk --no-print-directory  clean
	@rm -fv $(OBJ)

fclean: clean
	@$(MAKE) -C libk --no-print-directory  fclean
	@rm -fv $(OBJ)
	@rm -fv $(BIN_NAME)
	@rm -fv $(ISO_NAME)
	@rm -fv isodir/boot/$(BIN_NAME)

test: all
	kvm -m 256 -cdrom $(ISO_NAME) -curses

re: fclean all
