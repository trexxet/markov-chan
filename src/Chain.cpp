#include "Chain.h"
#include <fstream>

const static std::wstring childPrefix (L"->");


void Chain::writeToFile (std::wofstream &file) {
	for (auto &chainItem : data) {
		file << chainItem.first << std::endl;
		auto nextStates = chainItem.second.getNextStates ();
		for (auto &nextState : nextStates) {
			file << childPrefix << '\t' << nextState.first << " " << nextState.second.count << std::endl;
		}
	}
}


void Chain::loadFromFile (std::wifstream &file) {
	std::wstring word;
	bool readingChild = false;
	State *currWord = nullptr;
	size_t count = 0;

	while (file >> word)
		if (word == childPrefix)
			readingChild = true;
		else {
			if (readingChild) {
				readingChild = false;
				file >> count;
				currWord->addNextState (word, count);
			} else {
				auto[newWord, success] = data.try_emplace (word, State (word));
				currWord = &(newWord->second);
			}
		}

}


void Chain::calcWeights () {
	for (auto &chainItem : data)
		chainItem.second.calcWeights ();
}
