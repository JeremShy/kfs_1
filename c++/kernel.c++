#include <libk.h>

void putstr(const char* data)
{
	terminal_write(data, strlen(data));
}

void putstr_color(const char *data, uint8_t color)
{
	uint8_t oldcolor = terminal_color;

	terminal_setcolor(color);
	putstr(data);
	terminal_setcolor(oldcolor);
}

extern "C" void kernel_main(void)
{
	/* Initialize terminal interface */
	terminal_initialize();

	/* Newline support is left as an exercise. */
	putstr_color("Hello, kernel World!", VGA_COLOR_CYAN);
}
