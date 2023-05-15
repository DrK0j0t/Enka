#pragma once

#include <SFML/Graphics.hpp>


class PlayDirectionAnimation
{
public:
	
	PlayDirectionAnimation(const sf::Vector2f centre, const int radiusFromCentre, const int indicatorSize);
	virtual ~PlayDirectionAnimation() = default;

	
	void update(const float deltaTime);


	void draw(sf::RenderWindow& renderWindow) const;

	void setIsIncreasing(bool isIncreasing);
private:

	const sf::Vector2f _centre;

	const int _radiusFromCentre;

	float _currentAngle;

	bool _isIncreasing;

	sf::CircleShape _movingObject1, _movingObject2;
};

