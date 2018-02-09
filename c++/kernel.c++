#include <libk.h>

Terminal term;

extern "C" void kernel_main(void)
{
	term.enableCursor(1, 15);
	putstr_color("Hello, kernel World!\n", VGA_COLOR_CYAN);

	char c;
	while (1)
	{
		c = getchar();
		putchar(c);
		if (c == 'x')
			term.disableCursor();
	}
}
