#include "Learn.h"
#include <fstream>
#include <cwctype>
#include <cwchar>
#include <algorithm>
#include "Chain.h"
#include "State.h"

extern bool verbose;
extern std::string chainFileExtension;


LEARN_ERR learn (std::string filename) {
	Chain chain;

	/* Open file */
	std::wifstream fileIn;
	fileIn.open (filename);
	if (!fileIn.is_open ())
		return LEARN_ERR::CANT_OPEN_INPUT_FILE;
	fileIn.imbue (std::locale (""));

	/* Build chain */
	std::wstring word;
	State *prevWord = nullptr;
	while (fileIn >> word) {
		/* Remove non-alpha characters */
		word.erase (std::remove_if (word.begin (), word.end (),
		                            [] (wint_t ch) { return !iswalpha (ch); }),
		            word.end ());
		/* Convert to lowercase */
		std::transform (word.begin (), word.end (), word.begin (), towlower);

		if (!word.empty ()) {
			auto[newWord, success] = chain.data.try_emplace (word, State (word));

			if (verbose) {
				if (success)
					wprintf (L"Key '%ls' not found, created new\n", word.c_str ());
				else
					wprintf (L"Key '%ls' exists\n", word.c_str ());
			}

			if (prevWord)
				prevWord->addNextState (newWord->second.key);
			prevWord = &(newWord->second);
		}
	}
	fileIn.close ();

	wprintf (L"Chain built. Writing to %s%s\n", filename.c_str (), chainFileExtension.c_str ());

	/* Write to file */
	std::wofstream fileOut;
	fileOut.open (filename.append (chainFileExtension));
	if (!fileOut.is_open ())
		return LEARN_ERR::CANT_OPEN_OUTPUT_FILE;
	fileOut.imbue (std::locale (""));
	chain.writeToFile (fileOut);
	fileOut.close ();

	wprintf (L"Chain saved! Markov-chan has learned %lu new words!\n", chain.data.size ());

	return LEARN_ERR::OK;
}
