#pragma once

#include <string>

struct Job {
	enum class Type {
		Learn, Run
	};
	Type type;
	std::string target;
};
