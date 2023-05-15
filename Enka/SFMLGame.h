#pragma once
#include "Game.h"

class SFMLGame
{
public:

	SFMLGame();
	virtual ~SFMLGame() = default;


	void gameLoop();

private:
	sf::RenderWindow _window;

	sf::Font _font;

	Game _game;

	static sf::Font loadFont();
};

