//Louisa Nyhus and Steven Omondi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

/* my-zip.c -- encodes a file by saving each character once (in ASCII),
 * preceded by the number of sequential occurrences of that character.
 */

//zips the file
void zipFile(char* f) {
  FILE* file = fopen(f, "r");
  if (file == NULL) { //don't work with bad files
    printf("my-zip: cannot open file\n");
    exit(1);
  }

  //for every line
  char *currentLine = NULL;
  size_t len = 0;
  while (getline(&currentLine, &len, file) != -1) {
    //for every character in the line
    uint32_t linePos = 0;
    uint32_t currPos = 0;
    char currChar;
    while (linePos < strlen(currentLine)) {
      //for every sequence of characters
      currPos = 0;
      currChar = currentLine[linePos];
      while (currentLine[linePos+currPos] == currChar && (currPos < UINT_MAX)) {
	currPos++;
      }
      linePos += currPos;
      fwrite(&currPos, sizeof(currPos), (size_t) 1, stdout);
      fwrite(&currChar, sizeof(currChar), (size_t) 1, stdout);
    }
  }
  free(currentLine);
  fclose(file);
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("my-zip: file1 [file2 ...]\n");
    exit(1);
  }
  int fileCounter = 1; //don't read in argv[0]
  while (fileCounter < argc) {
    zipFile(argv[fileCounter]);
    fileCounter++;
  }
  exit(0);
}
