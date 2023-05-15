#pragma once

#include <map>
#include "TurnDecisionAction.h"
#include "WndInterface.h"
#include "Player.h"
#include "GameStateData.h"
#include "UnoButton.h"
#include "AntiUnoButton.h"


class OverlayManager : public WndInterface
{
public:
	
	OverlayManager(const sf::IntRect& bounds, std::vector<Player*> playerList, const sf::Font& font, GameStateData gameData);
	virtual ~OverlayManager();


	virtual void update(const float deltaTime, const TurnAction* currentTurnAction);


	virtual void update(const float deltaTime) override {};


	virtual void draw(sf::RenderWindow & renderWindow) const override;


	virtual void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) override;

	virtual void handleMouseMove(const sf::Vector2i& mousePosition) override;

	void showDecisionOverlay(TurnDecisionAction* currentAction);

	void showGeneralOverlay(const std::string& overlayName);

	void hideAllDecisionOverlays();

	PlayerUpdateResult getUnoButtonsState();

private:

	std::map<std::string, WndInterface*> _overlays;

	TurnDecisionAction* _overlayAction;

	GameStateData _gameState;

	UnoButton* _unoButton;

	AntiUnoButton* _antiUnoButton;
};

