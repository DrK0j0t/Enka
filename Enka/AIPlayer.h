#pragma once
#include "Player.h"
#include "TurnDecisionAction.h"
#include <random>

class AIPlayer :
	public Player
{
public:

	enum AIStrategy { Offensive, Defensive, Chaotic, Random };


	AIPlayer(const int playerID, const std::string& playerName, const sf::IntRect bounds, const AIStrategy strategy, const bool showPlayerNameLeft, std::default_random_engine& randomEngine, const sf::Font& font);
	virtual ~AIPlayer() = default;

	PlayerUpdateResult update(const float deltaTime, const Player* currentPlayer, TurnAction* currentTurnAction, const RecentCardPile* recentCards, const std::vector<Player*>& players, const RuleSet* rules) override;


	static std::string aiStrategyToString(const AIStrategy strategy);

private:

	std::default_random_engine& _randomEngine;


	AIStrategy _strategy;


	float _delayTimer;

	int _consideringPlayerID;


	float _consideringDelayTimer;


	bool _canJumpIn;


	bool _consideringJumpIn;


	float _consideringJumpInTimer;

	void selectRandomStrategy();

	PlayerUpdateResult updateAntiUnoCheck(const int deltaTime, const std::vector<Player*>& players);

	PlayerUpdateResult updateJumpInCheck(const int deltaTime, const RuleSet* rules, const TurnAction* currentTurnAction, const Player* currentPlayer, const RecentCardPile* recentCards);

	std::pair<TurnActionSequence<TurnAction>*, PlayerUpdateResult> performTurn(Card* topCard);


	void resetDelayTimer();


	Card* chooseCard(std::vector<Card*>& validCards);


	PlayerUpdateResult handleTurnDecision(TurnDecisionAction* decisionAction, const std::vector<Player*>& players, const RuleSet* rules);


	PlayerUpdateResult chooseWildColour(TurnDecisionAction* decisionAction);

	PlayerUpdateResult chooseKeepOrPlay(TurnDecisionAction* decisionAction);

	PlayerUpdateResult choosePlayerToSwapWith(TurnDecisionAction* decisionAction, const std::vector<Player*>& players);

	PlayerUpdateResult chooseChallengeOrDecline(TurnDecisionAction* decisionAction, const RuleSet* rules);


	PlayerUpdateResult chooseStackPlus2(TurnDecisionAction* decisionAction, const RuleSet* rules);

	PlayerUpdateResult checkCallUNO();
};

