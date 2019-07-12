#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Helper
{
public:
	bool static isMouseonTop(FloatRect &rect);
	bool static collision(FloatRect &obj1, FloatRect &obj2);	
};

