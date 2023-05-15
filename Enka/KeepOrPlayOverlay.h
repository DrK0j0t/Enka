#pragma once

#include "WndInterface.h"
#include "TurnDecisionOverlayInterface.h"
#include "Button.h"
#include "CardFrontObjectGroup.h"


class KeepOrPlayOverlay
	: public WndInterface, public TurnDecisionOverlayInterface
{
public:
	
	KeepOrPlayOverlay(const sf::IntRect& bounds, const sf::Font& font);
	virtual ~KeepOrPlayOverlay();


	virtual void update(const float deltaTime) override { }

	
	virtual void draw(sf::RenderWindow & renderWindow) const override;


	virtual void showOverlay(TurnDecisionAction * currentAction) override;

	
	virtual void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) override;
	
	virtual void handleMouseMove(const sf::Vector2i& mousePosition) override;

private:
	
	const sf::Font& _font;

	std::vector<Button> _buttonList;

	TurnDecisionAction* _currentAction;

	CardFrontObjectGroup* _cardForChoice;

	sf::Vector2f _cardPosition;
};

