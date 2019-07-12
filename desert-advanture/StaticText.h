#pragma once
#include "GameObject.h"
#include <string>
#include "Game.h"
using namespace std;
class StaticText : public GameObject
{
protected:
	Font m_font;
	Text m_text;
	string m_path;
	string m_textString;
	int m_size;
	Color m_color;
	int m_positionX;
	int m_positionY;
	string m_id = "STATICTEXT";

public:
	StaticText(string path, string text, int size, Color color, int positionX, int positionY);
	~StaticText();
	virtual void handleInput();
	virtual void update();
	virtual void draw();
	virtual string getID();
	FloatRect getRect();
};

