#include <libk.h>

extern "C" void kernel_main(void)
{
	terminal_initialize();

	putstr_color("Hello, kernel World!", VGA_COLOR_CYAN);

	char buffer[3] = "0\n";
	char c;

	while (1)
	{
		c = getchar();
		buffer[0] = c + '0';
		putstr(buffer);
	}
}
