#pragma once
#include "FiniteStateMachine.hpp"
#include <algorithm>
#include <functional>


template <typename S, typename I>
FiniteStateMachine<S, I>::FiniteStateMachine() = default;

template <typename S, typename I>
FiniteStateMachine<S, I>::FiniteStateMachine(S startState, TransitionInitList initList) : current(startState)
{
	auto fctAddTransition = std::bind(&FiniteStateMachine<S, I>::addTransition, this, std::placeholders::_1);
	std::for_each(initList.begin(), initList.end(), fctAddTransition);
}

template <typename S, typename I>
FiniteStateMachine<S, I>::~FiniteStateMachine() = default;

template <typename S, typename I>
bool FiniteStateMachine<S, I>::operator()(const I& input)
{
	auto scopePair = transitions.find(current);
	if (scopePair == transitions.end())
		return false;
	auto transistion = std::find(scopePair->second.begin(), scopePair->second.end(), input);
	if (transistion == scopePair->second.end())
		return false;
	current = transistion->getNextState();
	onTransition(scopePair->first, current);
	return true;
}

template <typename S, typename I>
S FiniteStateMachine<S, I>::getCurrentState() const
{
	return current;
}

template <typename S, typename I>
void FiniteStateMachine<S, I>::addTransition(const Transition<S, I>& transition)
{
	auto scope = transitions.find(transition.getCurrentState());
	if (scope == transitions.end())
		scope = transitions.insert({ transition.getCurrentState(), TransitionVec() }).first;
	scope->second.push_back(transition);
}

template <typename S, typename I>
void FiniteStateMachine<S, I>::onTransition(const S&, const S&){}

template <typename S, typename I>
Transition<S, I>::Transition(const S& inOldState, const I& inInput, const S& inNewState) : 
	oldState(inOldState), input(inInput), newState(inNewState){}

template <typename S, typename I>
S Transition<S, I>::getCurrentState() const
{
	return oldState;
}

template <typename S, typename I>
S Transition<S, I>::getNextState() const
{
	return newState;
}

template <typename S, typename I>
I Transition<S, I>::getInput() const
{
	return input;
}

template <typename S, typename I>
bool operator==(const Transition<S, I>& transition, const I& input)
{
	return transition.getInput() == input;
}
