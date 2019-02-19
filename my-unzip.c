//Louisa Nyhus and Steven Omondi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void unzipFile(char* f) {
  FILE* file = fopen(f, "r");
  if (file == NULL) {
    printf("my-unzip: cannot open file\n");
    exit(1);
  }
  //char *currentLine = NULL;
  //size_t len = 0;
  //while (getline(&currentLine, &len, file) != -1) {
    //int currNum = 0
    //int currPos = 0;
    //char currChar = currentLine[currPos]; //this is wasteful!!!!!!!!!
    //while (currPos < strlen(currentLine)) {
    /* while (currentLine[currPos] == currChar) {
	currPos++;
      }
      printf("%d", currPos);*/
  uint32_t currNum;
  char currChar;
  while (fread(&currNum, sizeof(currNum), (size_t) 1, file) != 0) {
    
	  //fread(&currNum, sizeof(currNum), (size_t) 1, file); //is 4 right?????????
    fread(&currChar, sizeof(char), (size_t) 1, file);
    //for (int i=currNum; i>0; i--) {
      
    // }
    printf("%hu", currNum); //is it really a short int???????
    printf("%c", currChar);
    //printf("%PRIuint32", currNum);
      /*char toPrint[100]; //ask bill!!!!!!!!!!!!!!!!!!!!!!!!!!
      char intToChar = currPos + '0';
      strcat(toPrint, &intToChar); //more efficient way???????????
      strcat(toPrint, &currChar);
      fwrite(&toPrint, (size_t) 5, (size_t) 1, stdout);*/
  }
  //}
  //free(currentLine);
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
      unzipFile(argv[fileCounter]);
      fileCounter++;
    }
    //}
    exit(0);
}
