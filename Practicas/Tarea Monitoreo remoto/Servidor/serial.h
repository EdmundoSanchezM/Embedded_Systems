#ifndef SERIAL_H
#define SERIAL_H

#include <termios.h>

int config_serial ( char *dispositivo, speed_t baudios );
void guardaDatos( unsigned char datos[] );

#endif
