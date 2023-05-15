#pragma once

#include "WndInterface.h"
#include "TurnDecisionOverlayInterface.h"
#include "Button.h"
#include "Player.h"
#include "GameStateData.h"


class StackChoiceOverlay : public WndInterface, public TurnDecisionOverlayInterface
{
public:

	StackChoiceOverlay(const sf::IntRect & bounds, const sf::Font & font, const GameStateData& gameData);
	virtual ~StackChoiceOverlay();

	virtual void update(const float deltaTime) override {};

	virtual void draw(sf::RenderWindow& renderWindow) const override;

	virtual void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) override;

	virtual void handleMouseMove(const sf::Vector2i& mousePosition) override;


	virtual void showOverlay(TurnDecisionAction * currentAction) override;

private:
	
	Button* _declineButton;
	
	TurnDecisionAction* _currentAction;
	
	Player* _playerReference;
};

