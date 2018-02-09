#include <libk.h>

int	putchar(int c)
{
	terminal_putchar(c);
	return (c);
}
