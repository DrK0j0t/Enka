#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "InteractableRect.h"
#include "CardFrontObjectGroup.h"
#include "CardBackGroupObject.h"


#define CARD_WIDTH 60

#define CARD_HEIGHT 90


class Card : public InteractableRect
{
public:

	Card(const int faceValueID, const int colourID, const int cardID, const std::shared_ptr<CardBackGroupObject>& cardBack, const sf::Font& font);
	~Card();


	void drawCardFront(sf::RenderWindow & renderWindow) const;


	void drawCardBack(sf::RenderWindow & renderWindow) const;


	void setColour(const int colourID);


	int getColourID() const;

	int getFaceValueID() const;


	int getUniqueCardID() const;

	int getScoreValue() const;


	sf::Color getDrawColour() const;


	std::string getCardLabel() const;


	std::string getCornerLabel() const;


	static sf::Color getColourByID(const int colourID);

	static std::string getLabelByFaceValue(const int faceValue);


	static std::string getCornerLabelByFaceValue(const int faceValue);

	void setPosition(const sf::Vector2i& newPosition);

private:

	std::string _cardLabel;

	
	std::string _cornerLabel;


	const int _faceValueID;


	const int _uniqueCardID;

	int _colourID;

	sf::Color _drawColour;

	const std::shared_ptr<CardBackGroupObject>& _cardBack;

	std::unique_ptr<CardFrontObjectGroup> _cardFront;

	const sf::Font& _font;
};

