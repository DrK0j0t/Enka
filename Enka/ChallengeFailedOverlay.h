#pragma once

#include "WndInterface.h"
#include "GeneralOverlayInterface.h"
#include "PolygonShape.h"


class ChallengeFailedOverlay : public WndInterface, public GeneralOverlayInterface
{
public:

	ChallengeFailedOverlay(const sf::IntRect& bounds);
	virtual ~ChallengeFailedOverlay();

	virtual void update(const float deltaTime) override;


	virtual void draw(sf::RenderWindow & renderWindow) const override;


	virtual void showOverlay() override;

private:

	float _displayTimer;

	
	PolygonShape* _crossShape;
};

