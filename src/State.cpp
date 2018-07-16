#include "State.h"
#include <cwchar>

extern bool verbose;


const std::map<std::wstring, State::edge_out>& State::getNextStates () {
	return nextStates;
}


void State::addNextState (const std::wstring &key) {
	auto nextState = nextStates.find (key);
	if (nextState != nextStates.end ()) {
		nextState->second.count++;
		if (verbose)
			wprintf (L"Chain '%ls' -> '%ls' exists, new counter value is %zu\n",
			         this->key.c_str (), key.c_str (), nextState->second.count);
	} else {
		nextStates.emplace (key, edge_out ());
		if (verbose)
			wprintf (L"Created chain '%ls' -> '%ls'\n", this->key.c_str (), key.c_str ());
	}
}


void State::calcWeights () {
	size_t count_sum = 0;
	for (auto &nextState : nextStates)
		count_sum += nextState.second.count;
	for (auto &nextState : nextStates)
		nextState.second.weight = (float) nextState.second.count / (float) count_sum;
}
