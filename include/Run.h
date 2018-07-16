#pragma once

#include <string>

enum class RUN_ERR : int {
	OK = 0,
	CANT_OPEN_INPUT_FILE
};

RUN_ERR run (std::string filename);
