#include <cwchar>
#include <unistd.h>
#include <stdexcept>

#include "Job.h"
#include "Learn.h"

#define ARG_KEYS "vl:r:"
Job parseArgs (int argc, char *argv[]);


bool verbose = false;
std::string chainFileExtension (".mchan");


int main (int argc, char *argv[]) {
	setlocale (LC_CTYPE, "");
	wprintf (L"Hi, Markov-chan is here!\n");

	Job job = parseArgs (argc, argv);
	if (job.type == Job::Type::Learn)
		if (learn (job.target) != LEARN_ERR::OK)
			fprintf (stderr, "Some shit happened with Markov-chan!");
	return 0;
}


Job parseArgs (int argc, char *argv[]) {
	int opt = 0;
	opterr = 0;
	Job job {};
	while ((opt = getopt (argc, argv, ARG_KEYS)) != -1)
		switch (opt) {
			case 'l':
				wprintf (L"Markov-chan is going to learn from %s!\n", optarg);
				job.type = Job::Type::Learn;
				job.target = std::string (optarg);
				break;
			case 'r':
				wprintf (L"Markov-chan is going to run %s!\n", optarg);
				job.type = Job::Type::Run;
				job.target = std::string (optarg);
				break;
			case 'v':
				verbose = true;
				break;
			case '?':
			default:
				throw std::runtime_error ("Markov-chan doesn't know this key...");
		}
	return job;
}
