#include <libk.h>
// char getScancode()
// {
//     char c = 0;
// 	while (1)
// 	{
//         if(inb(0x60) != c)
// 		{
//             c = inb(0x60);
//             if(c > 0)
//                 return c;
//         }
//     }
// }

char getScancode()
{
    while (!(inb(0x64) & 1))
	{
	}
    return inb(0x60);
}

char getchar()
{
	// return scancode[getScancode() + 1];
    return getScancode();
}
