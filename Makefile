C++_SRC_NAME=kernel.c++
C++_OBJ_NAME=$(C++_SRC_NAME:.c++=.o)


ASM_SRC_NAME=boot.s
ASM_OBJ_NAME=$(ASM_SRC_NAME:.s=.o)

C++=i686-elf-g++
ASM=i686-elf-as
LD=i686-elf-gcc -T linker.ld

C++_PATH=./C++/
ASM_PATH=./ASM/

OBJ_PATH=./OBJ/

PRENAME=jcamhi_kernel

ISO_NAME=$(PRENAME).iso
BIN_NAME=$(PRENAME).bin

C++_FLAGS=-fno-builtin -fno-exception -fno-stack-protector -fno-rtti -nostdlib -nodefaultlibs

C++_SRC = $(addprefix $(C++_PATH), $(C++_SRC_NAME))
ASM_SRC = $(addprefix $(ASM_PATH), $(ASM_SRC_NAME))

C++_OBJ = $(addprefix $(C++_PATH), $(C++_OBJ_NAME))
ASM_OBJ = $(addprefix $(ASM_PATH), $(ASM_OBJ_NAME))

OBJ = $(C++_OBJ) $(ASM_OBJ)

all: $(NAME)

$(NAME) : $(OBJ)
	$(LD) -o $(NAME) $^ $(C++_FLAGS) -lgcc

$(OBJ_PATH)
