#pragma once
#include "StaticText.h"
#include <string>
#include <sstream> 
using namespace std;
class Score : public StaticText
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
	int m_score;
	stringstream m_scoreText;

public:
	Score(string path, string text, int size, Color color, int positionX, int positionY, int score = 0);
	~Score();
	virtual void handleInput();
	virtual void update();
	virtual void draw();
	virtual string getID();
	FloatRect getRect();
};

