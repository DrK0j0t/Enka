#pragma once
#include "TurnActionSequence.h"
#include "TurnAction.h"


class TurnActionSequenceManager
{
public:

	explicit TurnActionSequenceManager(const bool& debugModeEnabled);
	virtual ~TurnActionSequenceManager();

	void update();

	void setSequence(TurnActionSequence<TurnAction>* newSequence);

	void queueSequence(TurnActionSequence<TurnAction>* newSequence);

	TurnAction* getCurrentTurnAction() const;
	
	bool hasActiveTurnAction() const;

	void toggleDebugShowTaskActionNotes();

	void toggleDebugShowTreeOnNewAction();

private:

	TurnActionSequence<TurnAction>* _currentSequence;
	

	TurnActionSequence<TurnAction>* _queuedSequence;

	const bool& _debugModeEnabled;

	bool _debugShowTaskActionNotes;

	bool _debugShowTreeOnNewAction;
};

