#include "State.h"
#include <cwchar>

extern bool verbose;


const std::map<std::wstring, State::edge_out> &State::getNextStates () {
	return nextStates;
}


void State::addNextState (const std::wstring &key, size_t count) {
	auto nextState = nextStates.find (key);
	if (nextState != nextStates.end ()) {
		nextState->second.count += count;
		if (verbose)
			wprintf (L"Chain '%ls' -> '%ls' exists, new count = %zu\n",
			         this->key.c_str (), key.c_str (), nextState->second.count);
	} else {
		nextStates.emplace (key, edge_out ());
		if (verbose)
			wprintf (L"Created chain '%ls' -> '%ls', count = %zu\n", this->key.c_str (), key.c_str (), count);
	}
}


void State::calcWeights () {
	size_t count_sum = 0;
	for (auto &nextState : nextStates)
		count_sum += nextState.second.count;
	for (auto &nextState : nextStates)
		nextState.second.weight = (float) nextState.second.count / (float) count_sum;
}


const std::wstring State::getNext (float value) {
	for (auto &next : nextStates) {
		value -= next.second.weight;
		if (value <= 0)
			return next.first;
	}
	return std::wstring (L"");
}
