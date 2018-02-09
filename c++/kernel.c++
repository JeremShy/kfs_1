#include <libk.h>

extern "C" void kernel_main(void)
{
	terminal_initialize();

	putstr_color("Hello, kernel World!\n", VGA_COLOR_CYAN);

	char c;
	while (1)
	{
		c = getchar();
		putchar(c);
		// putstr("\n");
	}
}
