#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void usage() {
	printf("Example usage:\n");
	printf("\t./my-stat somefile\n");
}

int do_stat(char *path) {
	// This allocates a statbuf structure on the stack,
	// ensuring that I don't need to reclaim its memory
	// before returning from do_stat
	struct stat statbuf;
	int ret;

	// `man 2 stat`
	ret = stat(path, &statbuf);
	
	// Always check return codes. See man 2 stat
	// for possible errors and the associated
	// errno
	if (ret < 0) {
		// `man 3 perror`
		perror("stat error:");
		return errno;
	}

	// there are many more fields one could print, but
	// this gives you the idea...
	printf("%s\n", path);
	printf("\tino:    %llu\n", statbuf.st_ino);
	printf("\tmode:   %hu\n", statbuf.st_mode);
	printf("\tnlink:  %hu\n", statbuf.st_nlink);
	printf("\tsize:   %llu\n", statbuf.st_size);
	printf("\tblocks: %llu\n", statbuf.st_blocks);
	
	return ret;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		// This is simple, but there may be better ways
		// to parse command line input and communicate
		// errors. You may wan to look into the `getopt`
		// framework.
		usage();
		exit(1);
	}

	return do_stat(argv[1]);
}
