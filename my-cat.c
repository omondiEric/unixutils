//Louisa Nyhus and Steven Omondi

#include <stdio.h>
#include <stdlib.h>

/* my-cat.c -- copies to stdout the contents of whatever files are passed
 * to it.  If an invalid file is found, program will terminate.
 */ 
int main(int argc, char* argv[]) {
  if (argc < 2) {
     exit(0);
  }
  int fileCount = 1;
  
  //as long as there are more files left to open
  while (fileCount < argc) {
    FILE* file = fopen(argv[fileCount],"r");
    if (file == NULL) { //make sure the file really exists
      printf("my-cat: cannot open file\n");
      exit(1);
    }

    //print to stdout using currentLine as a buffer of variable size
    char *currentLine = NULL;
    size_t len = 0;
    while (getline(&currentLine, &len, file) != -1) {
      printf("%s", currentLine);
    }
    free(currentLine);
    fclose(file);
    fileCount++; //move to the next file
  }
  exit(0);
}
