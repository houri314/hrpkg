/*
 * I know damn well this file may never be compatible with Windows
 * (although I haven't tested yet). Window users please provide an
 * alternative file.
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

#include "types.h"
#include "defines.h"
#include "utils.h"

uint8_t handlePkg(const char* pkg, uint8_t f) {
  struct stat s;
  if (getVerbose())
    printf("hrPkg: %sing package %s\n", getInstrStr(f), pkg);
  if (stat(pkg, &s) != 0)
    return NOTFOUND;

  if (!(s.st_mode & S_IFDIR))
    return NOTAFOLDER;
  return 0;
}
