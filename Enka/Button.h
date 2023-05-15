#pragma once
#include "InteractableRect.h"
#include "DrawableObjectGroup.h"
#include "DrawableShape.h"
#include "DrawableText.h"


class Button :
	public InteractableRect
{
public:

	Button(const sf::IntRect& bounds, const std::string& text, const int actionID, const sf::Font& font);
	virtual ~Button() = default;


	void draw(sf::RenderWindow& renderWindow) const;


	int getActionID() const;


	void setHovering(const bool isHovering);

private:

	int _actionID;


	bool _isHovered;


	std::string _text;


	DrawableObjectGroup _defaultView, _hoveredView;


	void initialiseDefaultView(const sf::Font& font);

	void initialiseHoveredView(const sf::Font& font);
};

