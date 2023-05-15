#pragma once
#include "WndInterface.h"
#include "DrawableObjectGroup.h"
#include "Button.h"


class PauseInterface :
	public WndInterface
{
public:
	
	PauseInterface(const sf::IntRect& bounds, const sf::IntRect& gameBounds, const sf::Font& font);
	virtual ~PauseInterface();

	virtual void update(const float deltaTime) override {}

	virtual void draw(sf::RenderWindow & renderWindow) const override;

	virtual void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) override;

	virtual void handleMouseMove(const sf::Vector2i& mousePosition) override;

	WndResultState getResultState() const override;

	void resetResultState();

private:

	DrawableObjectGroup* _interfaceBackground;

	std::vector<Button> _buttonList;

	WndResultState _resultState;

	void initialiseInterface(const sf::IntRect & bounds, const sf::IntRect& gameBounds, const sf::Font & font);

	void handleButtonAction(const int actionID);
};

