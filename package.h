#pragma once

#include <stdint.h>

#include "utils.h"
#include "types.h"
#include "defines.h"

uint8_t checkBuild(const char*);
void build(const char*);

uint8_t checkInstall(const char*);
uint8_t install(const char*, uint8_t);
