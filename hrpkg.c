#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

#include <unistd.h>

#include "types.h"
#include "defines.h"
#include "utils.h"

#include "build.h"

// Bruh I initially put uint8_t* here but then it segfaults
// if I doesn't give an argument, which defeats the whole point.
// Using [] instead somehow solves the issue and I don't know why.
extern uint8_t args[];

int main(int argc, char** argv) {
  Servant serv = {0};
  serv.pkg = malloc(argc*sizeof(char**));

  // Processing arguments
  uint8_t count = 0;
  for (uint8_t i=1; i<argc; i++) {
    if (argv[i][0] == '-') {
      // Flipping bits to the args
      for (int k=1; k<strlen(argv[i]); k++) {
        serv.flags = serv.flags | processFlags(argv[i][k]);
        if (serv.flags & 0b10000000) // Exit if detecting invalid argument
          return printf("hrPkg: invalid argument -%c\n", argv[i][k]);
      }
    }
    // Getting package names
    else {
      serv.pkg[count] = argv[i];
      count++;
    }
  }

  printf("%d\n", serv.flags);

  if (!serv.flags)
    exit_lmao:
    return printf("hrPkg: usage: hrpkg -[%s] [packages]\n", args);

  if (serv.flags & FLAG_VERSION) {
      printf("hrPkg version %s\n", VERSION);
      printf("Compiled for %s\n", ARCH);
      return 0;
  }

  // Logical check
  if (serv.flags & FLAG_INSTALL && serv.flags & FLAG_BUILD) {
    printf("hrPKg: -I and -B cannot go together\n");
    return 1;
  }
  if (!(serv.flags & FLAG_INSTALL)&& serv.flags & FLAG_LOCAL) {
    printf("hrPKg: -L (local installation) requires -I\n");
    return 1;
  }
  if (!(serv.flags & FLAG_INSTALL || serv.flags & FLAG_BUILD || serv.flags & FLAG_FETCH)) {
    printf("hrPKg: Nothing to do\n");
    return 1;
  }
  if (serv.flags & FLAG_VERBOSE)
    setVerbose();

  // UX works. Don't ask.
  printf("hrPkg called to %s package%s", 
      getInstrStr(serv.flags),
      (count>1)?"s\n":"\n");
  if (!serv.pkg[0])
    return printf("hrPkg: No packages provided\n");
  printf("Package%sgiven:",
      (count>1)?"s ":" ");
  for (int i=0; serv.pkg[i] != NULL; i++) {
    printf(" %s", serv.pkg[i]);
    if (serv.pkg[i+1] != NULL) // Put a comma if the next package is given.
      putchar(',');
  }
  putchar('\n');

#ifndef FETCH_IMPLEMENTED
  if (serv.flags & FLAG_FETCH)
    return printf("hrPkg: -F not implemented\n");
#endif

  for (int i=0; serv.pkg[i] != NULL; i++) {
    // bro at this point why don't just pass &serv
    uint8_t ret = handlePkg(serv.pkg[i], serv.flags);
    printErr(ret);
    if (ret) continue; // Skip if package is not OK.
    ret = checkBuild(serv.pkg[i]);
    printErr(ret);
    if (ret) continue; // Skip if package is not OK.
    if (serv.flags & FLAG_BUILD)
      build(serv.pkg[i]);
  }

  return 0;
}
