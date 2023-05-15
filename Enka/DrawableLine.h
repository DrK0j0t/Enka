#pragma once

#include "DrawableObject.h"


class DrawableLine : public DrawableObject
{
public:

	DrawableLine(std::initializer_list<sf::Vector2f> vertexList);
	virtual ~DrawableLine();

	virtual void draw(sf::RenderWindow & renderWindow) const override;


	virtual void setPositionWithOffset(const sf::Vector2f & position) override {}

	virtual void move(const sf::Vector2f & offset) override {}

private:

	std::size_t _elementCount;

	sf::Vertex* _line;

	sf::Vertex* getVertexList(std::initializer_list<sf::Vector2f> vertexList);
};

