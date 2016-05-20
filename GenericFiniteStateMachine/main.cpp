#include "FiniteStateMachine.h"
#include <cassert>
#include <iostream>

enum class State
{
	LOCKED,
	UNLOCKED
};

enum class Input
{
	PUSH,
	COIN
};

std::ostream& operator<< (std::ostream&, const State&);

int main()
{
	FiniteStateMachine<State, Input> fsm({ 
		{ State::LOCKED, Input::COIN, State::UNLOCKED }, 
		{ State::UNLOCKED, Input::PUSH, State::LOCKED }
	});
	char c;

	do {
		std::cout << "current state: " << fsm.getCurrentState() << std::endl << std::endl;
		std::cout << "(c)oin (p)ass e(x)it: ";
		std::cin >> c;

		bool result = false;
		if (c == 'c')
			result = fsm(Input::COIN);
		else if (c == 'p')
			result = fsm(Input::PUSH);
		if (result)
			std::cout << std::endl << "-> Thx" << std::endl;
		else
			std::cout << std::endl << "-> Peeeeeep" << std::endl;
	} while (c != 'x');

	return EXIT_SUCCESS;
}

std::ostream& operator<<(std::ostream& os, const State& state)
{
	switch (state)
	{
	case State::LOCKED:
		os << "Locked";
		break;
	case State::UNLOCKED:
		os << "Unlocked";
		break;
	default:
		//Unknown state was given, please add it here
		assert(false);
	}
	return os;
}

