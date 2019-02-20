//Louisa Nyhus and Steven Omondi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* my-grep.c -- searches specified files for a given search term and prints
 * any lines containing the term.  If no search term given, no files given 
 * or invalid file given, exits with error.
 */


//helper method that searches and prints one file
void searchFile(char* f, char* w) {
  FILE* file = fopen(f, "r");
  if (file == NULL) {
    printf("my-grep: cannot open file\n");
    exit(1);
  }
  //check for term and print line if needed
  char *currentLine = NULL;
  size_t len = 0;
  while (getline(&currentLine, &len, file) != -1) {
    if (strstr(currentLine, w) != NULL) {
      printf("%s", currentLine);
    }
  }
  free(currentLine);
  fclose(file);
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("my-grep: searchterm [file ...]\n");
    exit(1);
  }
  if (argc < 3) {
    char *currentLine = NULL;
    size_t len = 0;
    while (getline(&currentLine, &len, stdin) != -1) {
      if (strstr(currentLine, argv[1]) != NULL) {
	printf("%s", currentLine);
      }
    }
  }
  else {
    int fileCounter = 2;
    while (fileCounter < argc) {
      searchFile(argv[fileCounter], argv[1]);
      fileCounter++;
    }
  }
  exit(0);
}
  //in case we want to: getopt????????????
