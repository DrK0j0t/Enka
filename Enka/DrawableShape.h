#pragma once
#include "DrawableObject.h"

class DrawableShape :
	public DrawableObject
{
public:
	DrawableShape(sf::Shape* shape, const sf::Color& colour, const sf::Vector2f& offset = sf::Vector2f(0.0f, 0.0f))
		: DrawableObject(offset), _shape(shape) {
		_shape->setFillColor(colour);
	};
	virtual ~DrawableShape();

	void draw(sf::RenderWindow& renderWindow) const override;

	void setPositionWithOffset(const sf::Vector2f & position) override;

	void move(const sf::Vector2f & moveOffset) override;

	void setColour(const sf::Color& colour);

	void setBorder(const float thickness, const sf::Color colour);

	void setSize(const sf::Vector2f size);

private:
	sf::Shape* _shape;
};

