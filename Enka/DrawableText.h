#pragma once
#include "DrawableObject.h"

class DrawableText :
	public DrawableObject
{
public:
	DrawableText(const std::string& str, const sf::Font& font, const size_t fontSize, const sf::Color textColour, const sf::Uint32 style);
	virtual ~DrawableText() = default;

	virtual void draw(sf::RenderWindow & renderWindow) const override;

	virtual void setPositionWithOffset(const sf::Vector2f & position) override;

	virtual void move(const sf::Vector2f & offset) override;

	float getTextWidth() const;

	void setText(const std::string& text);

	void setColour(const sf::Color& colour);

private:
	
	sf::Text _textObject;
};

