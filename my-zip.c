//Louisa Nyhus and Steven Omondi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* my-grep.c -- searches specified files for a given search term and prints
 * any lines containing the term.  If no search term given, no files given 
 * or invalid file given, exits with error.
 */


//helper method that searches and prints one file
/*void searchFile(char* f, char* w) {
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
  }*/

void zipFile(char* f) {
  FILE* file = fopen(f, "r");
  if (file == NULL) {
    printf("my-zip: cannot open file\n");
    exit(1);
  }
  char *currentLine = NULL;
  size_t len = 0;
  while (getline(&currentLine, &len, file) != -1) {
  //getline(&currentLine, &len, file);
    uint32_t linePos = 0;
    uint32_t currPos = 0;
    char currChar = currentLine[0]; //this is wasteful!!!!!!!!!
    while (linePos < strlen(currentLine)) { //or if it's super big????????????????
      currPos = 0;
      currChar = currentLine[linePos];
      while (currentLine[linePos+currPos] == currChar) {
	currPos++;
      }
      printf("%d", currPos);
      linePos += currPos; //we need to make linepos skip one!!!!!!!!
      //printf("%d", currPos);
      fwrite(&currPos, sizeof(currPos), (size_t) 1, stdout); //better to just call 32 or sizeof?
      fwrite(&currChar, sizeof(currChar), (size_t) 1, stdout);    //is sizeof char ok????
    }
  }
  free(currentLine);
  fclose(file);
}

int main(int argc, char* argv[]) {
  /*  if (argc < 2) {
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
    }*/
  //else {
    int fileCounter = 1;
    while (fileCounter < argc) {
      zipFile(argv[fileCounter]);
      fileCounter++;
    }
    //}
  exit(0);
}


  //in case we want to: getopt????????????

//stdin and ctrl c
//empty string specified as ""????????????????

//from office hours: we need to loop through to ensure that if we have 2^32+1 characters it just prints 1!



//what do we do with getopt if we aren't switching?

//we don't care what myzip actually prints, just that we can unzip it
