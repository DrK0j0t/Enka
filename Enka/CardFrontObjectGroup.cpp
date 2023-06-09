#include "CardFrontObjectGroup.h"
#include "DrawableShape.h"
#include "DrawableText.h"
#include "EllipseShape.h"
#include "ArcShape.h"
#include "Card.h"

CardFrontObjectGroup::CardFrontObjectGroup(const int faceValue, const int colourID, const sf::Vector2f& initialPosition, const sf::Font& font)
{
	
	DrawableShape* background = new DrawableShape(new sf::RectangleShape(sf::Vector2f(CARD_WIDTH - 4, CARD_HEIGHT - 4)), 
													Card::getColourByID(colourID), sf::Vector2f(2, 2));
	background->setBorder(2, sf::Color::White);
	addChild(background);

	if (colourID != 4) {

		DrawableShape* centralEllipse = new DrawableShape(new EllipseShape(sf::Vector2f((CARD_WIDTH - 8) / 2, (CARD_WIDTH - 8) / 4)), 
												sf::Color::White, sf::Vector2f(4, CARD_HEIGHT / 2 - ((CARD_WIDTH - 8) / 4)));
		addChild(centralEllipse);
	}
	else {

		for (int i = 0; i < 4; i++) {
			ArcShape* arcShape = new ArcShape(90 * i, 90 * (i+1), sf::Vector2f((CARD_WIDTH - 8) / 2, ((CARD_WIDTH - 8) / 4)/2+10));
			DrawableShape* arc = new DrawableShape(arcShape, Card::getColourByID(i), sf::Vector2f(4, CARD_HEIGHT / 2 - ((CARD_WIDTH - 8) / 4)));
			addChild(arc);
		}
	}

	std::string label = Card::getLabelByFaceValue(faceValue);
	std::string cornerLabel = Card::getCornerLabelByFaceValue(faceValue);

	// Shadow behind central text (only shows for wild and short text)
	if (colourID == 4 || label.length() <= 4) {
		size_t fontHeight = (label.length() > 4) ? 10 : 20;
		DrawableText* shadowText = new DrawableText(label, font, fontHeight, sf::Color::Black, sf::Text::Bold);
		shadowText->setOffset(sf::Vector2f(CARD_WIDTH/2-shadowText->getTextWidth()/2-1, CARD_HEIGHT/2-fontHeight/2-1));
		addChild(shadowText);
	}

	// Foreground text that changes dependent on shadow and card colour.
	sf::Color textColour = sf::Color::White;
	if (colourID != 4) {
		textColour = label.length() <= 4 ? Card::getColourByID(colourID) : sf::Color::Black;
	}
	size_t fontHeight = (label.length() > 4) ? 10 : 20;
	DrawableText* foregroundText = new DrawableText(label, font, fontHeight, textColour, sf::Text::Bold);
	foregroundText->setOffset(sf::Vector2f(CARD_WIDTH / 2 - foregroundText->getTextWidth() / 2, CARD_HEIGHT / 2 - fontHeight / 2));
	addChild(foregroundText);

	// Labels in each of the corners.	
	fontHeight = (cornerLabel.length() > 2) ? 10 : 20;
	DrawableText* topLeftCorner = new DrawableText(cornerLabel, font, fontHeight, sf::Color::White, sf::Text::Bold);
	topLeftCorner->setOffset(sf::Vector2f(5, 5));
	addChild(topLeftCorner);
	DrawableText* bottomRightCorner = new DrawableText(cornerLabel, font, fontHeight, sf::Color::White, sf::Text::Bold);
	bottomRightCorner->setOffset(sf::Vector2f(CARD_WIDTH-bottomRightCorner->getTextWidth()-5, CARD_HEIGHT-fontHeight-5));
	addChild(bottomRightCorner);

	// ESSENTIAL! This line updates all elements to apply the offset based on a relative position. 
	setPositionWithOffset(initialPosition);
}
