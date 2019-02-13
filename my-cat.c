#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("usage: ./my-cat <filename>");
  }
  FILE* file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("cannot open file\n");
    exit(1);
  }
  char currentLine[2000];
  while (fgets(currentLine, 2000, file) != NULL) { //!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    printf("%s", currentLine);
  }
  fclose(file);
}

//ask bill about how to set buffer size!
