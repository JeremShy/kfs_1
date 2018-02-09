#include <libk.h>
#include <stdarg.h>

Terminal term;

extern "C" void kernel_main(void)
{
	char	line[4096];
	term.enableCursor(1, 15);
	putstr_color("Hello, kernel World!\n", VGA_COLOR_CYAN);

	char c;
	while (1)
	{
		c = getchar();
		printk("%c", c);
		if (c == 'x')
			term.disableCursor();
	}
}
