#pragma once

#include "WndInterface.h"
#include "TurnDecisionOverlayInterface.h"
#include "InteractableRect.h"
#include "DrawableObjectGroup.h"
#include "DrawableShape.h"


class WildColourSelectionOverlay : public WndInterface, public TurnDecisionOverlayInterface
{
public:

	WildColourSelectionOverlay(const sf::IntRect& bounds, const sf::Font& font);
	virtual ~WildColourSelectionOverlay();


	virtual void update(const float deltaTime) override {}

	virtual void draw(sf::RenderWindow & renderWindow) const override;


	virtual void showOverlay(TurnDecisionAction * currentAction) override;


	virtual void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) override;


	virtual void handleMouseMove(const sf::Vector2i& mousePosition) override;

private:

	int _hoveredRegion, _hoverX, _hoverY;
	
	TurnDecisionAction* _currentAction;
	

	InteractableRect _interactionRect;
	

	DrawableObjectGroup* _background;


	std::vector<DrawableShape*> _hoverArcs;
};

