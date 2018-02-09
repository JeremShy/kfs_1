#ifndef LIBK_H
# define LIBK_H

# include <terminal.h>
# include <types.h>
# include <inline.h>
# include <cursor.h>
# include <keyComb.h>

# define VGA_WIDTH 80
# define VGA_HEIGHT 25

// Thank you, GCC, that's nice.
typedef __builtin_va_list va_list;
# define va_start __builtin_va_start
# define va_end __builtin_va_end
# define va_arg __builtin_va_arg

extern Terminal term;

size_t strlen(const char* str);
void putstr(const char* data);
void putstr_color(const char *data, uint8_t color);
void putnbr(int c);
int	putchar(int c);

char getScancode();
KeyComb getKeyComb_down();

void printk(const char *s, ...);


// ASM functions
extern "C"
{
}
#endif
