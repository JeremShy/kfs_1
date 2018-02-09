#ifndef TERMINAL_H
# define TERMINAL_H

# include <types.h>

class Terminal {
private:
	size_t _row;
	size_t _column;
	uint8_t _color;
	volatile uint16_t* _buffer;

	void putEntryAt(char c, uint8_t color, size_t x, size_t y);

public:
	Terminal();
	void putchar(char c);
	void write(const char* data, size_t size);
	void	scrollUp();

	void setColor(uint8_t color);
	uint8_t	getColor();
};

#endif
