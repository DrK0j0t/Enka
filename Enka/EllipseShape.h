#pragma once

#include <SFML/Graphics.hpp>


class EllipseShape : public sf::Shape
{
public:

	explicit EllipseShape(const sf::Vector2f& radius = sf::Vector2f(0.f, 0.f));
	~EllipseShape();

	void setRadius(const sf::Vector2f& radius);
	
	
	const sf::Vector2f& getRadius() const;

	
	virtual std::size_t getPointCount() const;

	
	virtual sf::Vector2f getPoint(std::size_t index) const;

private:

	sf::Vector2f _radius;
};

