#include "headers.h"

int main() {

  char fileName[100], buffer[1024];
  int mode, bytesRead;
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
        bytesRead = read(fd, buffer, sizeof(buffer));
        if(bytesRead == 0)
      	{
      		printf("Unable to read contents\n");
      	}else{
          printf("Read contents are : \n %s\n",buffer);
        }
        close(bytesRead);
      }
    break;
    default:
      printf("Please Select option 1 to read from the file.\n");
    break;
  }

  close(fd);
  return 0;
}
