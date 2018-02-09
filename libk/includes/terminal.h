#ifndef TERMINAL_H
# define TERMINAL_H

# include <types.h>

class Terminal {
private:
	size_t _row;
	size_t _column;
	uint8_t _color;
	volatile uint16_t* _buffer;
public:
	Terminal();
	void setColor(uint8_t color);
	void putEntryAt(char c, uint8_t color, size_t x, size_t y);
	void putchar(char c);
	void write(const char* data, size_t size);
	void	scrollUp();

	uint8_t	getColor();
};

#endif
