
#include <libk.h>
#include <stdarg.h>

Terminal term;

extern "C" void kernel_main(void)
{
	char	line[4096];
	term.enableCursor(1, 12);
	putstr_color("Hello, kernel World!\n", VGA_COLOR_CYAN);

	while (1)
	{
		KeyComb comb = getKeyComb_down();
		if (comb.isAscii())
		{
			printk("Ascii : %d : %c\n", comb.getAscii(), comb.getAscii());
		}
		else
		{
			printk("Code : %d\n", comb.getCode());
		}
	}
}
