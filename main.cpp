#include <cstdio>
#include <unistd.h>
#include <string>
#include <stdexcept>

struct Job {
	enum class Type {
		Learn, Run
	};
	Type type;
	std::string target;
};

#define ARG_KEYS "l:r:"
Job parseArgs (int argc, char *argv[]);


int main (int argc, char *argv[]) {
	printf ("Hi, Markov-chan is here!\n");
	Job job = parseArgs (argc, argv);
	return 0;
}


Job parseArgs (int argc, char *argv[]) {
	opterr = 0;
	while (int opt = getopt (argc, argv, ARG_KEYS) != -1)
		switch (opt) {
			case 'l':
				printf ("Markov-chan is going to learn from %s!\n", optarg);
				return {.type = Job::Type::Learn, .target = std::string (optarg)};
			case 'r':
				printf ("Markov-chan is going to run %s!\n", optarg);
				return {.type = Job::Type::Run, .target = std::string (optarg)};
			case '?':
			default:
				throw std::runtime_error ("Markov-chan doesn't know this key...");
		}
	fprintf (stderr, "Markov-chan has nothing to do and suicides, bye!\n");
	exit (EXIT_SUCCESS);
}
