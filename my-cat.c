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
  char currentLine[800];
  //while (fgets(currentLine, 2000, file) != NULL) { //!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  while (scanf("%800s", currentLine)) { 
    printf("%s", currentLine);
  }
  fclose(file);
}

//ask bill about how to set buffer size!


//there should be a version of fgets that specifically sets the buffer size...same idea as what we have now but you can't have an overflow. the version of fgets or whatever will go until \n OR the specified size

  //he also said that 800 is a good limit to use
