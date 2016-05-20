#pragma once
#include <unordered_map>
#include <initializer_list>

template<typename S, typename I>
class Transition;

template<typename S, typename I>
class FiniteStateMachine
{
protected:
	using TransitionVec		 = std::vector<Transition<S, I>>;
	using TransitionInitList = std::initializer_list<Transition<S, I>>;
public:
	FiniteStateMachine();
	FiniteStateMachine(TransitionInitList);
	virtual ~FiniteStateMachine();
	virtual bool operator() (const I&) final;
	virtual S getCurrentState() const final;
protected:
	virtual void addTransition(const Transition<S, I>&) final;
	virtual void onTransition(const S&, const S&);
private:
	S current;
	std::unordered_map<S, TransitionVec> transitions;
};

template<typename S, typename I>
class Transition
{
public:
	Transition(const S&, const I&, const S&);
	S getCurrentState() const;
	S getNextState() const;
	I getInput() const;
private:
	S oldState;
	S newState;
	I input;
};


#include "FiniteStateMachineImpl.hpp"
