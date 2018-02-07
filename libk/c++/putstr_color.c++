#include <libk.h>

void putstr_color(const char *data, uint8_t color)
{
	uint8_t oldcolor = terminal_color;

	terminal_setcolor(color);
	putstr(data);
	terminal_setcolor(oldcolor);
}
