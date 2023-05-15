#pragma once

#include "WndInterface.h"
#include "TurnDecisionOverlayInterface.h"
#include "Button.h"
#include "Player.h"


class PlayerSelectionOverlay : public WndInterface, public TurnDecisionOverlayInterface
{
public:
	
	PlayerSelectionOverlay(const sf::IntRect & bounds, std::vector<Player*> playerList, const sf::Font & font);
	virtual ~PlayerSelectionOverlay();

	virtual void update(const float deltaTime) override {}

	
	virtual void draw(sf::RenderWindow & renderWindow) const override;

	
	virtual void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) override;

	
	virtual void handleMouseMove(const sf::Vector2i& mousePosition) override;

	
	virtual void showOverlay(TurnDecisionAction * currentAction) override;

private:
	
	std::vector<Button> _buttonList;

	
	TurnDecisionAction* _currentAction;
};

