#include <libk.h>

void	Terminal::scrollUp()
{
	int	y;
	int	x;
	size_t	index;
	size_t	nindex;

	y = 0;
	while (y < VGA_HEIGHT - 1)
	{
		x = 0;
		while (x < VGA_WIDTH)
		{
			index = y * VGA_WIDTH + x;
			nindex = (y + 1) * VGA_WIDTH + x;
			terminal_buffer[index] = terminal_buffer[nindex];
			x++;
		}
		y++;
	}
}
