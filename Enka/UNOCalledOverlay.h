#pragma once

#include "PlayerFlashOverlay.h"


class UNOCalledOverlay : public PlayerFlashOverlay
{
public:

	UNOCalledOverlay(sf::Vector2f position, const sf::Font& font);
	virtual ~UNOCalledOverlay();

	void draw(sf::RenderWindow & renderWindow) const override;

private:
	
	std::vector<sf::Text> _UNOLetters;
};

