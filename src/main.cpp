#include <cwchar>
#include <unistd.h>

#include "Job.h"
#include "Learn.h"
#include "Run.h"

#define ARG_KEYS "l:r:vh"
Job parseArgs (int argc, char *argv[]);


bool verbose = false;
extern const std::string chainFileExtension (".mchan");


int main (int argc, char *argv[]) {
	setlocale (LC_CTYPE, "");
	wprintf (L"Hi, Markov-chan is here!\n");

	Job job = parseArgs (argc, argv);
	if (job.type == Job::Type::Learn)
		if (learn (job.target) != LEARN_ERR::OK) {
			fprintf (stderr, "Some shit happened with Markov-chan while learning!\n");
			return EXIT_FAILURE;
		}
	if (job.type == Job::Type::Run)
		if (run (job.target) != RUN_ERR::OK) {
			fprintf (stderr, "Some shit happened with Markov-chan while running!\n");
			return EXIT_FAILURE;
		}
	if (job.type == Job::Type::Nothing)
		wprintf (L"Markov-chan has nothing to do and commits suicide.\n");
	return 0;
}


Job parseArgs (int argc, char *argv[]) {
	int opt = 0;
	opterr = 0;
	Job job{};
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
			case 'h':
			case '?':
			default:
				wprintf (L"How to use Markov-chan: Full manual\n");
				wprintf (L"\t-l some_text_file : Teach Markov-chan new words! (generate chain from file)\n");
				wprintf (
						L"\t-r some_chain_file : Launch Markov-chan with chain file! (load chain from file and run)\n");
				wprintf (L"\t\tWhile running, press Enter to generate a new line or Ctrl-C to kill Markov-chan\n");
				wprintf (L"\t-v : Makes Markov-chan tell you everything! (verbose)\n");
				wprintf (L"\t-h : Print this manual\n");
		}
	return job;
}
