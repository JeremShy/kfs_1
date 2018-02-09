#ifndef TERMINAL_H
# define TERMINAL_H

# include <types.h>
# include <cursor.h>

class Terminal {
private:
	size_t _row;
	size_t _column;
	uint8_t _color;
	volatile uint16_t* _buffer;
	Cursor _cursor;

	void putEntryAt(char c, uint8_t color, size_t x, size_t y);

public:
	Terminal();
	void putchar(char c);
	void write(const char* data, size_t size);
	void	scrollUp();

	void setColor(uint8_t color);
	uint8_t	getColor();

	void	disableCursor();
	void	enableCursor(uint8_t startLine, uint8_t endLine);

	void	moveCursorTo(int x, int y);
};

#endif
