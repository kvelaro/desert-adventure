#include "pch.h"
#include "Helper.h"


bool Helper::isMouseonTop(FloatRect &rect)
{
	Vector2i mousePosition = Mouse::getPosition();
	if (mousePosition.x > rect.left && rect.left + rect.width > mousePosition.x && mousePosition.y > rect.top && rect.top + rect.height > mousePosition.y) {
		return true;
	}
	return false;
}