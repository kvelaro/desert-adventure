#include "pch.h"
#include "Score.h"


Score::Score(string path, string text, int size, Color color, int positionX, int positionY, int score) : StaticText(path, text, size, color, positionX, positionY)
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
	m_score = score;
}

Score::~Score()
{
}

void Score::handleInput()
{
}

void Score::update()
{
	m_score++;
	m_scoreText.str("");
	m_scoreText << m_textString << m_score;
	m_text.setString(m_scoreText.str());
}

void Score::draw()
{
	Game::getInstance()->getWindow()->draw(m_text);
}

string Score::getID()
{
	return m_id;
}

FloatRect Score::getRect()
{
	return m_text.getGlobalBounds();
}
