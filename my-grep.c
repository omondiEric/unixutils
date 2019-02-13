#include <stdio.h>
#include <stdlib.h>

void searchFile(char* f, char* w) {
  FILE* file = fopen(f, "r");
  //  char* word = w; //ok to have a char*???????
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


int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("usage: ./my-grep <word> <filename(s)>");
  }
  //while (getopt(argc, argv, "") != -1) { //empty string?????????????
  searchFile(argv[2], argv[1]);
}








//ask bill about how to set buffer size!
//argc < vs !=???
//what do we do with getopt if we aren't switching?
