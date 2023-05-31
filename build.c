#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "package.h"
#include "utils.h"

static char dir[255];

uint8_t checkBuild(const char* pkg) {
  getcwd(dir, 255);
  if (getVerbose()) {
    printf("Checking package %s for building\n", pkg);
    printf("chdir() into %s\n", pkg);
  }
  struct stat build;
  chdir(pkg);
  if (stat("hrpkgBuild", &build) != 0) {
    chdir(dir);
    return NOBUILD;
  }
  chdir(dir);
  return 0;
}

void build(const char* pkg) {
  if (getVerbose()) {
    printf("Building package\n", pkg);
    printf("chdir() into %s\n", pkg);
  }
  chdir(pkg);
  if (getVerbose()) {
    uint8_t ch;
    printf("Check %s/hrpkgBuild script? (y/n)\n", pkg);
    scanf("%c", &ch);
    if (ch == 'y') {
      printf("Content of %s/hrpkgBuild:\n", pkg);
      FILE* hrpkgBuild = fopen("hrpkgBuild", "r");
      while (!feof(hrpkgBuild)) {
        char buffer[100];
        printf("%s", buffer);
        fgets(buffer, 100, hrpkgBuild);
      }
      printf("Execute? (y/n)\n");
      scanf("%c", &ch);
      if (ch == 'n') {
        printf("Skipped.\n");
        return ;
      }
    }
  }
  chmod("./hrpkgBuild", S_IRUSR | S_IXUSR | S_IWUSR);
  system("./hrpkgBuild");
  if (getVerbose())
    printf("Returning to parent directory\n");
  chdir(dir);
}
