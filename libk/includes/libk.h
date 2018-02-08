#ifndef LIBK_H
# define LIBK_H

# include <types.h>
# include <inline.h>

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

extern size_t terminal_row;
extern size_t terminal_column;
extern uint8_t terminal_color;
extern volatile uint16_t* terminal_buffer;

size_t strlen(const char* str);
void putstr(const char* data);
void putstr_color(const char *data, uint8_t color);

void	scrollUp();
void terminal_initialize(void);
void terminal_setcolor(uint8_t color);
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);


// ASM functions
void outb(uint16_t port, uint8_t val);
#endif
