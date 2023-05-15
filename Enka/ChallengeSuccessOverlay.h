#pragma once

#include "WndInterface.h"
#include "GeneralOverlayInterface.h"
#include "PolygonShape.h"


class ChallengeSuccessOverlay : public WndInterface, public GeneralOverlayInterface
{
public:

	ChallengeSuccessOverlay(const sf::IntRect& bounds);
	virtual ~ChallengeSuccessOverlay();

	
	virtual void update(const float deltaTime) override;


	virtual void draw(sf::RenderWindow & renderWindow) const override;


	virtual void showOverlay() override;

private:
	
	float _displayTimer;

	
	PolygonShape* _tickShape;
};

