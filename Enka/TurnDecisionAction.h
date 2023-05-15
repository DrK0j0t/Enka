#pragma once
#include "TurnAction.h"


class TurnDecisionAction :
	public TurnAction
{
public:
	
	TurnDecisionAction(TurnAction* next, TurnAction* otherNext, const bool timeOut, const std::string& flagName, TurnActionSequence<TurnAction>* parentSequence, const TurnActionEffect actionID, const std::string& actionDebugText);
	virtual ~TurnDecisionAction() = default;

	TurnAction* getNext() override;

	TurnActionEffect getTurnAction() override;

	void injectFlagProperty(const int value);


	bool requiresTimeout() const;

	std::string getFlagName() const;

	bool getHasRunOnce() const;

	bool getTimeOut() const;

	TurnAction* getOtherNextPointer() const;

private:
	bool _timeOut;
	TurnAction* _otherNext;
	std::string _flagName;
	bool _hasRunOnce;
};

