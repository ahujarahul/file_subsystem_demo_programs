#include "headers.h"

int main(){
  char fileName[100];
  int mode;
  int fd;

  printf("Enter File name to open : \n");
  scanf("%s", fileName);
  strcat(fileName,".txt");

  printf("Enter mode in which you want to open file : \n");
  printf(" MODES : \n 1. read\n 2. write\n 3. read write\n 4. Create\n 5. Append\n\n");
  scanf("%d", &mode);

  switch (mode) {
    case 1:
      fd = open(fileName, O_RDONLY);
      if(fd == -1){
      	printf("Unable to open the file in read mode\n");
      }else{
      	printf("File is successfully opened with file descriptor %d in read mode \n",fd);
      }
    break;
    case 2:
      fd = open(fileName, O_WRONLY);
      if(fd == -1){
        printf("Unable to open the file in write mode\n");
      }else{
        printf("File is successfully opened with file descriptor %d in write mode \n",fd);
      }
    break;
    case 3:
      fd = open(fileName, O_RDWR);
      if(fd == -1){
      	printf("Unable to open the file in read write mode\n");
      }else{
      	printf("File is successfully opened with file descriptor %d in read write mode \n",fd);
      }
    break;
    case 4:
      fd = open(fileName, O_CREAT);
      if(fd == -1){
        printf("Unable to create file\n");
      }else{
        printf("File is successfully opened with file descriptor %d in create mode \n",fd);
      }
    break;
    case 5:
      fd = open(fileName, O_APPEND);
      if(fd == -1){
        printf("Unable to open the file in append mode\n");
      }else{
        printf("File is successfully opened with file descriptor %d in append mode \n",fd);
      }
    break;
    default:
      printf("Please choose and enter any number from above given modes.\n");
    break;
  }

  close(fd);

  return 0;
}
