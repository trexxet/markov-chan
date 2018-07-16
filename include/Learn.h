#pragma once

#include <string>

enum class LEARN_ERR : int {
	OK = 0,
	CANT_OPEN_INPUT_FILE,
	CANT_OPEN_OUTPUT_FILE
};

LEARN_ERR learn (std::string filename);
