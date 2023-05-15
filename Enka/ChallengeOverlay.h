#pragma once

#include "WndInterface.h"
#include "TurnDecisionOverlayInterface.h"
#include "Button.h"
#include "Player.h"
#include "GameStateData.h"


class ChallengeOverlay : public WndInterface, public TurnDecisionOverlayInterface
{
public:

	ChallengeOverlay(const sf::IntRect& bounds, const sf::Font& font, const GameStateData& gameData);
	virtual ~ChallengeOverlay() = default;

	void update(const float deltaTime) override {};


	void draw(sf::RenderWindow & renderWindow) const override;

	void handleMouseMove(const sf::Vector2i& mousePosition) override;

	void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) override;

	virtual void showOverlay(TurnDecisionAction * currentAction) override;

private:

	std::vector<Button> _buttonList;

	TurnDecisionAction* _currentAction;

	bool _allowStacking;

	Player* _playerReference;
};

