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

C++_FLAGS= -fno-builtin -fno-exceptions -fno-stack-protector -fno-rtti -nostdlib -nodefaultlibs

C++_SRC = $(addprefix $(C++_PATH),$(C++_SRC_NAME))
ASM_SRC = $(addprefix $(ASM_PATH),$(ASM_SRC_NAME))

C++_OBJ = $(addprefix $(C++_OBJ_PATH),$(C++_OBJ_NAME))
ASM_OBJ = $(addprefix $(ASM_OBJ_PATH),$(ASM_OBJ_NAME))

OBJ = $(C++_OBJ) $(ASM_OBJ)

all: $(NAME)

$(NAME) : $(OBJ)
	$(LD) -o $(BIN_NAME) $^ $(C++_FLAGS) -lgcc
	mkdir -p isodir/boot/grub
	cp $(BIN_NAME) isodir/boot/$(BIN_NAME)
	grub-mkrescue -o $(ISO_NAME) isodir


$(C++_OBJ_PATH)%.o: $(C++_SRC_PATH)%.c++
	$(C++) $(C++_FLAGS) -c $< -o $@

$(ASM_OBJ_PATH)%.o: $(ASM_SRC_PATH)%.s
	$(ASM) $< -o $@

clean:
	rm -fv $(OBJ)

fclean: clean
	rm -fv $(OBJ)
	rm -fv $(BIN_NAME)
	rm -fv $(ISO_NAME)

test: all
	kvm -m 256 -cdrom $(ISO_NAME) -curses

re: fclean all
