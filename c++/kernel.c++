#include <libk.h>

extern "C" void kernel_main(void)
{
	terminal_initialize();

	putstr_color("Hello, kernel World!", VGA_COLOR_CYAN);
}
