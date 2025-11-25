#ifndef METHODS_H
#define METHODS_H

#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

extern std::string user;

void disableEcho();
void restoreEcho();

#endif