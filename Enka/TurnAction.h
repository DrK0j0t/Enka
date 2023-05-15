#pragma once

#include "TurnActionSequence.h"
#include <string>
#include "TurnActionEffect.h"

class TurnAction
{
public:
	
	TurnAction(TurnAction* next, TurnActionSequence<TurnAction>* parentSequence, const TurnActionEffect actionID, const std::string& actionDebugText);
	virtual ~TurnAction() = default;

	virtual TurnActionEffect getTurnAction();

	virtual TurnAction* getNext();

	void injectProperty(const std::string& key, const int value);

	int getPropertyValue(const std::string& key) const;

	std::string getActionDebugText() const;

	TurnAction* getNextPointer() const;

protected:
	
	TurnActionSequence<TurnAction>* _parent;

	const TurnActionEffect _actionID;

	TurnAction* _next;

	std::string _actionDebugText;
};

