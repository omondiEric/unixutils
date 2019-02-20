//Louisa Nyhus and Steven Omondi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* my-unzip.c -- decodes a file by printing to stdout each character the
 * number of times specified, as given by the file zipped by my-zip.c.
 */

//unzip the file
void unzipFile(char* f) {
  FILE* file = fopen(f, "r");
  if (file == NULL) { //don't work with bad files
    printf("my-unzip: cannot open file\n");
    exit(1);
  }
  //print characters
  uint32_t currNum;
  char currChar;
  //for every number-character pair
  while (fread(&currNum, sizeof(currNum), (size_t) 1, file) != 0) {
    fread(&currChar, sizeof(char), (size_t) 1, file);

    //print character as many times as needed
    for (int i=currNum; i>0; i--) {
      printf("%c", currChar);
    }
  }
  fclose(file);
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("my-unzip: file1 [file2 ...]\n");
    exit(1);
  }
  int fileCounter = 1; //don't read in argv[0]
    while (fileCounter < argc) {
      unzipFile(argv[fileCounter]);
      fileCounter++;
    }
    exit(0);
}





//PRIuint32??????????????
