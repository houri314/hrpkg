#include "utils.h"
#include "types.h"
#include "defines.h"

#include <stdio.h>
#include <stdbool.h>

const char args[ARGNO+1] = "IBFVCLv";

static uint8_t verbose;
void setVerbose() {
  verbose = true;
}
uint8_t getVerbose() {
  return verbose;
}

uint8_t processFlags(uint8_t opt) {
  for (uint8_t i=0; i<ARGNO; i++) {
    if (opt == args[i]) {
      if (args[i] == 'v')
        return FLAG_VERSION;
      return 1<<i;
    }
  }
  return 0b10000000;  // Flip 8th bit if invalid arg.
}

uint8_t* getInstrStr(uint8_t flags) {
  if (flags & FLAG_INSTALL)
    return "install";
  else if (flags & FLAG_BUILD)
    return "build";
  else if (flags & FLAG_FETCH)
    return "fetch";
}

void printErr(uint8_t code) {
  if (!code) // return if no error
    return ;
  printf("hrPkg: ");
  if (!verbose) { // simple error msg if verbose disabled
    printf("package skipped\n");
    return ;
  }
  switch (code) {
    case NOTFOUND:
      printf("no such files or directories\n"); break;
    case NOTAFOLDER:
      printf("package is not a folder. Skipped\n"); break;
    case NOBUILD:
      printf("no build instruction (hrpkgBuild) found. Skipped\n"); break;
    case NOINSTL:
      printf("no install instruction (hrpkgInstall) found. Skipped\n"); break;
    default: printf("unwritten bug with code %d\n", code); break;
  }
}
