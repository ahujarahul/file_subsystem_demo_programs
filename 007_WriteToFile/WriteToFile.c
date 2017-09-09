#include "headers.h"

int main() {

  char fileName[100];
  int fd, bytesWritten;

  printf("Enter File name to open : \n");
  scanf("%s", fileName);
  strcat(fileName,".txt");

  fd = open(fileName, O_WRONLY);
  if(fd == -1){
    printf("Unable to open the file in write mode\n");
  }else{
    printf("File is successfully opened with file descriptor %d in write mode \n",fd);

    char buffer[] = "contents to be written into file\n";
  	char bufferSizeToWrite[sizeof(buffer)];
    bytesWritten = write(fd, buffer, sizeof(bufferSizeToWrite));

    if (bytesWritten == -1) {
      printf("Unable to write into the file.\n");
    }else{
      printf("Contents written into file.\n");
    }
  }

  close(fd);
  return 0;
}
