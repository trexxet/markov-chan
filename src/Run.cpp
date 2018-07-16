#include "Run.h"
#include <fstream>
#include <random>
#include "Chain.h"


RUN_ERR run (std::string filename) {
	Chain chain;

	/* Load chain from file */
	std::wifstream fileIn;
	fileIn.open (filename);
	if (!fileIn.is_open ())
		return RUN_ERR::CANT_OPEN_INPUT_FILE;
	fileIn.imbue (std::locale (""));
	chain.loadFromFile (fileIn);
	fileIn.close ();

	wprintf (L"Chain loaded. Calculating weights...\n");

	/* Calculate weights */
	chain.calcWeights ();
	wprintf (L"Weights calculated. Markov-chan starts!\n");

	/* Init randomizer */
	std::random_device rd;
	std::mt19937 gen (rd ());
	std::uniform_real_distribution<> weight (0.0, 1.0);
	std::uniform_int_distribution<> start (0, (int) chain.data.size () - 1);
	std::uniform_int_distribution<> wordCount (8, 16);

	/* Generate text */
	while (getchar () == '\n') {
		/* Start with random word */
		auto iter = chain.data.begin ();
		std::advance (iter, start (gen));
		std::wstring word = iter->first;
		/* Continue chain generation */
		for (int i = 0; (i < wordCount (gen)) && !word.empty (); i++) {
			wprintf (L"%ls ", word.c_str ());
			word = chain.data.find (word)->second.getNext ((float) weight (gen));
		}
	}

	return RUN_ERR::OK;
}
