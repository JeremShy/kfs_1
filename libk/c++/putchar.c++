#include <libk.h>

int	putchar(int c)
{
	term.putchar(c);
	return (c);
}
