#include <libk.h>

void putstr_color(const char *data, uint8_t color)
{
	uint8_t oldcolor = term.getColor();

	term.setColor(color);
	putstr(data);
	term.setColor(oldcolor);
}
