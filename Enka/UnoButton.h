#pragma once


#include "GeneralOverlayInterface.h"
#include "Player.h"
#include "OvalHoverButton.h"
#include "GameStateData.h"


class UnoButton : public OvalHoverButton, public GeneralOverlayInterface
{
public:

	UnoButton(const sf::Vector2f position, const sf::Font& font, const GameStateData& gameData);
	virtual ~UnoButton() = default;


	virtual void update(const float deltaTime) override;


	virtual void showOverlay() override;
	
	virtual void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) override;

private:

	Player* _bottomPlayer;

	const GameStateData& _gameState;
};

