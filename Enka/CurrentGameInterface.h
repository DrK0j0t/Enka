#pragma once
#include "WndInterface.h"
#include "Deck.h"
#include "RecentCardPile.h"
#include "LobbyPlayer.h"
#include "OverlayManager.h"
#include "PlayDirectionAnimation.h"
#include "RuleSet.h"
#include "TurnActionSequenceManager.h"
#include <vector>

class CurrentGameInterface :
	public WndInterface
{
public:
	
	CurrentGameInterface(const sf::IntRect& bounds, const sf::Font& font, const std::vector<LobbyPlayer*> playerList, RuleSet* ruleSet, std::default_random_engine& randomEngine);

	
	CurrentGameInterface(const sf::IntRect& bounds, const sf::Font& font, const std::vector<Player*> playerList, RuleSet* ruleSet, std::default_random_engine& randomEngine);
	virtual ~CurrentGameInterface();

	
	virtual void update(const float deltaTime) override;


	virtual void draw(sf::RenderWindow & renderWindow) const override;


	virtual void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) override;

	virtual void handleMouseMove(const sf::Vector2i& mousePosition) override;


	virtual void handleKeyInput(const sf::Keyboard::Key key) override;

	void jumpIn(const int playerID, const Card* cardToPlay);

	void showOverlayForTurnAction();


	void showGeneralOverlay(const std::string& overlayName);

	
	void revealHands();

	
	void sortHand();


	Player* getBottomPlayer() const;

	void toggleTurnDirection();

	
	void moveToNextPlayer();

	
	void applyAntiUno(const int playerID);

	bool isIncreasing() const;


	void setCurrentTurnAction(TurnActionSequence<TurnAction>* newSequence);

	
	TurnAction* getCurrentTurnAction() const;


	RuleSet* getRuleSet() const;


	Player* getCurrentPlayer() const;

	
	std::vector<Player*> getAllPlayers() const;


	Player* getPlayerByID(const int playerID) const;

	
	Deck* getDeck() const;

	RecentCardPile* getRecentCardPile() const;

	
	WndResultState getResultState() const override;

private:
	
	RuleSet* _ruleSet;

	
	Deck* _deck;

	TurnActionSequenceManager* _turnActionSequenceManager;

	RecentCardPile* _recentCardPile;


	OverlayManager* _overlayManager;


	std::vector<Player*> _players;

	Player* _bottomPlayer;

	int _currentPlayerID;

	bool _isIncreasing;

	PlayDirectionAnimation* _playDirectionAnimation;

	bool _debugModeEnabled;

	sf::Text _debugEnabledText;

	WndResultState _resultState;

	void checkForEndOfRound();

	void updateUNOState();

	void applyPlayerUpdateResult(PlayerUpdateResult& playerUpdateResult);

	
	static std::vector<Player*> createPlayersFromLobby(const std::vector<LobbyPlayer*> playerList, sf::IntRect bounds, const sf::Font& font, std::default_random_engine& randomEngine);

	static sf::IntRect getPlayerRect(const int direction, const sf::IntRect& bounds);
};

