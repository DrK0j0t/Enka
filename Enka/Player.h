#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Card.h"
#include "DrawableText.h"
#include "RecentCardPile.h"
#include "TurnAction.h"
#include "PlayerUpdateResult.h"


class Player
{
public:
	
	enum PlayerType { ThisPlayer, AIPlayer };
	
	enum UNOState { Safe, Called, NotSafe };

	Player(const int playerID, const std::string& playerName, const PlayerType playerType, const sf::IntRect bounds, const bool showPlayerNameLeft, const sf::Font& font);
	virtual ~Player();


	virtual PlayerUpdateResult update(const float deltaTime, const Player* currentPlayer, TurnAction* currentTurnAction, const RecentCardPile* recentCards, const std::vector<Player*>& players, const RuleSet* rules) { 
		return { PlayerUpdateResultState::PlayerDidNothing, nullptr, -1, nullptr };
	}

	void draw(sf::RenderWindow& renderWindow, const Player* currentPlayer) const;


	void addCardToHand(Card* card);

 
	void emptyHand();


	void revealHand(const bool reveal);

	
	PlayerType getPlayerType() const;

	int getPlayerID() const;


	std::vector<Card*> getValidMoves(const int curFaceValue, const int curColourValue) const;

	void sortHand();


	void updateHover(const sf::Vector2i& mousePosition);

	
	Card* removeCard(const int uniqueCardID);

	const Card* getCardByID(const int cardID);


	const Card* chooseCardFromClick(const sf::Vector2i& mousePosition);

	
	const std::vector<Card*>& getHand() const;

	
	std::vector<Card*> takeAllHand();

	
	const std::string& getPlayerName() const;

	
	int getHandTotalScore() const;

	
	sf::Vector2f getCentreOfBounds() const;

	
	void setCurrentRoundScore(const int newCurrentRoundScore);


	void setWon();

	
	bool getWon() const;

	
	int getTotalScore() const;

	
	int getCurrentRoundScore() const;

	
	void resetScore();

	
	void setUnoState(const UNOState unoState);

	
	bool isSafe() const;

	
	UNOState getUnoState() const;

private:
	
	const int _playerID;

	
	std::string _playerName;

	
	const PlayerType _playerType;

	
	const sf::IntRect _bounds;

	
	std::vector<Card*> _hand;

	
	Card* _hoveredCard;

	
	bool _showCards;

	
	int _totalScore;

	
	int _currentRoundScore;


	bool _wonRound;

	
	const bool _showPlayerNameLeft;

	
	UNOState _unoState;

	
	DrawableObjectGroup* _nameTag;

	
	DrawableText* _playerNameText;

	void recalculateCardPositions();
};

