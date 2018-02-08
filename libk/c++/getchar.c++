#include <libk.h>
// char getScancode() {
//     char c=0;
//     do {
//         if(inb(0x60)!=c) {
//             c=inb(0x60);
//             if(c>0)
//                 return c;
//         }
//     } while(1);
// }


char getScancode()
{
    while (!(inb(0x64) & 1));
    return inb(0x60);
}

char getchar()
{
	// return scancode[getScancode() + 1];
    char code = getScancode();
	putstr("Returning scancode.\n");
	return (code);
}
