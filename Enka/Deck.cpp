#include "Deck.h"
#include <algorithm>	

Deck::Deck(const sf::Vector2f position, const sf::Font& font, std::default_random_engine& randomEngine)
	: _position(position), InteractableRect(sf::IntRect(static_cast<int>(position.x), static_cast<int>(position.y), CARD_WIDTH, CARD_HEIGHT)),
	_deckTitle("DECK", font, 20, sf::Color::Black, sf::Text::Bold),
	_randomEngine(randomEngine), _font(font)
{
	_nextCardID = 0;
	_cardBack = std::make_shared<CardBackGroupObject>(sf::Vector2f(0, 0), font);
	_deckTitle.setPositionWithOffset(sf::Vector2f(position.x + CARD_WIDTH/2 - _deckTitle.getTextWidth()/2, position.y - 4 - 20));
}

Deck::~Deck()
{
	for (auto p : _deck)
		delete p;
}

void Deck::draw(sf::RenderWindow & renderWindow) const
{
	_cardBack->drawAt(_position, renderWindow);
	_deckTitle.draw(renderWindow);
}

Card* Deck::drawCard()
{
	if (_deck.empty()) {
		fillDeck();
	}
	Card* drawnCard = _deck.at(_deck.size() - 1);
	_deck.pop_back();
	return drawnCard;
}

void Deck::fillDeck()
{
	
	for (auto p : _deck)
		delete p;
	_deck.clear();
	

	for (int colourID = 0; colourID < 4; colourID++) {
	
		addCard(0, colourID);
	
		for (int faceValue = 1; faceValue <= 12; faceValue++) {
			addCard(faceValue, colourID);
			addCard(faceValue, colourID);
		}
	}
	
	for (int i = 0; i < 4; i++) {
		addCard(13, 4);
		addCard(14, 4);
	}

	std::shuffle(_deck.begin(), _deck.end(), _randomEngine);
}

void Deck::addCard(const int faceValueID, const int colourID)
{
	_deck.emplace_back(new Card(faceValueID, colourID, _nextCardID, _cardBack, _font));
	++_nextCardID;
}
