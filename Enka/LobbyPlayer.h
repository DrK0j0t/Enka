#pragma once
#include "InteractableRect.h"
#include "AIPlayer.h"
#include "DrawableObjectGroup.h"
#include "DrawableShape.h"
#include "DrawableText.h"

class LobbyPlayer :
	public InteractableRect
{
public:

	LobbyPlayer(const std::string& playerName, const Player::PlayerType playerType, const sf::IntRect& bounds, const sf::Font& font);
	virtual ~LobbyPlayer();

	void setPlayerName(const std::string& playerName);

	std::string getPlayerName() const;

	Player::PlayerType getPlayerType() const;

	void setEnabled(const bool isEnabled);

	bool isEnabled() const;

	AIPlayer::AIStrategy getAIStrategy() const;

	void handleClick();

	void draw(sf::RenderWindow& renderWindow) const;

	void updateHoverState(const sf::Vector2i& mousePosition);

private:

	std::string _playerName;

	Player::PlayerType _playerType;

	AIPlayer::AIStrategy _aiStrategy;

	std::string _strategyStr;

	bool _isEnabled;

	bool _isHovered;

	std::string _playerTypeStr;

	DrawableObjectGroup* _drawableObject;

	DrawableShape* _background;

	sf::Color _bgHoverColour;

	sf::Color _bgNotHoveredColour;

	DrawableText* _playerNameText;

	DrawableText* _aiStrategyText;

	void chooseNewName();

	void iterateStrategy();
};

