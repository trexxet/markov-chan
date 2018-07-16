#pragma once

#include <map>
#include <string>

class State {
	struct edge_out {
		float weight = 0;
		size_t count = 1;
	};
	std::map<std::wstring, edge_out> nextStates;

public:
	std::wstring key;

	void addNextState (const std::wstring& key);
	void calcWeights ();
	const std::map<std::wstring, edge_out> &getNextStates();

	State (std::wstring& key) : key(key) {}
};
