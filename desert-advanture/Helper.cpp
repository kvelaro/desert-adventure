#include "pch.h"
#include "Helper.h"


bool Helper::isMouseonTop(FloatRect &rect)
{
	Vector2i mousePosition = Mouse::getPosition();
	if (mousePosition.x > rect.left && rect.left + rect.width > mousePosition.x && mousePosition.y > rect.top && rect.top + rect.height > mousePosition.y) 
	{
		return true;
	}
	return false;
}

bool Helper::collision(FloatRect &obj1, FloatRect &obj2)
{
	if (obj1.left + obj1.width >= obj2.left &&     // r1 right edge past r2 left
		obj1.left <= obj2.left + obj2.width &&       // r1 left edge past r2 right
		obj1.top + obj1.height >= obj2.top &&       // r1 top edge past r2 bottom
		obj1.top <= obj2.top + obj2.height) {       // r1 bottom edge past r2 top
		return true;
	}
	return false;
}
