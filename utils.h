#pragma once
#include <stdint.h>

uint8_t handlePkg(const char*, uint8_t);
uint8_t processFlags(uint8_t);
uint8_t* getInstrStr(uint8_t);
void printErr(uint8_t);

void setVerbose();
uint8_t getVerbose();
