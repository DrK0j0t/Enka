#pragma once

#include <map>


class RuleSet
{
public:
	
	enum CardAction { Nothing, Plus2, Plus4, Wild, Skip, Reverse, Swap, PassAll };

	enum ScoreLimitType { OneRound, Score200, Score300, Score500, Unlimited };


	RuleSet();
	virtual ~RuleSet() = default;


	void setToDefaults();


	CardAction getActionForCard(const int faceValueID) const;


	bool canStackCards() const;


	void setCanStackCards(const bool canStackCards);

	bool shouldDrawnTillCanPlay() const;

	void setDrawnTillCanPlay(const bool drawnTillCanPlay);


	int getDefaultTimeOut() const;


	void setTwoPlayers(const bool onlyTwoPlayers);

	bool getOnlyTwoPlayers() const;

	void setSevenZeroRule(const bool sevenZeroRule);


	bool getSevenZeroRule() const;

	void setNoBuffingRule(const bool noBluffingRule);

	bool getNoBluffingRule() const;


	void setAllowJumpInRule(const bool allowJumpInRule);


	bool allowJumpInRule() const;


	void setForcedPlayRule(const bool forcedPlayRule);


	bool getForcedPlayRule() const;


	void setScoreLimitType(const ScoreLimitType scoreLimitType);


	ScoreLimitType getScoreLimitType() const;

private:
	
	std::map<int, CardAction> _faceValueToActionMap;
	
	bool _canStackCards;

	bool _drawTillCanPlay;

	int _defaultTimeOut;
	
	bool _onlyTwoPlayers;

	bool _sevenZeroRule;
	
	bool _noBluffingRule;

	bool _allowJumpInRule;
	
	bool _forcedPlayRule;

	ScoreLimitType _scoreLimitType;
};

