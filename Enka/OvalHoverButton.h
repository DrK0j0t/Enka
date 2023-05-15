#pragma once

#include "WndInterface.h"
#include "DrawableShape.h"
#include "DrawableObjectGroup.h"


class OvalHoverButton : public WndInterface
{
public:

	OvalHoverButton(const sf::IntRect& bounds, const sf::Font& font, const std::string& message, const sf::Color& bgColour);
	virtual ~OvalHoverButton();


	virtual void handleMouseMove(const sf::Vector2i& mousePosition) override;


	virtual void draw(sf::RenderWindow & renderWindow) const override;

	bool isTriggeredReset();

	int getActionID() const;

protected:

	bool _isHovered;

	bool _isActive;

	bool _isTriggered;

	int _actionID;

private:

	sf::Color _bgColour;

	DrawableShape* _hoverShape;

	DrawableObjectGroup* _text;
};

