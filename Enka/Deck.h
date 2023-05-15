#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>       
#include "Card.h"
#include "CardBackGroupObject.h"
#include "DrawableText.h"
#include "InteractableRect.h"


class Deck : public InteractableRect
{
public:
	
	Deck(const sf::Vector2f position, const sf::Font& font, std::default_random_engine& randomEngine);
	virtual ~Deck();

	void draw(sf::RenderWindow& renderWindow) const;

	
	Card* drawCard();

private:
	
	std::default_random_engine& _randomEngine;

	
	sf::Vector2f _position;

	
	std::vector<Card*> _deck;


	std::shared_ptr<CardBackGroupObject> _cardBack;


	int _nextCardID;


	DrawableText _deckTitle;

	const sf::Font& _font;


	void fillDeck();

	void addCard(const int faceValueID, const int colourID);
};

