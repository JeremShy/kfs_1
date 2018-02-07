#include <libk.h>

void putstr(const char* data)
{
	terminal_write(data, strlen(data));
}
