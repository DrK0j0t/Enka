#include "TurnActionSequenceManager.h"
#include <iostream>
#include "TurnDecisionAction.h"

TurnActionSequenceManager::TurnActionSequenceManager(const bool& debugModeEnabled)
	: _debugModeEnabled(debugModeEnabled)
{
	_currentSequence = nullptr;
	_queuedSequence = nullptr;
	_debugShowTaskActionNotes = false;
	_debugShowTreeOnNewAction = false;
}

TurnActionSequenceManager::~TurnActionSequenceManager()
{
	if (_currentSequence != nullptr) {
		delete _queuedSequence;
	}
	if (_queuedSequence != nullptr) {
		delete _queuedSequence;
	}
}

void TurnActionSequenceManager::update()
{
	if (hasActiveTurnAction()) {

		if (_debugModeEnabled && _debugShowTaskActionNotes) {
			TurnDecisionAction* decisionAction = dynamic_cast<TurnDecisionAction*>(getCurrentTurnAction());
			if (decisionAction != nullptr) {
				if (!decisionAction->getHasRunOnce()) {
					std::cout << getCurrentTurnAction()->getActionDebugText() << std::endl;
				}
			}
			else {
				std::cout << getCurrentTurnAction()->getActionDebugText() << std::endl;
			}
		}
		_currentSequence->iterateSequence();


		if (_queuedSequence != nullptr) {
			delete _currentSequence;
			_currentSequence = _queuedSequence;
			_queuedSequence = nullptr;
		}

		else if (getCurrentTurnAction() == nullptr) {
			delete _currentSequence;
			_currentSequence = nullptr;
		}
	}
}

void TurnActionSequenceManager::setSequence(TurnActionSequence<TurnAction>* newSequence)
{
	if (hasActiveTurnAction()) {
		queueSequence(newSequence);

		if (_debugModeEnabled && _debugShowTreeOnNewAction) {
			std::cout << "Queued action sequence:" << std::endl;
			_currentSequence->debugOutputTurnActionTree();
		}
	}
	else {
		if (_currentSequence != nullptr) {
			delete _queuedSequence;
		}
		_currentSequence = newSequence;

		if (_debugModeEnabled && _debugShowTreeOnNewAction) {
			std::cout << "Set action sequence:" << std::endl;
			_currentSequence->debugOutputTurnActionTree();
		}
	}
}

void TurnActionSequenceManager::queueSequence(TurnActionSequence<TurnAction>* newSequence)
{
	if (_queuedSequence != nullptr) {
		delete _queuedSequence;
	}
	_queuedSequence = newSequence;
}

TurnAction * TurnActionSequenceManager::getCurrentTurnAction() const
{
	if (_currentSequence == nullptr) {
		return nullptr;
	}

	return _currentSequence->getCurrentAction();
}

bool TurnActionSequenceManager::hasActiveTurnAction() const
{
	return getCurrentTurnAction() != nullptr;
}

void TurnActionSequenceManager::toggleDebugShowTaskActionNotes()
{
	_debugShowTaskActionNotes = !_debugShowTaskActionNotes;
}

void TurnActionSequenceManager::toggleDebugShowTreeOnNewAction()
{
	_debugShowTreeOnNewAction = !_debugShowTreeOnNewAction;
}
