#pragma once

#include "TurnAction.h"

enum PlayerUpdateResultState { PlayerDidNothing, PlayerStartedTurnAction, PlayerStartedTurnActionWithUno, PlayerJumpedIn, PlayerCalledAntiUno, PlayerCalledUno };


struct PlayerUpdateResult {
	PlayerUpdateResultState resultState;
	
	TurnActionSequence<TurnAction>* turnActionRequest;

	int playerIDForResult;

	Card* cardForJump;
};