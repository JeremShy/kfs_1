#include <libk.h>

void putstr(const char* data)
{
	term.write(data, strlen(data));
}
