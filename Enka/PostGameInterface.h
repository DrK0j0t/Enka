#pragma once

#include "WndInterface.h"
#include "Player.h"
#include "RuleSet.h"
#include "Button.h"
#include "DrawableObjectGroup.h"


class PostGameInterface : public WndInterface
{
public:

	PostGameInterface(const sf::IntRect& bounds, const sf::Font& font, const std::vector<Player*>& playerList, RuleSet* ruleSet);
	virtual ~PostGameInterface();


	virtual void update(const float deltaTime) override {}


	virtual void draw(sf::RenderWindow & renderWindow) const override;


	virtual void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) override;

	virtual void handleMouseMove(const sf::Vector2i& mousePosition) override;


	WndResultState getResultState() const override;

	
	std::vector<Player*> getPlayers() const;


	RuleSet* getRuleSet() const;

private:
	
	std::vector<Button> _buttonList;
	

	std::vector<Player*> _playerList;
	
	DrawableObjectGroup* _staticElements;
	
	
	WndResultState _resultState;


	RuleSet* _rules;


	void handleButtonPress(const int actionID);

	void initialiseInterface(const sf::Font& font, RuleSet* ruleSet);
};

