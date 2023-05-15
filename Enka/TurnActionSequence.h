#pragma once

#include "RuleSet.h"
#include <vector>
#include <map>
#include "TurnActionEffect.h"
#include <string>

template <class T>
class TurnActionSequence
{
public:
	explicit TurnActionSequence();
	virtual ~TurnActionSequence();

	void setStartOfSequence(T* startAction);

	void iterateSequence();

	T* getCurrentAction();

	void injectProperty(const std::string& key, const int value);

	
	int getPropertyValue(const std::string& key) const;

	RuleSet* getRuleSet();

	void debugOutputTurnActionTree();

private:
 
	std::vector<T*> _unorderedSequence;


	T* _currentAction;


	std::map<std::string, int> _storedData;


	RuleSet* _ruleSet;

	void resolveEffect(TurnActionEffect effect);

	void playCardAsActionFromData();

	void drawCardAsActionFromData();

	
	void drawCard();

	void placeCard();

	void moveNextTurn();

	void increaseDrawCountBy2();
	
	void increaseDrawCountBy4();

	void increaseDrawCountByN(const int N);

	void drawNCards();

	void isCardPlayable();

	void beginChoiceOverlay();

	void checkDrawTillCanPlayRule();

	void hasPlus2AndResponseAllowed();

	void showSkip();

	void togglePlayDirection();

	void setTopPileColour();

	void checkCouldPlayCard();

	void draw4ChallengeSuccess();

	void movePrevious();

	void swapHandWithOther();

	void passAllHands();

	void showChallengeResult();

	void checkNoBluffingRule();

	void checkForcedPlayRule();

	void flushTurnActions();

	void loadAllPointers(T* actionToAdd);
};