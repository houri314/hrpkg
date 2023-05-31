#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char installDir[255];
static char workingDir[255];

void setWorkingDir() {
  getcwd(workingDir, 255);
}
char* getWorkingDir() {
  return workingDir;
}

void setInstallDir() {
  // Only for *nix environments for now.
  strcpy(installDir, getenv("HOME"));
}
char* getInstallDir() {
  return installDir;
}
