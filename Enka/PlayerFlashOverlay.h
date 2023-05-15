#pragma once

#include "WndInterface.h"
#include "GeneralOverlayInterface.h"


class PlayerFlashOverlay : public WndInterface, public GeneralOverlayInterface
{
public:

	PlayerFlashOverlay(sf::Vector2f position, const std::string& message, const sf::Color& colour, const int fontSize, const sf::Font& font);
	virtual ~PlayerFlashOverlay();

	void update(const float deltaTime) override;
	
	virtual void draw(sf::RenderWindow & renderWindow) const override;

	void showOverlay() override;

	void setMessage(const std::string& message);

protected:
	
	sf::Text _flashingText;

	sf::Text _shadowText;

	sf::Vector2f _position;

	float _displayTimer;
};

