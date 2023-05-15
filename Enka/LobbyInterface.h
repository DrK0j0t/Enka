#pragma once

#include "WndInterface.h"
#include "LobbyPlayer.h"
#include "Button.h"
#include "RuleSet.h"
#include <map>
#include <string>


class LobbyInterface : public WndInterface
{
public:
	
	LobbyInterface(const sf::IntRect& bounds, const sf::Font& font, std::default_random_engine& randomEngine);
	virtual ~LobbyInterface();

	void update(const float deltaTime) override {}

	void draw(sf::RenderWindow& renderWindow) const override;

	void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) override;

	void handleMouseMove(const sf::Vector2i& mousePosition) override;


	RuleSet* getRuleSet() const;


	std::vector<LobbyPlayer*> getLobbyPlayerList() const;


	WndResultState getResultState() const override;

private:
	
	std::vector<LobbyPlayer*> _playerList;

	std::vector<Button> _buttonList;

	RuleSet* _ruleSet;

	std::map<std::string, sf::Text> _ruleStrings;

	DrawableObjectGroup* _background;

	WndResultState _resultState;

	void handleButtonPress(const int actionID);

	void toggleNumberOfPlayers();

	void updatePlayerNumberStatus();

	void toggleStackRule();

	void updateStackRuleLabel();

	void toggleDrawTillCanPlayRule();

	void updateDrawTillCanPlayRuleLabel();

	void toggleSevenZeroRule();

	void updateSevenZeroRuleLabel();

	void toggleForcedPlayRule();

	void updateForcedPlayRuleLabel();

	void toggleJumpInRule();

	void updateJumpInRuleLabel();

	void toggleNoBluffingRule();

	void updateNoBluffingRuleLabel();

	void cycleScoreLimit();

	void updateScoreLimitLabel();

	void resetRulesToDefault();

	void updateAllRuleLabels();

	std::vector<std::string> getRandomAINameList(std::default_random_engine& randomEngine);

	void initialiseRuleOptions(const sf::IntRect& bounds, const sf::Font& font);

	void initialiseBackground(const sf::IntRect& bounds, const sf::Font& font);
};

