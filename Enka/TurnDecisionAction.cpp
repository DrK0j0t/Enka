#include "TurnDecisionAction.h"

TurnDecisionAction::TurnDecisionAction(TurnAction * next, TurnAction * otherNext, const bool timeOut, const std::string & flagName, TurnActionSequence<TurnAction>* parentSequence, const TurnActionEffect actionID, const std::string & actionDebugText)
	: TurnAction(next, parentSequence, actionID, actionDebugText), _otherNext(otherNext), _timeOut(timeOut), _flagName(flagName)
{
	_hasRunOnce = false;
}

TurnAction * TurnDecisionAction::getNext()
{
	if(getPropertyValue(_flagName) != -1) {
        return (getPropertyValue(_flagName) == 0) ? _next : _otherNext;
    }
    return this;
}

TurnActionEffect TurnDecisionAction::getTurnAction()
{
	if (_hasRunOnce) { return TurnActionEffect::Nothing; }
	_hasRunOnce = true;

	return TurnAction::getTurnAction();
}

void TurnDecisionAction::injectFlagProperty(const int value)
{
	injectProperty(_flagName, value);
}

bool TurnDecisionAction::requiresTimeout() const
{
	return _timeOut;
}

std::string TurnDecisionAction::getFlagName() const
{
	return _flagName;
}

bool TurnDecisionAction::getHasRunOnce() const
{
	return _hasRunOnce;
}

bool TurnDecisionAction::getTimeOut() const
{
	return _timeOut;
}

TurnAction * TurnDecisionAction::getOtherNextPointer() const
{
	return _otherNext;
}
