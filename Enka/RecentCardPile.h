#pragma once

#include "Card.h"
#include <random>


class RecentCardPile
{
public:

	RecentCardPile(const sf::Vector2f centredCardPos, std::default_random_engine& randomEngine);
	virtual ~RecentCardPile();

	void draw(sf::RenderWindow & renderWindow) const;


	void setTopCardColour(const int colourID);


	void placeCard(Card* card);

	
	void forcePlayCard(Card* card);

	Card* getTopCard() const;


	Card* getCardBelowTop() const;

private:

	std::vector<Card*> _recentCards;

	
	sf::Vector2f _centredCardPos;

	std::default_random_engine& _randomEngine;
};

