#include "headers.h"

//https://linux.die.net/man/2/stat
//http://codewiki.wikidot.com/c:system-calls:fstat

void printFileInfo(char fileName[100], struct stat fileStat);

int main() {

  char fileName[100];
  int mode;
  int fd;
  struct stat fileStat;

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
        fstat(fd,&fileStat);
        printFileInfo(fileName,fileStat);
      }
    break;
    case 2:
      fd = open(fileName, O_WRONLY);
      if(fd == -1){
        printf("Unable to open the file in write mode\n");
      }else{
        printf("File is successfully opened with file descriptor %d in write mode \n",fd);
        fstat(fd,&fileStat);
        printFileInfo(fileName,fileStat);
      }
    break;
    case 3:
      fd = open(fileName, O_RDWR);
      if(fd == -1){
      	printf("Unable to open the file in read write mode\n");
      }else{
      	printf("File is successfully opened with file descriptor %d in read write mode \n",fd);
        fstat(fd,&fileStat);
        printFileInfo(fileName,fileStat);
      }
    break;
    case 4:
      fd = open(fileName, O_CREAT);
      if(fd == -1){
        printf("Unable to create file\n");
      }else{
        printf("File is successfully opened with file descriptor %d in create mode \n",fd);
        fstat(fd,&fileStat);
        printFileInfo(fileName,fileStat);
      }
    break;
    case 5:
      fd = open(fileName, O_APPEND);
      if(fd == -1){
        printf("Unable to open the file in append mode\n");
      }else{
        printf("File is successfully opened with file descriptor %d in append mode \n",fd);
        fstat(fd,&fileStat);
        printFileInfo(fileName,fileStat);
      }
    break;
    default:
      printf("Please choose and enter any number from above given modes.\n");
    break;
  }

  close(fd);

  return 0;
}

void printFileInfo(char fileName[100], struct stat fileStat){
  printf("\nInformation for %s\n",fileName);
    printf("---------------------------\n");
    printf("File Size: \t\t%lld bytes\n",fileStat.st_size);
    printf("Number of Links: \t%d\n",fileStat.st_nlink);
    printf("File inode: \t\t%llu\n",fileStat.st_ino);

    printf("File Permissions: \t");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");

    printf("The file %s a symbolic link\n\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
}
