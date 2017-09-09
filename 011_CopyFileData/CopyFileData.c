#include "headers.h"

//https://linux.die.net/man/2/access

int main(){
  char fileName[100], fileCopy[100];
  char buffRead[1024];
  int fd, fdw, bytesWritten, bytesRead;
  int result;

  printf("Enter file name to copy data from : \n");
  scanf("%s", fileName);
  strcat(fileName,".txt");

  printf("Enter file name to copy data into : \n");
  scanf("%s", fileCopy);
  strcat(fileCopy,".txt");

  if (access(fileCopy, F_OK) != -1) {
    //file to copy in already exists
    printf("%s already exists. Delete file to continue.\n", fileCopy);
  }else{
      fd = open(fileName, O_RDONLY);
      if (fd == -1) {
        printf("Could not open the file %s in read mode.\n", fileName);
      }else{
        bytesRead = read(fd, buffRead, sizeof(buffRead));
        fdw = open(fileCopy, O_WRONLY | O_CREAT);
        if (fdw == -1) {
          printf("Could not open the file %s in write mode.\n", fileCopy);
        }else{
          bytesWritten = write(fdw, buffRead, sizeof(buffRead));
          if (bytesWritten == bytesRead) {
            printf("Write success in %s file\n", fileCopy);
          }else{
            printf("Write FAILURE in %s file\n", fileCopy);
          }
        }
      }
  }
    close(fd);

  return 0;
}
