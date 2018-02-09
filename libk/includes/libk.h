#ifndef LIBK_H
# define LIBK_H

# include <terminal.h>
# include <types.h>
# include <inline.h>

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

extern Terminal term;

size_t strlen(const char* str);
void putstr(const char* data);
void putstr_color(const char *data, uint8_t color);
void putnbr(int c);
int	putchar(int c);

char getScancode();
char getchar();



// ASM functions
extern "C"
{
}
#endif
