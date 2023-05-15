#pragma once

#include "CurrentGameInterface.h"
#include "LobbyInterface.h"
#include "PostGameInterface.h"
#include "PauseInterface.h"


class Game
{
public:

	Game(const sf::IntRect& gameBounds, const sf::Font& font);
	virtual ~Game();


	void update(const float deltaTime);


	void draw(sf::RenderWindow & renderWindow) const;


	void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft);


	void handleMouseMove(const sf::Vector2i& mousePosition);

	
	void handleKeyInput(const sf::Keyboard::Key key);

	
	static CurrentGameInterface* getCurrentGame();
	   

	bool getGameCloseRequested();

private:

	const sf::IntRect _bounds;


	const sf::Font& _font;


	std::default_random_engine _randomEngine;


	WndInterface* _activeInterface;

	
	static CurrentGameInterface* _currentGame;

	
	LobbyInterface* _lobbyInterface;

	
	PostGameInterface* _postGameInterface;

	
	PauseInterface* _pauseInterface;

	
	bool _terminateGame;

	
	void setPauseState(const bool isPaused);

	
	void showLobby();

	
	void startGame();


	void startNextRound();

	
	void showPostGame();

	void quitGame();
};
