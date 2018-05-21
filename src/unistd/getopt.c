/*
 * This is a version of the public domain getopt implementation by
 * Henry Spencer originally posted to net.sources.
 *
 * This file is in the public domain.
 *
 *
 *
 * Heavily modified by CM Graff for hlibc
 */

#include <string.h>
#include <unistd.h>
char *optarg;	/* Global argument pointer. */
int optind = 0;	/* Global argv index. */
int optopt = 0;	/* a no opt -cmg */
int opterr = 1;	/* a no opt -cmg */
int getopt(int argc, char *const argv[], const char *optstring)
{
	char c;
	char *place;
	static char *scan = NULL;
	optarg = NULL;

	if (!scan || *scan == '\0') {
		if (optind == 0) {
			optind++;
		}
		if (optind >= argc || argv[optind][0] != '-'
		    || argv[optind][1] == '\0') {
			return -1;
		}
		if (argv[optind][1] == '-' && argv[optind][2] == '\0') {
			optind++;
			return -1;
		}
		scan = argv[optind] + 1;
		optind++;
	}

	c = *scan++;
	place = strchr(optstring, c);

	if (!place || c == ':') {
		return '?';
	}
	place++;
	if (*place == ':') {
		if (*scan != '\0') {
			optarg = scan;
			scan = NULL;
		}
		else if (optind < argc) {
			optarg = argv[optind];
			optind++;
		}
		else {
			write(2, "option requires argument\n", 27);
			return ':';
		}
	}
	return c;
}

