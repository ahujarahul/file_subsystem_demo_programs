#include "headers.h"

int
main (void)
{
  DIR *dir;
  struct dirent *entry;
  int fd;
  struct stat fileStat;

  char dirName[100];
  char fileName[100];
  int maxSizeFile;
  //char maxSizeFileName[100];

  printf("Enter Directory name to open : \n");
  scanf("%s", dirName);

  if ((dir = opendir(dirName)) == NULL)
    perror("opendir() error\n");
  else {
    printf("contents of %s directory :\n", dirName);
    printf("---------------------------------------------------------------------------\n");
    while ((entry = readdir(dir)) != NULL){
      //008 - names of all files in the given directory
      printf("FILE NAME : %s\n", entry->d_name);

      //009 - check type of file in the directory
      sprintf(fileName, "%s/%s", dirName, entry->d_name);
      stat(fileName, &fileStat);
      printf("File Size: \t\t%lld bytes\n",fileStat.st_size);
      printf("The file %s a symbolic link\n\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
      printf("The file %s a file\n\n", (S_ISREG(fileStat.st_mode)) ? "is" : "is not");
      printf("The file %s a directory\n\n", (S_ISDIR(fileStat.st_mode)) ? "is" : "is not");
      printf("The file %s a character device\n\n", (S_ISCHR(fileStat.st_mode)) ? "is" : "is not");
      printf("The file %s a block device\n\n", (S_ISBLK(fileStat.st_mode)) ? "is" : "is not");
      //printf("The file %s a pipe\n\n", (S_ISIFO(fileStat.st_mode)) ? "is" : "is not");
      printf("The file %s a socket\n\n", (S_ISSOCK(fileStat.st_mode)) ? "is" : "is not");
      printf("---------------------------------------------------------------------------\n");

      //010 - get file with max file size
      if (maxSizeFile < fileStat.st_size) {
        maxSizeFile = fileStat.st_size;
        //maxSizeFileName = entry->d_name;
      }
    }

    printf("\nfile with max size is  and file size is %d\n", maxSizeFile);
    closedir(dir);
  }

  return 0;
}
