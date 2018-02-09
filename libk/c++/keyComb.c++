#include <keyComb.h>

constexpr unsigned char KeyComb::scancode[128]; // Kamoulox
constexpr unsigned char KeyComb::majscancode[128];

KeyComb::KeyComb() : _flags(0), _ascii(0), _code(0)
{
}

KeyComb::KeyComb (KeyComb const & src) : _flags(src._flags), _ascii(src._ascii), _code(src._code)
{
}

bool	KeyComb::isShiftPressed()
{
	return ((bool)(_flags & KEYCOMB_SHIFT));
}

bool	KeyComb::isCtrlPressed()
{
	return ((bool)(_flags & KEYCOMB_CTRL));
}

bool	KeyComb::isAltPressed()
{
	return ((bool)(_flags & KEYCOMB_ALT));
}

bool	KeyComb::isAscii()
{
	return ((bool)(_flags & KEYCOMB_ASCII));
}

char	KeyComb::getAscii()
{
	return (_ascii);
}

char	KeyComb::getCode()
{
	return (_code);
}


void	KeyComb::pressShift()
{
	_flags |= KEYCOMB_SHIFT;
}

void	KeyComb::pressCtrl()
{
	_flags |= KEYCOMB_CTRL;
}

void	KeyComb::pressAlt()
{
	_flags |= KEYCOMB_ALT;
}

void	KeyComb::setAscii(bool val)
{
	if (val)
		_flags |= KEYCOMB_ASCII;
	else
		_flags = _flags & (~KEYCOMB_ASCII);
}

void KeyComb::setKeyFromScancode(char code)
{
	_code = code;
	if (isAltPressed() || isCtrlPressed())
	{
		setAscii(false);
		return ;
	}
	if (isShiftPressed())
	{
		if (this->majscancode[code] == 0)
			setAscii(false);
		else
		{
			setAscii(true);
			_ascii = this->majscancode[code];
		}
	}
	else
	{
		if (this->scancode[code] == 0)
			setAscii(false);
		else
		{
			setAscii(true);
			_ascii = this->scancode[code];
		}
	}
}
