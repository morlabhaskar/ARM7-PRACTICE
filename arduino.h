#ifndef __ARDUINO_H__
#define __ARDUINO_H__
#include "types.h"

void pinMode(u32 pinNo,u32 pinDir);
void digitalWrite(u32 pinNo,u32 bit);
void digitalRead(u32 pinNo);

#endif
