#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "package.h"
#include "utils.h"
#include "path.h"

uint8_t checkBuild(const char* pkg) {
  struct stat build;
  if (stat("hrpkgBuild", &build) != 0) {
    chdir(getWorkingDir());
    return NOBUILD;
  }
  return 0;
}

void build(const char* pkg) {
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
      fflush(stdin);
      scanf("%c", &ch);
      if (ch == 'n') {
        printf("Skipped.\n");
        return ;
      }
    }
  }
  chmod("./hrpkgBuild", S_IRUSR | S_IXUSR | S_IWUSR);
  system("./hrpkgBuild");
}
