#include "headers.h"

//https://linux.die.net/man/2/access

int main(){
  char fileName[100];
  int mode;
  int result;

  printf("Enter File name to open : \n");
  scanf("%s", fileName);
  //strcat(fileName,".txt");

  printf("Enter mode in which you want to open file : \n");
  printf(" MODES : \n 1. read\n 2. write\n 3. read write\n 4. Create\n 5. Append\n\n");
  scanf("%d", &mode);

  switch (mode) {
    case 1:
      result = access(fileName, O_RDONLY);
      if(result == -1){
      	printf("Unable to access the file in read mode\n");
      }else{
      	printf("File accessed with result %d in read mode \n", result);
      }
    break;
    case 2:
      result = access(fileName, O_WRONLY);
      if(result == -1){
        printf("Unable to access the file in write mode\n");
      }else{
        printf("File accessed with result %d in write mode \n", result);
      }
    break;
    case 3:
      result = access(fileName, O_RDWR);
      if(result == -1){
      	printf("Unable to access the file in read write mode\n");
      }else{
      	printf("File accessed with result %d in read write mode \n", result);
      }
    break;
    case 4:
      result = access(fileName, O_CREAT);
      //if file does not exist, this funtion will not create the file. returns -1
      if(result == -1){
        printf("Unable to create file\n");
      }else{
        printf("File accessed with result %d in create mode \n", result);
      }
    break;
    case 5:
      result = access(fileName, O_APPEND);
      if(result == -1){
        printf("Unable to access the file in append mode\n");
      }else{
        printf("File accessed with result %d in append mode \n", result);
      }
    break;
    default:
      printf("Please choose and enter any number from above given modes.\n");
    break;
  }

  return 0;
}
