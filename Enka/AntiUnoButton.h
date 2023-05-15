#pragma once
#include "OvalHoverButton.h"
#include "GeneralOverlayInterface.h"
#include "Player.h"
#include "GameStateData.h"


class AntiUnoButton :
	public OvalHoverButton, public GeneralOverlayInterface
{
public:

	AntiUnoButton(const sf::Vector2f position, const sf::Font& font, const GameStateData& gameData);
	virtual ~AntiUnoButton();


	virtual void update(const float deltaTime) override;


	virtual void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) override;


	virtual void showOverlay() override;

private:

	Player* _bottomPlayer;

	const GameStateData& _gameState;
};

