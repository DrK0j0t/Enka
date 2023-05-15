#pragma once

#include "WndInterface.h"
#include "TurnDecisionOverlayInterface.h"
#include "DrawableShape.h"
#include "DrawableText.h"
#include "GameStateData.h"


class StatusOverlay : public WndInterface, public TurnDecisionOverlayInterface
{
public:

	StatusOverlay(const sf::IntRect& bounds, const sf::Font& font, const GameStateData& gameData);
	virtual ~StatusOverlay();


	virtual void update(const float deltaTime) override;

	virtual void draw(sf::RenderWindow & renderWindow) const override;


	virtual void showOverlay(TurnDecisionAction * currentAction) override;

private:

	sf::Vector2f _centre;
	

	float _timeOut;
	
	
	DrawableText* _statusText;
	

	DrawableText* _timeOutText;
	
	
	DrawableText* _timeOutShadowText;
	

	DrawableShape* _background;

	
	const GameStateData& _gameData;

	
	std::string createContextString(TurnDecisionAction* currentAction);

	
	void updateStatusLabel(const std::string& status);


	void updateTimeOutLabel();
};

