#include "pch.h"
#include "StaticText.h"


StaticText::StaticText(string path, string text, int size, Color color, int positionX, int positionY)
{
	m_path = path;
	m_textString = text;
	m_size = size;
	m_color = color;
	m_positionX = positionX;
	m_positionY = positionY;
	m_font.loadFromFile(m_path);

	m_text.setString(m_textString);
	m_text.setCharacterSize(m_size);
	m_text.setFillColor(m_color);
	m_text.setFont(m_font);

	FloatRect gameOverStateTextRect = m_text.getGlobalBounds();
	m_text.setOrigin(gameOverStateTextRect.left + gameOverStateTextRect.width / 2.0f, gameOverStateTextRect.top + gameOverStateTextRect.height / 2.0f);
	m_text.setPosition(m_positionX, m_positionY);
}

StaticText::~StaticText()
{
}

void StaticText::handleInput()
{
}

void StaticText::update()
{
	
}

void StaticText::draw()
{
	Game::getInstance()->getWindow()->draw(m_text);
}

string StaticText::getID()
{
	return m_id;
}

FloatRect StaticText::getRect()
{
	return m_text.getGlobalBounds();
}
