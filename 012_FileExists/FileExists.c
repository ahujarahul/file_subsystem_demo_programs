#include "headers.h"

//https://linux.die.net/man/2/access

int main(){
  char dirName[100], fileName[100], fileInDir[100];
  char buffRead[1024];
  DIR *dir;
  struct dirent *entry;
  int result = 1;

  printf("Enter Directory name to open : \n");
  scanf("%s", dirName);

  printf("Enter file name to check : \n");
  scanf("%s", fileName);
  strcat(fileName,".txt");

  if ((dir = opendir(dirName)) == NULL)
    perror("opendir() error\n");
  else {
    while ((entry = readdir(dir)) != NULL){
      sprintf(fileInDir, "%s", entry->d_name);

      //strcmp(fileInDir, fileName) -> returns 0 if matches
      if (strcmp(fileInDir, fileName)) {
      }else{
        result = 0;
      }
    }

    if (result == 0) {
      printf("%s already exists.\n", fileName);
    }else{
      printf("%s does not exists.\n", fileName);
    }
    closedir(dir);
  }






  /*if (access(fileName, F_OK) != -1) {
    //file to copy in already exists
    printf("%s already exists.\n", fileCopy);
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
  }*/

  return 0;
}
