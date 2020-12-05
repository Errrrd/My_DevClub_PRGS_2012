/**************************************************************
 * A simpler and shorter implementation of ls(1)
 * ls(1) is very similar to the DIR command on DOS and Windows.
 **************************************************************/
#include <stdio.h>
#include <dirent.h>
 
int listdir(const char *path) {
  struct dirent *entry;
  DIR *dp;
 
  dp = opendir(path);
  if (dp == NULL) {
    perror("opendir: Path does not exist or could not be read.");
    return -1;
  }
 
  while((entry = readdir(dp)))
    puts(entry->d_name);
 
  closedir(dp);
  return 0;
}
 
int main(int argc, char **argv) {
 
  if (argc == 1)
        listdir("c:/");
 
for(int item = 0; item<argc; item++)
{
    printf("\nListing %s...\n", argv[item]);
    listdir(argv[item]);
}
 
  return 0;
}