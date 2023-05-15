#pragma once

#include "TurnActionSequence.h"
#include "TurnDecisionAction.h"


static class TurnActionFactory
{
public:
	
	static TurnActionSequence<TurnAction>* playCardAsAction(const int playerID, const int cardID, const int faceValueID, const int colourID);

	
	static TurnActionSequence<TurnAction>* drawCardAsAction(const int playerID);

private:

	static TurnAction* playPlus2Action(TurnActionSequence<TurnAction>* nextSequence);

	
	static TurnAction* playPlus4Action(TurnActionSequence<TurnAction>* nextSequence);


	static TurnAction* playWildAction(TurnActionSequence<TurnAction>* nextSequence);


	static TurnAction* playSkipAction(TurnActionSequence<TurnAction>* nextSequence);


	static TurnAction* playReverseAction(TurnActionSequence<TurnAction>* nextSequence);


	static TurnAction* playSwapAction(TurnActionSequence<TurnAction>* nextSequence);

	
	static TurnAction* playPassAllAction(TurnActionSequence<TurnAction>* nextSequence);

	static TurnAction* cardIDToTurnAction(const int faceValueID, TurnActionSequence<TurnAction>* nextSequence);
};

