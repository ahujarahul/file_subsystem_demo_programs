#include "headers.h"

int main() {

  char fileName[100];
  int fd;

  printf("Enter file name to open file in read mode : \n");
  scanf("%s", fileName);
  //fgets(fileName, 100, stdin);
  printf("Entered file name : %s\n", fileName);
  strcat(fileName,".txt");

  fd = open(fileName, O_RDONLY);
  if(fd == -1){
  	printf("Unable to open the file\n");
  }else{
  	printf("File is successfully opened with file descriptor %d in read mode \n",fd);
  }

  return 0;
}
