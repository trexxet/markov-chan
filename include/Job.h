#pragma once

#include <string>

struct Job {
	enum class Type {
		Nothing = 0, Learn, Run
	};
	Type type;
	std::string target;
};
