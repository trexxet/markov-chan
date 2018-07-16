#pragma once

#include <map>
#include <string>
#include "State.h"

struct Chain {
	std::map<std::wstring, State> data;

	void writeToFile (std::wofstream &file);
	void loadFromFile (std::wifstream &file);

	void calcWeights ();
};